#define DEFAULT_CLOCK_DELAY 500 // ms

#define PIN_CLOCK 2

unsigned int clock_delay = DEFAULT_CLOCK_DELAY;
bool CLOCK = false;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(PIN_CLOCK, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    char c = Serial.read();
    switch (c) {
      case '+':
        // increase clock speed (+10%)
        clock_delay *= 0.9;
        Serial.println(clock_delay);
        break;

      case '-':
        // decrease clock speed (-10%)
        clock_delay *= 1.1;
        Serial.println(clock_delay);
        break;
    }
  }
  digitalWrite(PIN_CLOCK, CLOCK ? HIGH : LOW);
  delay(clock_delay);

  CLOCK = !CLOCK;
}
