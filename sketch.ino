#include "config.h"
#include "display.h"

void setup() {

  // initialize the button pin as a input:
  pinMode(buttonPin, INPUT_PULLUP);
  // initialize the LED as an output:
  pinMode(ledPin, OUTPUT);
  encoder.setPosition(10 / ROTARYSTEPS);
  // initialize serial communication:
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS);
  //display.display();
  delay(100);
  display.clearDisplay();
  display.display();
}



void pressTime() {
  press_mil = 1000;
  switch (whilePress) {
    case 0:
      //Serial.println(akt_mil);
      break;
    case 1:
      //press_start_mil = akt_mil;
 //     press_ziel_mil = akt_mil + press_mil;
      //Serial.println(akt_mil);
      //if (press_start_mil >= press_ziel_mil) {
        //press_start_mil = press_ziel_mil;
       // Serial.println("long");
       // display.print("long");
      //}
      //Serial.println(press_ziel_mil);
      break;

      
  }
}

void encoder_read() {
  encoder.tick();

  // get the current physical position and calc the logical position
  newPos = encoder.getPosition() * ROTARYSTEPS;

  if (newPos < ROTARYMIN) {
    encoder.setPosition(ROTARYMIN / ROTARYSTEPS);
    newPos = ROTARYMIN;

  } else if (newPos > ROTARYMAX) {
    encoder.setPosition(ROTARYMAX / ROTARYSTEPS);
    newPos = ROTARYMAX;
  }  // if

  if (lastPos != newPos) {
    Serial.print(newPos);
    Serial.print(" ");
    Serial.println(akt_mil);

    lastPos = newPos;
  }  // if
}


void loop() {
  akt_mil = millis();
  display_out();
  // read the pushbutton input pin:
  buttonState = digitalRead(buttonPin);
  encoder_read();
  pressTime();
  //panels_dev();

  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    // if the state has changed, increment the counter
    if (buttonState == LOW) {
      buttonState2 = 0;  // if the current state is HIGH then the button went from off to on:
      whilePress = true;
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
            Serial.print("startmil:");
            start_mil = akt_mil;
      Serial.println(start_mil);
    } else {
      // if the current state is LOW then the button went from on to off:
      Serial.println("off");
      Serial.println(press_ziel_mil);
      Serial.print("endmil:");
      end_mil=akt_mil;
      Serial.println(end_mil);
      press_start_mil = akt_mil;
      press_ziel_mil = akt_mil + press_mil;
      buttonState2 = 1;
      whilePress = false;
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  lastButtonState = buttonState;
  press_dauer = end_mil - start_mil;




  // turns on the LED every four button pushes by checking the modulo of the
  // button push counter. the modulo function gives you the remainder of the
  // division of two numbers:
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
