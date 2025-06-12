#ifndef THERMOCOUPLE_22BCT0063_H
#define THERMOCOUPLE_22BCT0063_H

#include <math.h>

// Thermocouple calibration constants
#define THERMOCOUPLE_COEFFICIENT_A 0.2268
#define THERMOCOUPLE_COEFFICIENT_B 0.0012
#define THERMOCOUPLE_COEFFICIENT_C 0.000034

/**Converts thermocouple voltage to temperature using a polynomial approximation.
 * Formula:
 *      T = A * V + B * V² + C * V³ + T_cold
 *voltage Measured thermocouple voltage in millivolts (mV).
 * coldJunctionTemp Cold junction temperature (°C).
 * Calculated temperature in Celsius (°C).
 */
static inline double calculateTemperature(double voltage, double coldJunctionTemp) {
    double temp = THERMOCOUPLE_COEFFICIENT_A * voltage +
                  THERMOCOUPLE_COEFFICIENT_B * pow(voltage, 2) +
                  THERMOCOUPLE_COEFFICIENT_C * pow(voltage, 3);
    return temp + coldJunctionTemp;
}

// Function prototype
double getThermocoupleTemp(int yearsElapsed);

#endif // THERMOCOUPLE_22BCT0063_H
