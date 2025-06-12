#include<stdlib.h>
#include "thermoresist22BCT0063.h"
/**
 * Function to simulate temperature readings from an RTD (Resistance Temperature Detector).
 * The RTD sensor's resistance changes over time due to aging and environmental factors.
 *yearsElapsed Number of years elapsed (used for simulating sensor drift).
 * The computed temperature based on RTD resistance.
 */

double getRTDTemp(int yearsElapsed) {
    // Simulate resistance variation:
    // - The baseline resistance R0 is modified by a small fluctuation.
    // - The fluctuation is calculated as a random value between -50 and +49.
    // - ALPHA is the temperature coefficient of resistance for the RTD.
    double resistance = R0 * (1 + ALPHA * ((rand() % 100) - 50));
    return cal_temp_RTD(resistance);
}
