void setup() {
    int ledG = 2;
    int ledR = 3;
    int ledB = 4;
    int relay = 5;
    int pedal = 6;
    
    pinMode(ledG, OUTPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledB, OUTPUT);
    pinMode(relay, OUTPUT);
    pinMode(pedal, INPUT_PULLUP);
    digitalWrite(ledG, HIGH);
}
void loop() {
    float relayDelay = 0.015;
    float mainPulse = 0.05 + relayDelay;
    float firstPulse = (mainPulse * 0.12) + relayDelay;
    
    if (digitalRead(pedal) == LOW) {
        digitalWrite(ledG, LOW);
        digitalWrite(ledR, HIGH);

        digitalWrite(relay, HIGH);
        delay(firstPulse);
        digitalWrite(relay, LOW);

        digitalWrite(ledR, LOW);
        digitalWrite(ledB, HIGH);
        delay(500);

        digitalWrite(ledB, LOW);
        digitalWrite(ledR, HIGH);

        digitalWrite(relay, HIGH);
        delay(mainPulse);
        digitalWrite(relay, LOW);

        digitalWrite(ledR, LOW);
        digitalWrite(ledG, HIGH);
    }
    else {
        continue;
    }
}
