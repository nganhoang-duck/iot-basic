// Khai báo các chân I/O sử dụng trong chương trình
int Red=10;
int Yellow=9;
int Green=8;
void setup() {
 pinMode(Red, OUTPUT);
 pinMode(Yellow, OUTPUT);
 pinMode(Green, OUTPUT);
}
void loop() {
 //Bật đèn xanh trong 2 giây
 digitalWrite(Green, HIGH); 
 delay(2000); 
 digitalWrite(Green, LOW);
 //Nhấp nháy đèn vàng 2 giây
  for (int i=0; i<10; i++){
  digitalWrite(Yellow, HIGH);
  delay(100);
  digitalWrite(Yellow, LOW);
  delay(100);
  } 
 digitalWrite(Yellow, LOW);
 //Bật đèn đỏ trong 2 giây
 digitalWrite(Red, HIGH); 
 delay(2000); 
 digitalWrite(Red, LOW);
}
