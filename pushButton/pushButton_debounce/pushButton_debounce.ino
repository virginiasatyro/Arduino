/***********************************************************************************
 * File: pushbutton_debounce
 * Arduino UNO
 * Arduino IDE
 * Author: Virgínia Sátyro
 * License: Free - Open Source
 * Created on Julho de 2019
 * 
 * Quado o poto vai do estado LOW para o HIGH (botao pressionado), a saida do led
 * muda de LOW para HIGH ou de HIGH para LOW. Ha um delay minimo entre as mudanças
 * do toggle para lidar com o debounce do circuito.
***********************************************************************************/

// pins 
const int buttonPin = 2;  // pushbutton pin 
const int ledPin    = 13; // LED pin

int ledState = HIGH;       // current state of the output pin
int buttonState;           // current reading of the input pin
int lastButtonState = LOW; // previous reading state of the input pin

// long number stored - mesure of time in miliseconds
long lastDebounceTime = 0;  // last time the output pin was toggled
long debounceDelay    = 50; // the debounce time; increase if the output flickers

void setup(){
  pinMode(buttonPin, INPUT);
  pinMode(ledPin, OUTPUT); 
  
  // set initial LED state
  digitalWrite(ledPin, ledState);
}

void loop(){
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button 
  // (i.e. the input went from LOW to HIGH),  and you've waited 
  // long enough since the last press to ignore any noise:  

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  } 
  
  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }
  
  // set the LED:
  digitalWrite(ledPin, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}

