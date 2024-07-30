#include <Grove_LCD_RGB_Backlight.h>
#include <pushButton.h>
#include <playSong.h>

rgb_lcd lcd;

const int colorR = 255;
const int colorG = 255;
const int colorB = 255;
 
int ButtonG = A0;
int ButtonA = A1;
int ButtonB = A2;
 
int GprevButton = LOW;
int AprevButton = LOW;
int BprevButton = LOW;
int MprevButton = LOW;
 
int Gcounter = 0;
int Acounter= 0;
int Bcounter = 0;
 
int speakerPin1 = D2;
int speakerPin2 = D3;
int speakerPin3 = D4;
int MusicState = D7;



// setup() runs once, when the device is first turned on.
void setup() {
    lcd.begin(16, 2);
   
    lcd.setRGB(colorR, colorG, colorB);
 
      pinMode(ButtonG, INPUT_PULLDOWN);
      pinMode(ButtonA, INPUT_PULLDOWN);
      pinMode(ButtonB, INPUT_PULLDOWN);
      pinMode(MusicState, INPUT_PULLDOWN);
      Particle.variable("Gianni counter", Gcounter);
      Particle.variable("Andrew counter", Acounter);
      Particle.variable("Brock counter", Bcounter);
     
    // INPUT mode with internal pull-down resistor
    Serial.begin(9600);               // Use Serial port for debugging
 
}
 
// loop() runs over and over again, as quickly as it can execute.
void loop() {
  
  int GcurrButton = digitalRead(ButtonG);
  checkGcurrButton(GcurrButton, GprevButton, Gcounter, speakerPin1, speakerPin2, speakerPin3);

  int AcurrButton = digitalRead(ButtonA);
  checkAcurrButton(AcurrButton, AprevButton, Acounter, speakerPin1, speakerPin2, speakerPin3);

  int BcurrButton = digitalRead(ButtonB);
  checkBcurrButton(BcurrButton, BprevButton, Bcounter, speakerPin1, speakerPin2, speakerPin3);

  int McurrButton = digitalRead(MusicState);
  checkMcurrButton(McurrButton, MprevButton, Gcounter, Bcounter, Acounter, speakerPin1, speakerPin2, speakerPin3);
}