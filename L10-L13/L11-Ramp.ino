//Moshe Moskowitz and Ryan Connolly - Makeup

void sawtooth(double freq, int zero, int divisions){
  for (int i = 0; i < divisions; i++){
    analogWrite(DAC1, zero);
    output += (4096 / divisions);
    delayMicroseconds(((double(1)/freq)*pow(10,6))/divisions);
  }
}

void setup() {
  analogWriteResolution(12);
  analogWrite(DAC1, 0);
  analogWrite(DAC1, 4095);
}

void loop() {
  sawtooth(440, 0, 32);  
}
