/* #18
================================================================================================================= 
Channel M&E Automation:https://bit.ly/3uz3Bt8
Vui lòng đăng ký kênh https://bit.ly/34a2of1 cảm ơn các bạn rất nhiều!
Danh sách phát Arduino : https://bit.ly/34BUDlU
=================================================================================================================
*/
int IN1= 8;
int IN2= 9;
int IN3= 10;
int IN4= 11;

int FPB  =2; // forward push button
int Stop=3; //Stop push button
int RPB =4; // Reverse push button

int Step = 0;
int Status = 3;
//===============================================================================================================
void setup() 
{

pinMode(FPB,INPUT);
pinMode(Stop,INPUT);
pinMode(RPB,INPUT);

pinMode(IN1, OUTPUT);
pinMode(IN2, OUTPUT);
pinMode(IN3, OUTPUT);
pinMode(IN4, OUTPUT);

}
//===============================================================================================================
void loop() 
{ 
  
  if(digitalRead(FPB) == HIGH) 
     Status =1;
  
  else if(digitalRead(RPB) == HIGH )
     Status  = 2;  
  
  else if(digitalRead(Stop) == HIGH) 
    Status =3; 

 if(Status ==1)
    Forward_Reverse(true); 
 
 else if(Status ==2)
    Forward_Reverse(false);  
 
 else
 {digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);}
    
if(Step>7) 
   Step=0; 
 delay(1); 
}
//===============================================================================================================
void Forward_Reverse (bool dir)
{
    if(dir){
    switch(Step){
  case 0:
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  break;
  case 1:
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  break;
  case 2:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  break;
  case 3:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  break;
  case 4:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  break;
  case 5:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  break;
  case 6:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  break;
  case 7:
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  break;
} 
  }
  
  else{
    switch(Step){
  case 0:
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  break;
  case 1:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  break;
  case 2:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, HIGH);
  break;
  case 3:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
 break;
 case 4:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  break;
  case 5:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  break;
  case 6:
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  break;
 case 7:
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  break;
  case 8:
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  break;
  
} 
  }
Step++;
 
}
//=============================================== END =========================================================
