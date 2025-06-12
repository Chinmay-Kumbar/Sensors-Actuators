#include<stdlib.h>
#include "thermoacoust22BCT0063.h"
/**Simulates a temperature reading from a thermoacoustic sensor.
 *Thermoacoustic sensors estimate temperature based on the interaction 
 * between acoustic waves and heat flow in a medium. This function simulates 
 * the process by considering base sensitivity, acoustic pressure, and 
 * nonlinearity effects. yearsElapsed Number of years elapsed (used for simulating sensor drift).
 *The computed temperature in degrees Celsius.
 */
double getThermoAcousticTemp(int yearsElapsed) {
    double baseSensitivity = 0.5;// Base sensitivity of the thermoacoustic sensor (empirically determined)
    // Simulate acoustic pressure variation (random value between 1.0 and 10.0)
    double acousticPressure = (rand() % 10) + 1.0;
    double nonlinearityCoeff = 0.02;// Nonlinearity coefficient representing the deviation due to system imperfections
    // Compute and return the actual temperature using the thermoacoustic model
    return calculateThermoAcousticTemperature(baseSensitivity, acousticPressure, nonlinearityCoeff);
}
