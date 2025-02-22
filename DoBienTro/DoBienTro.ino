const char POT=1; //Sử dụng chân A1 trên board để lấy giá trị từ chiết áp
const float R=5000;
void setup() {
Serial.begin(9600); // Khai báo sử dụng Serial với tốc độ baud = 9600
}
void loop() {
int Na = analogRead(POT); //Tiến hành đọc giá trị chiết áp
int Va = map(Na, 0, 511, 0, 2500); 
int R2 = map(Va, 0, 2500, 0, 5000); 
int R1=R-R2;
Serial.println("Resistor's measuarement: ");
Serial.println();
Serial.print("Analog Reading: ");
Serial.println(Na); //In giá trị thô đọc được
Serial.print("Voltage: ");
Serial.print(Va); //In giá trị điện áp tại A1
Serial.println(" mV"); //In kí tự 'mV' và kết thúc dòng thông tin
Serial.print("Resistor R1: ");
Serial.print(R1);
Serial.println(" Ohm");
Serial.print("Resistor R2: ");
Serial.print(R2);
Serial.println(" Ohm");
delay(2000); //Đợi 2s sau đó tiếp tục lặp
}
