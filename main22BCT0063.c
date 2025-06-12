// LA1-22BCT0063.c
// This program simulates temperature readings from four types of sensors:
// Thermocouple, RTD (Thermoresistive), Thermooptical, and Thermoacoustic sensors.
// It logs the data into a CSV file, filters out outliers, and determines whether
// a fan or heater should be activated based on the average temperature.

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include "thermocouple22BCT0063.h"
#include "thermoresist22BCT0063.h"
#include "thermoopti22BCT0063.h"
#include "thermoacoust22BCT0063.h"

#define NUM_READINGS 1200     // Total number of simulated readings
#define YEARS_ELAPSED 5       // Simulate 5 years of sensor drift for realistic values
#define FILENAME "sensordata.csv" // File to store sensor readings

// Function to log data into the CSV file
void logData(FILE *file, int id, const char *sensorType, double temperature, int isOutlier) {
    fprintf(file, "%d,%s,%.2f,%s\n", id, sensorType, temperature, isOutlier ? "Outlier" : "Valid");
}

// Function to check temperature thresholds and control heating/cooling
void checkThresholds(double avgTemp) {
    if (avgTemp > 35.0) {
        printf("Fan ON (Temp: %.2f°C)\n", avgTemp);
    } else if (avgTemp < 6.0) {
        printf("Heater ON (Temp: %.2f°C)\n", avgTemp);
    } else {
        printf("System Stable (Temp: %.2f°C)\n", avgTemp);
    }
}

// Function to compute the average temperature while filtering outliers
double computeFilteredAverage(double tc, double rtd, double to, double ta) {
    double readings[4] = {tc, rtd, to, ta};
    double sum = 0.0;
    int count = 0;

    // Define acceptable deviation range for filtering outliers
    double mean = (tc + rtd + to + ta) / 4.0;
    double deviationLimit = 5.0; // Adjust this threshold if needed

    for (int i = 0; i < 4; i++) {
        if (fabs(readings[i] - mean) <= deviationLimit) {
            sum += readings[i];
            count++;
        }
    }

    return (count > 0) ? (sum / count) : mean; // Return mean if all are outliers
}

int main() {
    srand(time(NULL)); // Sets for random number generation

    // Open file for writing data
    FILE *file = fopen(FILENAME, "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    // Write CSV header
    fprintf(file, "ID,SensorType,Temperature,Status\n");

    double totalTemp = 0.0; // Tracks total average temperature for final calculation

    // Generate and log temperature readings
    for (int i = 0; i < NUM_READINGS; i++) {
        // Generate simulated temperature readings
        double tcTemp = getThermocoupleTemp(YEARS_ELAPSED);
        double rtdTemp = getRTDTemp(YEARS_ELAPSED);
        double toTemp = getThermoOpticalTemp(YEARS_ELAPSED);
        double taTemp = getThermoAcousticTemp(YEARS_ELAPSED);

        // Compute average temperature after filtering outliers
        double avgTemp = computeFilteredAverage(tcTemp, rtdTemp, toTemp, taTemp);
        totalTemp += avgTemp;

        // Log data for each sensor
        logData(file, i, "Thermocouple", tcTemp, fabs(tcTemp - avgTemp) > 5.0);
        logData(file, i, "RTD", rtdTemp, fabs(rtdTemp - avgTemp) > 5.0);
        logData(file, i, "Thermo-Optical", toTemp, fabs(toTemp - avgTemp) > 5.0);
        logData(file, i, "Thermo-Acoustic", taTemp, fabs(taTemp - avgTemp) > 5.0);
    }

    fclose(file); // Close file after writing

    // Calculate and display the final average temperature
    double avgFinalTemp = totalTemp / NUM_READINGS;
    printf("Final Average Temperature: %.2f°C\n", avgFinalTemp);

    // Check and control temperature thresholds
    checkThresholds(avgFinalTemp);

    printf("Sensor data has been successfully logged into '%s'.\n", FILENAME);

    return 0;
}
