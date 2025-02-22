#include <Stepper.h>
// Định nghĩa các chân kết nối với Arduino
#define IN1 8
#define IN2 9
#define IN3 10
#define IN4 11

// Khai báo biến lưu trữ số xung cho một vòng quay
int stepsPerRevolution = 4096;

// Khai báo biến lưu trữ chân analog kết nối với biến trở
int potPin = A0;

// Khai báo biến lưu trữ giá trị điện áp từ biến trở
int potValue = 0;

// Khai báo biến lưu trữ giá trị tốc độ từ biến trở
int speedValue = 0;

// Khởi tạo đối tượng stepper motor
Stepper myStepper(stepsPerRevolution, IN1, IN3, IN2, IN4);

void setup() {
  // Thiết lập tốc độ serial monitor là 9600 baud
  Serial.begin(9600);
}

void loop() {
  
  // Đọc giá trị điện áp từ biến trở (từ 0 -1023)
  potValue = analogRead(potPin);
  
  // Chuyển đổi giá trị điện áp thành giá trị tốc độ (vòng/phút)
  speedValue = map(potValue,0,1023,1,20);
  
   // Thiết lập tốc độ quay của động cơ bước 
   myStepper.setSpeed(speedValue);
   
   // Quay một vòng theo chiều kim đồng hồ
   Serial.print("Quay mot vong theo chieu kim dong ho voi toc do ");
   Serial.print(speedValue);
   Serial.println(" vong/phut");
   myStepper.step(stepsPerRevolution);
   
}