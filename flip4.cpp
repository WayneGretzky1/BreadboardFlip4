#include <Grove_LCD_RGB_Backlight.h>
 
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
 

 //Yesterday Melody & Note Duration Arrays
double yesterdayM1[] = {1244.508,1318.51,1174.659,1046.502,1046.502,783.9909,622.254,783.9909,622.254,783.9909,587.3295,523.2511,440,391.9954,440,523.2511,523.2511,523.2511,523.2511,391.9954,440,493.8833,415.3047,523.2511,415.3047,523.2511,523.2511,783.9909,880,1046.502
};
double yesterdayM2[] = {0,440,391.9954,329.6276,293.6648,261.6256,0,220,0,220,195.9977,164.8138,329.6276,0,146.8324,146.8324,195.9977,174.6141,174.6141,130.8128,0,0,0,0,0,0,0,0,0,0
};
double yesterdayM3[] = { 0,220,195.9977,164.8138,146.8324,130.8128,0,110,0,110,97.99886,82.40689,293.6648,0,73.41619,73.41619,97.99886,87.30706,87.30706,65.40639,0,0,0,0,0,0,0,0,0,0
};
double yesterdayNote1[] = {64,8,8,8,4,8,64,4,64,8,8,8,2.6667,16,16,8,8,4,2.6667,16,16,8,64,8,64,4,2.6667,16,16,8
};
double yesterdayNote2[] = {64,8,8,8,4,8,64,4,64,8,8,8,2.6667,4,8,4,1.6,8,4,1.6,16,16,8,64,8,64,4,2.6667,16,16,8
};
double yesterdayNote3[] = {64,8,8,8,4,8,64,4,64,8,8,8,2.6667,4,8,4,1.6,8,4,1.6,16,16,8,64,8,64,4,2.6667,16,16,8
};
 

//Hotline Bling Melody & Note Duration Arrays
double hotlineBlingM1[] = {698.45,1046.5,1046.5,1046.5,880,1046.5,1046.5,1174.6,0,349.23,698.45,880,784,698.45,784,784,880,0,0,1046.5,1046.5,1046.5,880,1046.5,1046.5,1174.7,0,0,0,698.45,880,784,698.45,784,784,880,1046.5,880,1046.5,880,1046.5,880,1046.5,880,1174.66,880,880,880,880,932.32,880,784,698.45,784,784,880,880,880,880,932.32,880,784,698.45,784,784,880,880,880,880,932.32,880,784,698.45,784,784,698.45,1046.5,880,1046.5,880,1046.5,880,1046.5,880,1174.66,1174.66,880,880,880,880,932.32,880,784,698.45,784,784
}; 
double hotlineBlingM2[] = {0,0,0,0,0,698,698,698,0,0,440,0,0,523,523,523,0,0,0,0,0,0,698,698,698,0,0,0,698,880,784,698,784,784,880,1046,880,1046,880,1046,880,1046,880,587,587,0,0,0,0,0,0,0,523,523,659,0,0,0,0,0,0,0,466,466,466,0,0,0,0,0,0,0,523,523,0,0,0,0,0,0,0,0,0,587,587,466,0,0,0,0,0,0,0,523,523
};
double hotlineBlingM3[] = {0,0,0,220,220,349,440,0,0,0,0,116.5,110,329.6,392,110,329.6,392,110,116.5,174.6,220,116.5,174.6,220,116.5,110,165,196,0,116.5,147,233,261.6,293.7,0,0,174.6,110,165,220,261.6,329.6,0,0,0,0,165,110,98,147,196,233,293.7,0,0,196,110,165,220,261.6,329.6,0,0,116.5,174.6,220,233,261.6,293.7,349,440,0,0,0,0,0,174.6,110,165,220,261.6,329.6,220,261.6,0,0,0,0,0,0,0,0,0,0,0
};
double hotlineBlingNote1[] = {8,8,8,8,8,8,8,1.66,2,8,8,8,8,8,8,8,1.66,2,8,8,8,8,8,8,8,1.2658,8,2,8,8,8,8,8,8,8,0.8,8,8,8,8,8,8,8,8,1,8,8,8,8,8,8,8,8,4,1.3333,8,8,8,8,8,8,8,8,4,1.333,8,8,8,8,8,8,8,8,4,1.333,8,8,8,8,8,8,8,8,8,1.1428,8,8,8,8,8,8,8,8,8,4,2.125
};
double hotlineBlingNote2[] = {8,8,8,8,8,8,8,1.662,8,4,8,8,8,8,1.66,2,8,8,8,8,8,8,8,1.2658,8,2,8,8,8,8,8,8,8,0.8,8,8,8,8,8,8,8,8,1,8,8,8,8,8,8,8,8,4,1.3333,8,8,8,8,8,8,8,8,4,1.333,8,8,8,8,8,8,8,8,4,1.333,8,8,8,8,8,8,8,8,8,1.1428,8,8,8,8,8,8,8,8,8,4,2.125
};
double hotlineBlingNote3[] = {8,8,8,4,2.666,8,2.666,2,8,8,8,4,2.666,8,2,2.666,8,4,4,2.66,8,2,2.666,8,4,4,2.666,8,1.15,1,8,8,8,8,2,4,4,2,8,8,8,8,2,8,8,8,8,4,4,8,8,8,8,2,4,4,2,8,8,8,8,2,1,8,8,8,8,8,8,8,8,8,8,4,8,8,8,4,8,8,8,8,8,8,8,8,8,8,4,8,8,8,8,8,8,8
};

