#ifndef THERMOOPTI_22BCT0063_H
#define THERMOOPTI_22BCT0063_H

#include <math.h>

// Stefan-Boltzmann constant (W/m²K⁴)
#define STEFAN_BOLTZMANN_CONSTANT 5.670374419e-8  

/**
 *  Calculates the temperature using thermo-optical sensor parameters.
 * Formula:
 *      T = (P / (ε * σ * A)) ^ (1/4)
 *
 * emissivity Emissivity of the surface (0 to 1).
 * area Surface area of the object in square meters (m²).
 * incidentPower Incident radiant power in watts (W).
 * Temperature in Kelvin (K), or -1 if invalid input.
 */
static inline double calculateThermoOpticalTemperature(double emissivity, double area, double incidentPower) {
    if (emissivity <= 0 || area <= 0 || incidentPower <= 0) {
        return -1;
    }
    return pow((incidentPower / (emissivity * STEFAN_BOLTZMANN_CONSTANT * area)), 0.25);
}

// Function prototype
double getThermoOpticalTemp(int yearsElapsed);

#endif // THERMOOPTI_22BCT0063_H
