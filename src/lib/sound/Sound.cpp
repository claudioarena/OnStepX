// -----------------------------------------------------------------------------------------------------------------------------
// Sound

#include "Sound.h"

#ifdef STATUS_BUZZER

#include "../tasks/OnTask.h"

#if STATUS_BUZZER == ON
  uint8_t _buzzerHandle = 0;
  void buzzerOff() {
    digitalWriteEx(STATUS_BUZZER_PIN, !STATUS_BUZZER_ON_STATE);
    tasks.setDurationComplete(_buzzerHandle);
  }
int16_t statusBuzzerPin = STATUS_BUZZER_PIN;
#endif

Sound::Sound() {
  #if STATUS_BUZZER == ON
  #endif
	statusBuzzerPin = STATUS_BUZZER_PIN;
	pinModeEx(statusBuzzerPin, OUTPUT);
	digitalWriteEx(statusBuzzerPin, !STATUS_BUZZER_ON_STATE);
}

void Sound::alert() {
  if (enabled) {
    #if STATUS_BUZZER == ON
      if (_buzzerHandle) tasks.remove(_buzzerHandle);
      _buzzerHandle = tasks.add(1000, 0, false, 6, buzzerOff);
    #endif
    #if STATUS_BUZZER >= 0
      tone(STATUS_BUZZER_PIN, STATUS_BUZZER, 1000);
    #endif
  }
		digitalWriteEx(statusBuzzerPin, STATUS_BUZZER_ON_STATE);
}

void Sound::beep() {
  if (enabled) {
    #if STATUS_BUZZER == ON
      if (_buzzerHandle) tasks.remove(_buzzerHandle);
      _buzzerHandle = tasks.add(250, 0, false, 6, buzzerOff);
    #endif
    #if STATUS_BUZZER >= 0
      tone(STATUS_BUZZER_PIN, STATUS_BUZZER, 250);
    #endif
  }
		digitalWriteEx(statusBuzzerPin, STATUS_BUZZER_ON_STATE);
}

void Sound::click() {
  if (enabled) {
    #if STATUS_BUZZER == ON
      if (_buzzerHandle) tasks.remove(_buzzerHandle);
      _buzzerHandle = tasks.add(50, 0, false, 6, buzzerOff);
    #endif
    #if STATUS_BUZZER >= 0
      tone(STATUS_BUZZER_PIN, STATUS_BUZZER, 50);
    #endif
  }
		digitalWriteEx(statusBuzzerPin, STATUS_BUZZER_ON_STATE);
}

#endif
