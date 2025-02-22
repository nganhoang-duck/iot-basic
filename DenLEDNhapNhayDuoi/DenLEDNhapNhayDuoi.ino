char ledPin[]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
unsigned int t1=280;
unsigned int t2=120;
void setup() {
  for (char i=0; i<10; i++)
  {
    pinMode(ledPin[i], OUTPUT);  
  }
}
void loop() {
  for (char x=0; x<9; x++) {
    digitalWrite(ledPin[x], HIGH);
    digitalWrite(ledPin[x+1], HIGH);
    delay(t1);
    digitalWrite(ledPin[x], LOW);
    delay(t2);
  }
  for (char y=9; y>0; y--) {
    digitalWrite(ledPin[y], HIGH);
    digitalWrite(ledPin[y-1], HIGH);
    delay(t1);
    digitalWrite(ledPin[y], LOW);
    delay(t2);
  } 
} 
