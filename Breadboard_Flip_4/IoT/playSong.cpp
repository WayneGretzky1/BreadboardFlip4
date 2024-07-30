#include <playSong.h>


// Melody & Note Duration Arrays

void playYesterday(int speakerPin1, int speakerPin2, int speakerPin3) {
  for (int i = 0; i < 30; i++) {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1500 / 4, eighth note = 1000/8, etc.
    int noteDuration1 = 1500/yesterdayNote1[i];
    int noteDuration2 = 1500/yesterdayNote2[i];
    int noteDuration3 = 1500/yesterdayNote3[i];
    
    tone(speakerPin1, yesterdayM1[i],noteDuration1);
    tone(speakerPin2, yesterdayM1[i],noteDuration2);
    tone(speakerPin3, yesterdayM1[i],noteDuration3);
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


void playHotlineBling(int speakerPin1, int speakerPin2, int speakerPin3) {
  for (int i = 0; i < 96; i++) {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1500 / 4, eighth note = 1000/8, etc.
    int noteDuration1 = 1500/hotlineBlingNote1[i];
    int noteDuration2 = 1500/hotlineBlingNote2[i];
    int noteDuration3 = 1500/hotlineBlingNote3[i];
    
    tone(speakerPin1, hotlineBlingM1[i],noteDuration1);
    tone(speakerPin2, hotlineBlingM2[i],noteDuration2);
    tone(speakerPin3, hotlineBlingM3[i],noteDuration3);
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


void playPianoMan(int speakerPin1, int speakerPin2, int speakerPin3) {
  for (int i = 0; i < 49; i++) {
    // to calculate the note duration, take one second
    // divided by the note type.
    //e.g. quarter note = 1500 / 4, eighth note = 1000/8, etc.
    int noteDuration1 = 1500/pianoManNote1[i];
    int noteDuration2 = 1500/pianoManNote2[i];
    int noteDuration3 = 1500/pianoManNote3[i];
    
    tone(speakerPin1, pianoManM1[i],noteDuration1);
    tone(speakerPin2, pianoManM2[i],noteDuration2);
    tone(speakerPin3, pianoManM3[i],noteDuration3);
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