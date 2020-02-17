#define DEFAULT_CLOCK_DELAY 500 // ms

#define PIN_CLOCK 2

unsigned int clock_delay = DEFAULT_CLOCK_DELAY;
bool CLOCK = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(PIN_CLOCK, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(PIN_CLOCK, CLOCK ? HIGH : LOW);
  delay(clock_delay);

  CLOCK = !CLOCK;
}
