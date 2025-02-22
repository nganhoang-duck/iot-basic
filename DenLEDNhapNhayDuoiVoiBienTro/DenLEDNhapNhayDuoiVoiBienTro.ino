char LedPin[]={0,1,2,3,4,5,6,7};
char i, x, y;
int t1;
void setup() {
  for(i=0; i<8; i++)   {
    pinMode(LedPin[i], OUTPUT);
  }
  Serial.begin(4600);
}
void loop() {
  t1=analogRead(5);
  for(x=0; x<8; x++)   {
    digitalWrite(LedPin[x], HIGH);
  	delay(t1);
  	digitalWrite(LedPin[x], LOW);
  	delay(10);
  }
  for(y=7; y>0; y--) {
    digitalWrite(LedPin[y], HIGH);
  	delay(t1);
  	digitalWrite(LedPin[y], LOW);
  	delay(10); 
  }
  Serial.println("Turn potentiometer");
  Serial.println();
  Serial.print("Blink time (ms): ");
  Serial.println(t1); 
}
