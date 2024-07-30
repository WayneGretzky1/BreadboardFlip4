#include <playSong.h>

#ifndef PUSHBUTTON_INCLUDE
#define PUSHBUTTON_INCLUDE


void checkGcurrButton(int GcurrButton, int GprevButton, int Gcounter, int speakerPin1, int speakerPin2, int speakerPin3);
void checkAcurrButton(int AcurrButton, int AprevButton, int Acounter, int speakerPin1, int speakerPin2, int speakerPin3);
void checkBcurrButton(int BcurrButton, int BprevButton, int Bcounter, int speakerPin1, int speakerPin2, int speakerPin3);
void checkMcurrButton(int McurrButton, int MprevButton, int Gcounter, int Bcounter, int Acounter, int speakerPin1, int speakerPin2, int speakerPin3);

#endif