#define LED 2
#define BUTTON 3
#define CARBON A0
#define NATURALGAS A1
#define BUZZER 4

int carbonmax = 310;
int naturalgasmax = 400;

bool state = false;
bool buttonstate = false;

unsigned long time = 0;

void setup() {

  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP);
  pinMode(CARBON, INPUT);
  pinMode(NATURALGAS, INPUT);
  pinMode(BUZZER, OUTPUT);
}

void loop() {

  if (digitalRead(BUTTON) == 0 && !buttonstate) {
    buttonstate = true;
    time = millis();
  }


  if (digitalRead(BUTTON) == 1) {
    buttonstate = false;
    time = millis();
  }

  if (digitalRead(BUTTON) == 0 && buttonstate) {
    if (millis() - time >= 3000) {
      if (state) {
        time = millis();
        state = true;
        digitalWrite(LED, 1);
      }
      else{
        time = millis();
        state = false;
        digitalWrite(LED, 0);
      }
    }
  }





  if (state) {
    if (analogRead(CARBON) >= carbonmax || analogRead(NATURALGAS) >= naturalgasmax) {
      digitalWrite(BUZZER, 1);
    } else {
      digitalWrite(BUZZER, 0);
    }
  }
}
