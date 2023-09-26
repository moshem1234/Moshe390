//Moshe Moskowitz and Ryan Connolly - Makeup

void setup() {
  analogWriteResolution(12);
  analogWrite(DAC1, 0);
  analogWrite(DAC1, 4095);
}

void loop() {
  double freq = 440;
  int samples = 32;
  double output;
  for(int i = 0; i <= samples; i++){
    output = 2048 + 2047 * sin(freq*2*PI*i*((1/freq)/samples));
    analogWrite(DAC1, output);
    delay(double(1)/(freq * samples));
  }
}
