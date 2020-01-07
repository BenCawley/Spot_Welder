int ledG = 2;
int ledR = 3; 
int ledB = 4;
int relay = 5;
int pedal = 6;

void setup() {
    
    pinMode(ledG, OUTPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledB, OUTPUT);
    pinMode(relay, OUTPUT);
    pinMode(pedal, INPUT_PULLUP);
    digitalWrite(ledG, HIGH);

    Serial.begin(9600);
}
void loop() {
    float relayDelay = 0;
    float mainPulse = 30 + relayDelay;
    float firstPulse = (mainPulse * 0.12) + relayDelay;
    float debounce = 500;
    
    if (digitalRead(pedal) == LOW) {
        Serial.write("Relay Triggered\n");
 //       digitalWrite(ledG, LOW);
 //       digitalWrite(ledR, HIGH);

        digitalWrite(relay, HIGH);
        delay(firstPulse);
        digitalWrite(relay, LOW);

 //       digitalWrite(ledR, LOW);
 //       digitalWrite(ledB, HIGH);
       delay(500);

 //       digitalWrite(ledB, LOW);
 //       digitalWrite(ledR, HIGH);

        digitalWrite(relay, HIGH);
        delay(mainPulse);
        digitalWrite(relay, LOW);

//        digitalWrite(ledR, LOW);
 //       digitalWrite(ledG, HIGH);

        delay(debounce);
        while(digitalRead(pedal) == LOW) {
            true;
        }
    }
}