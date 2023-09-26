//Moshe Moskowitz and Ryan Connolly - Makeup

void setup() {
  analogWriteResolution(12);
}

void loop() {
  analogWrite(DAC1, 0);
  analogWrite(DAC1, 4095);
}
