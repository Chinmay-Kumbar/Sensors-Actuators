#include<stdlib.h>
#include "thermoopti22BCT0063.h"
/**
 *Simulates a temperature reading from a thermo-optical sensor.
 * The sensor calculates temperature based on the Stefan-Boltzmann Law, 
 * which relates radiated power, emissivity, and surface area to temperature.
 *yearsElapsed Number of years elapsed (used for simulating sensor drift).
  The computed temperature in Kelvin.
 */
double getThermoOpticalTemp(int yearsElapsed) {
    double emissivity = 0.9; // Assume an emissivity value for the surface (between 0 and 1).
    double area = 0.01;// Assume a fixed surface area in square meters (m²).
    double power = (rand() % 50) + 10.0; // Generate a random incident power in watts (between 10 and 59 W).
    return calculateThermoOpticalTemperature(emissivity, area, power);
}
