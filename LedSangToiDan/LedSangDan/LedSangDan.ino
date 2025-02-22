char ledPin = 10;
unsigned char ledVal;
void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  for (char x=0; x<52; x++){
    ledVal=5*x;
    analogWrite(ledPin,ledVal);
    delay(50);
  }
  for (char x=52; x>0; x--){
    ledVal=5*x;
    analogWrite(ledPin,ledVal);
    delay(50);
  }
}