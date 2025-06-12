#include<stdlib.h>
#include "thermocouple22BCT0063.h"
/**
  Simulates a temperature reading from a thermocouple sensor.
  Thermocouples measure temperature based on the voltage generated 
  due to the Seebeck effect. This function simulates the sensor's behavior 
  by generating a random voltage and considering cold junction compensation.
  yearsElapsed Number of years elapsed (used for simulating sensor drift).
  The computed temperature in degrees Celsius.
 */
double getThermocoupleTemp(int yearsElapsed) {
    double voltage = (rand() % 1000) / 1000.0; // Simulate a thermoelectric voltage (random value between 0 and 0.999 V)
    double coldJunctionTemp = 25.0 + yearsElapsed * 0.1;//Simulate cold junction temperature compensation Initial cold junction temperature is 25°C, increasing slightly over time
    return calculateTemperature(voltage, coldJunctionTemp);//returns the actual temperature using a thermocouple equation
}
