#include <pushButton.h>
#include <Grove_LCD_RGB_Backlight.h>

rgb_lcd lcd;

void checkGcurrButton(int GcurrButton, int GprevButton, int Gcounter, int speakerPin1, int speakerPin2, int speakerPin3) {
  if (GcurrButton == 1 && GprevButton == 0) {
    Gcounter = Gcounter + 1;
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("Now Playing:");
    
    lcd.setCursor(0, 1);
    lcd.print("Yesterday");
    
    playYesterday(speakerPin1, speakerPin2, speakerPin3);   
  }
  GcurrButton = GprevButton;
}

  

void checkAcurrButton(int AcurrButton, int AprevButton, int Acounter, int speakerPin1, int speakerPin2, int speakerPin3) {
  if(AcurrButton == 1 && AprevButton == 0) {
    Acounter = Acounter + 1;
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("Now Playing:");
    
    lcd.setCursor(0, 1);
    lcd.print("Song #3");

    playHotlineBling(speakerPin1, speakerPin2, speakerPin3);
  }
  AcurrButton = AprevButton;
}


void checkBcurrButton(int BcurrButton, int BprevButton, int Bcounter, int speakerPin1, int speakerPin2, int speakerPin3) {
  if(BcurrButton == 1 && BprevButton == 0){
    Bcounter = Bcounter + 1;
    lcd.clear();
    
    lcd.setCursor(0, 0);
    lcd.print("Now Playing:");
    
    lcd.setCursor(0, 1);
    lcd.print("Song #5");

    playPianoMan(speakerPin1, speakerPin2, speakerPin3);
  }
  BcurrButton = BprevButton;
}

void checkMcurrButton(int McurrButton, int MprevButton, int Gcounter, int Bcounter, int Acounter, int speakerPin1, int speakerPin2, int speakerPin3) {
  if(McurrButton == 1 && MprevButton == 0) {
    
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
