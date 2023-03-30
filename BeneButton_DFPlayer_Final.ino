#include "SoftwareSerial.h"
#include "DFRobotDFPlayerMini.h"

SoftwareSerial softwareSerial(2,3);//RX, TX Pin

int MP3NUM;

int buttonState;

int lastButtonState;

int buttonPushCounter = 0;

int langswitch;


DFRobotDFPlayerMini player;

void setup() {
  Serial.begin(9600);
softwareSerial.begin(9600);

MP3NUM = 1;





pinMode(7 ,INPUT_PULLUP); //button
pinMode(5, INPUT_PULLUP); //langswitch

if(!player.begin(softwareSerial)){
Serial.println("OK");
player.volume(29);  //volume can be set to 0-30


}

}




void loop() {
langswitch = digitalRead(5);

if (langswitch == 0){
English();
}
else{
Latin();
}

 
}


void English(){
 

  delay(150);
 buttonState = digitalRead(7);

  // compare the buttonState to its previous state
  if (buttonState != 1) {
    // if the state has changed, increment the counter
    if (buttonPushCounter <= 7) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
       
      
    } else{

      buttonPushCounter = 1;
      
    }

   Serial.println(buttonPushCounter);
    // Delay a little bit to avoid bouncing
    player.play(buttonPushCounter);
   
  }
  // save the current state as the last state, for next time through the loop
//  lastButtonState = buttonState;
  }



void Latin(){
 

  delay(150);
 buttonState = digitalRead(7);

  // compare the buttonState to its previous state
  if (buttonState != 1) {
    // if the state has changed, increment the counter
    if ((9 <= buttonPushCounter)&&(buttonPushCounter <= 13)) {
      // if the current state is HIGH then the button went from off to on:
      buttonPushCounter++;
       
     
    } else{

      buttonPushCounter = 9;
      
    }

    Serial.println(buttonPushCounter);
    // Delay a little bit to avoid bouncing
    player.play(buttonPushCounter);
   
  }
  // save the current state as the last state, for next time through the loop
//  lastButtonState = buttonState;
  }