//Piano Man Melody & Note Duration Arrays
double pianoManM1[] = {0,0,392,392,392,392,349,329.6,349,329.6,261.6,0,0,261.6,261.6,261.6,261.6,261.6,261.6,293.6,293.6,0,392,392,392,392,392,349,329.6,349,329.6,261.1,220,220,220,261.6,329.6,349.2,329.6,293.6,261.6,0,0,0,0,0,0,0,0
};
double pianoManM2[] = {349,329.6,293.6,0,329.6,329.6,0,293.6,293.6,0,261.6,261.6,0,261.6,261.6,0,261.6,261.6,0,261.6,261.6,0,370,370,392,293.6,247,293.6,0,329.6,329.6,0,293.6,293.6,0,261.6,261.6,0,261.6,261.6,0,261.6,261.6,0,261.6,261.6,0,329.6,329.6
};
double pianoManM3[] = {174.6,164.8,146.8,130.8,261.6,261.6,123.5,247,247,110,220,220,98,196,196,87.3,220,220,82.4,196,196,73.4,220,220,98,196,247,131,261.6,261.6,123.47,247,247,110,220,220,98,196,196,87.3,220,220,98,196,196,0,0,0,0
};
double pianoManNote1[] = {4,4,4,2,4,4,2.66,8,8,8,2,4,4,4,4,2.66,8,4,8,2.66,1,8,8,8,8,4,1,8,8,4,8,1.66,8,8,2,8,8,4,4,4,1.33,4,4,4,4,4,4,4,4
};
double pianoManNote2[] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,8,8,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
};
double pianoManNote3[] = {4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4,4
};

 
 
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
  if (GcurrButton == HIGH && GprevButton == LOW) {
    Gcounter = Gcounter + 1;
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("Now Playing:");
    
    lcd.setCursor(0, 1);
    lcd.print("Yesterday");
    
    for (int thisNote = 0; thisNote < arraySize(yesterdayM1); thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1500 / 4, eighth note = 1000/8, etc.
      int noteDuration1 = 1500/yesterdayNote1[thisNote];
      int noteDuration2 = 1500/yesterdayNote2[thisNote];
      int noteDuration3 = 1500/yesterdayNote3[thisNote];
      
      tone(speakerPin1, yesterdayM1[thisNote],noteDuration1);
      tone(speakerPin2, yesterdayM1[thisNote],noteDuration2);
      tone(speakerPin3, yesterdayM1[thisNote],noteDuration3);
    // to distinguish the notes, set a min time between them.
    // the note's duration + 30% seems to work well:
      int pauseBetweenNotes1 = noteDuration1 * 1.30;
      delay(pauseBetweenNotes1);

    // stop the tone playing:
      noTone(speakerPin1);
      noTone(speakerPin2);
      noTone(speakerPin3);
    }      
  }
  GcurrButton = GprevButton;
  

  int AcurrButton = digitalRead(ButtonA);
  if(AcurrButton == HIGH && AprevButton == LOW) {
    Acounter = Acounter + 1;
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("Now Playing:");
    
    lcd.setCursor(0, 1);
    lcd.print("Song #3");

    for (int thisNote = 0; thisNote < arraySize(hotlineBlingM1); thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1500 / 4, eighth note = 1000/8, etc.
      int noteDuration1 = 1500/hotlineBlingNote1[thisNote];
      int noteDuration2 = 1500/hotlineBlingNote2[thisNote];
      int noteDuration3 = 1500/hotlineBlingNote3[thisNote];
      
      tone(speakerPin1, hotlineBlingM1[thisNote],noteDuration1);
      tone(speakerPin2, hotlineBlingM2[thisNote],noteDuration2);
      tone(speakerPin3, hotlineBlingM3[thisNote],noteDuration3);
    // to distinguish the notes, set a min time between them.
    // the note's duration + 30% seems to work well:
      int pauseBetweenNotes1 = noteDuration1 * 1.30;
      delay(pauseBetweenNotes1);

    // stop the tone playing:
      noTone(speakerPin1);
      noTone(speakerPin2);
      noTone(speakerPin3);
    }
  }
  AcurrButton = AprevButton;


  int BcurrButton = digitalRead(ButtonB);
  if(BcurrButton == HIGH && BprevButton == LOW){
    Bcounter = Bcounter + 1;
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("Now Playing:");
    
    lcd.setCursor(0, 1);
    lcd.print("Song #5");

    for (int thisNote = 0; thisNote < arraySize(pianoManM1); thisNote++) {

    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1500 / 4, eighth note = 1000/8, etc.
      int noteDuration1 = 1500/pianoManNote1[thisNote];
      int noteDuration2 = 1500/pianoManNote2[thisNote];
      int noteDuration3 = 1500/pianoManNote3[thisNote];
      
      tone(speakerPin1, pianoManM1[thisNote],noteDuration1);
      tone(speakerPin2, pianoManM2[thisNote],noteDuration2);
      tone(speakerPin3, pianoManM3[thisNote],noteDuration3);
    // to distinguish the notes, set a min time between them.
    // the note's duration + 30% seems to work well:
      int pauseBetweenNotes1 = noteDuration1 * 1.30;
      delay(pauseBetweenNotes1);

    // stop the tone playing:
      noTone(speakerPin1);
      noTone(speakerPin2);
      noTone(speakerPin3);
    }
  }
  BcurrButton = BprevButton;
  

  int McurrButton = digitalRead(MusicState);
  if(McurrButton == HIGH && MprevButton == LOW) {
    
    lcd.clear();
    lcd.setCursor(0, 0);

    lcd.print("Session Finished:");
    lcd.setCursor(0, 1);

    if (Gcounter > Acounter && Gcounter > Bcounter) {  
      lcd.print("#1 = Yesterday");
      Particle.publish("Yesterday Wins");
    }

    else if (Acounter > Gcounter && Acounter > Bcounter)  {
      lcd.print("#1 = Song#1");
      Particle.publish("Awin");
    } 
    
    else if (Bcounter > Gcounter && Bcounter > Acounter) {
      lcd.print("#1 = Song#2");
      Particle.publish("Bwin");
    }
  
    Gcounter = 0;
    Bcounter = 0;
    Acounter = 0;

    delay(5000);

    lcd.clear();
    lcd.setCursor(0, 0);
    
    lcd.print("Play song for");
    lcd.setCursor(0, 1);
    lcd.print("new session.");
  }

}