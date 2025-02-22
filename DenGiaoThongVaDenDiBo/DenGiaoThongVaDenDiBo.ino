// Pin 2 là đầu vào digital
int carRed=12; //Đèn giao thông cho xe
int carYellow=11;
int carGreen=10;
int pedRed=9; //Đèn giao thông cho người
int pedGreen=8;
int button=2; // Nút nhấn cho người đi bộ
int crossTime=5000; // Thời gian cho phép qua đường
unsigned long changeTime; // Thời gian khi nút được nhấn
void setup() {
  pinMode(carRed, OUTPUT);
  pinMode(carYellow, OUTPUT);
  pinMode(carGreen, OUTPUT);
  pinMode(pedRed, OUTPUT);
  pinMode(pedGreen, OUTPUT);
  pinMode(button, INPUT);
// Ban đầu, bật đèn xanh cho xe cơ giới và đèn đỏ cho người đi bộ
  digitalWrite(carGreen, HIGH);
  digitalWrite(pedRed, HIGH);
}
void loop() {
  int state=digitalRead(button);
/* Kiểm tra nút nhấn và thời gian kể từ lần gần nhất bấm nút nhất 
hơn 5s thì thực hiện lệnh của khối trúc IF */
  if (state==HIGH && (millis()-changeTime)>5000) { 
// Gọi hàm thay đổi đèn cho người đi bộ
    changeLights(); }
}
void changeLights() {
  digitalWrite(carGreen, LOW); //Tắt đèn xanh
  digitalWrite(carYellow, HIGH); // Bật đèn vàng
  delay(2000);
  digitalWrite(carYellow, LOW);
  digitalWrite(carRed, HIGH);
  delay(1000);
  digitalWrite(pedRed, LOW);
  digitalWrite(pedGreen, HIGH);
  delay(crossTime);
// Nhấp nháy đèn xanh cho người đi bộ trong 2 giây
  for (int x=0; x<10; x++) {
  digitalWrite(pedGreen, HIGH);
  delay(200);
  digitalWrite(pedGreen, LOW);
  delay(200); }
  digitalWrite(pedRed, HIGH);
  delay(2000);
  digitalWrite(carRed, LOW);
  digitalWrite(carGreen, HIGH);
  changeTime=millis();
 }