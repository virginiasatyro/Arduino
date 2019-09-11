#include <SPI.h>
#include <Wire.h>
#include "HX711.h"

#define DOUT  3
#define CLK   2

//HX711 scale(DOUT, CLK);
HX711 scale;

//float calibration_factor = -11980;
float calibration_factor = -11980;

void setup() {
  Serial.begin(9600);
  scale.begin(DOUT, CLK);
  scale.set_scale();
  scale.tare(); //Reset the scale to 0

  long zero_factor = scale.read_average(); //Get a baseline reading
}

void loop() {

  //scale.set_scale(calibration_factor); //Adjust to this calibration factor

  Serial.println(scale.get_units(10), 3);
  //displayValue(scale.get_units(20)  );
  delay(500);
}
/*
void displayValue(float val)
{
  display.clearDisplay();
  display.setTextSize(1.5);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);

  display.println("POUNDS");

  display.setTextSize(3);
  display.setTextColor(WHITE);
  display.setCursor(10, 16);
  //display.clearDisplay();
  display.println(val);
  display.display();
  
}*/
