#ifndef THERMOACOUSTIC_22BCT0063_H
#define THERMOACOUSTIC_22BCT0063_H

#include <math.h>

/**Calculates the temperature using thermoacoustic parameters.
 * Formula:
 *      Temperature (T) = (P * S) / K
 * baseSensitivity Sensor sensitivity (V/Pa).
 * acousticPressure Acoustic pressure (Pa).
 * nonlinearityCoeff Nonlinearity coefficient (1/Pa).
 * Temperature in Kelvin (K), or -1 if invalid input.
 */
static inline double calculateThermoAcousticTemperature(double baseSensitivity, double acousticPressure, double nonlinearityCoeff) {
    if (baseSensitivity <= 0 || acousticPressure <= 0 || nonlinearityCoeff <= 0) {
        return -1;
    }
    return (acousticPressure * baseSensitivity) / nonlinearityCoeff;
}

// Function prototype
double getThermoAcousticTemp(int yearsElapsed);

#endif // THERMOACOUSTIC_22BCT0063_H
