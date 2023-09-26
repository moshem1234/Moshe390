//Moshe Moskowitz and Ryan Connolly - Makeup

void setup() {
  const double freq = 100000;
  const int samples = 1000;
  double wave[samples];
  
  analogWriteResolution(12);
  analogWrite(DAC1, 0);
  analogWrite(DAC1, 4095);

  for(int i = 0; i < samples; i++){
    wave[i] = 2048 + 2047 * sin(freq * 2 * pi * i * ((double(1)/freq)/samples));
  }
}

void loop() {
  for(int i = 0; i < samples; i++){
    analogWrite(DAC1, wave[i]);
    delay(double(1)/(freq*samples));
  }
}
