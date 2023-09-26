// Moshe Moskowitz and Ryan Connolly

void power(int pin, int percent, int duration){
  analogWrite(pin,double(percent*2.55));
  delay(duration);
}

//where the pin selects which pin to pulse, percent represents a percentage from 0 (off) to 100 (full power), and duration is in milliseconds. Test with a loop like the  following:

void setup() {
  Serial.begin(115200);
  for (int i = 100; i >= 0; i--){
    Serial.print(i);
    Serial.println("% Power");
    power(11, i, 3000); // turn pin 11 to i% power for 3 seconds
  }
}

void loop() {

}