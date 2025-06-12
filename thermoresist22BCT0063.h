#ifndef THERMORESIST_22BCT0063_H
#define THERMORESIST_22BCT0063_H

#include <stdlib.h>

// PT100 RTD Sensor Constants
#define R0 100.0       // Resistance of PT100 at 0°C (Ohms)
#define ALPHA 0.00385  // Temperature coefficient of resistance (1/°C)

/**
 * Calculates the temperature from the resistance of an RTD sensor.
 *
 * Formula:
 *      Temperature (°C) = (Resistance - R0) / (R0 * ALPHA)
 * resistance Measured resistance of the RTD sensor (Ohms).
 * Calculated temperature in degrees Celsius (°C).
 */
static inline double cal_temp_RTD(double resistance) {
    return (resistance - R0) / (R0 * ALPHA);
}

// Function prototype
double getRTDTemp(int yearsElapsed);

#endif // THERMORESIST_22BCT0063_H
