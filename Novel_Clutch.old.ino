#define clutchF_ENA A5
#define clutchF_IN1 A4
#define clutchF_IN2 A3
#define clutchF_IN3 A2
#define clutchF_IN4 A1
#define clutchF_ENB 11

#define clutchR_ENA 8
#define clutchR_IN1 9
#define clutchR_IN2 10
#define clutchR_IN3 A0
#define clutchR_IN4 12
#define clutchR_ENB 13

#define motor_ENA 2
#define motor_IN1 3
#define motor_IN2 4
#define motor_IN3 5
#define motor_IN4 6
#define motor_ENB 7

#define testDelay 2000

#define Right 1
#define Left 0
#define Front 1
#define Rear 0
#define Engage 1
#define Disengage 0
#define Start 1
#define Stop 0

int reverse = 0;
int right = 0;

void setup() {
  pinMode(clutchF_ENA,OUTPUT);
  pinMode(clutchF_IN1,OUTPUT);
  pinMode(clutchF_IN2,OUTPUT);
  pinMode(clutchF_IN3,OUTPUT);
  pinMode(clutchF_IN4,OUTPUT);
  pinMode(clutchF_ENB,OUTPUT);
  
  pinMode(clutchR_ENA,OUTPUT);
  pinMode(clutchR_IN1,OUTPUT);
  pinMode(clutchR_IN2,OUTPUT);
  pinMode(clutchR_IN3,OUTPUT);
  pinMode(clutchR_IN4,OUTPUT);
  pinMode(clutchR_ENB,OUTPUT);
  
  pinMode(motor_ENA,OUTPUT);
  pinMode(motor_IN1,OUTPUT);
  pinMode(motor_IN2,OUTPUT);
  pinMode(motor_IN3,OUTPUT);
  pinMode(motor_IN4,OUTPUT);
  pinMode(motor_ENB,OUTPUT);
}

void loop() {

  reverse = 0;
  right = 0;
  
  /*
  clutch(Engage,Rear,Left);
  clutch(Engage,Rear,Right);
  clutch(Disengage,Front,Left);
  clutch(Disengage,Front,Right);
  motor(Front,Start);
  */

  


  
  
  
  moveForward(3000);
  moveReverse(3000);
  turnAroundRight(1000);
  turnAroundLeft(1000);

  

}

void turnAround(int seconds){
  clutch(Disengage,Rear,Left);
  clutch(Disengage,Rear,Right);
  clutch(Engage,Front,Left);
  clutch(Engage,Front,Right);
  motor(Front,Start);
  motor(Rear,Stop);
  delay(seconds);
  motor(Front,Stop);
}
void turnAroundRight(int seconds){
  right = 1;
  turnAround(seconds);
}
void turnAroundLeft(int seconds){
  right = 0;
  turnAround(seconds);
}

void moveForward(int seconds){
  clutch(Engage,Rear,Left);
  clutch(Engage,Rear,Right);
  clutch(Disengage,Front,Left);
  clutch(Disengage,Front,Right);
  motor(Front,Stop);
  motor(Rear,Start);
  delay(seconds);
  motor(Rear,Stop);
}
void moveReverse(int seconds){
  reverse = 1;
  moveForward(seconds);
}

void motor(int FrontRear, int StartStop){
  switch(StartStop){
    case Start:
      switch(FrontRear){
        case Rear:
        if(reverse==1){
          digitalWrite(motor_IN1,HIGH);
          digitalWrite(motor_IN2,LOW);
        }else{
          digitalWrite(motor_IN1,LOW);
          digitalWrite(motor_IN2,HIGH);
        }
          digitalWrite(motor_ENA,HIGH);
        break;
        case Front:
        if(right==1){
          digitalWrite(motor_IN3,HIGH);
          digitalWrite(motor_IN4,LOW);
        }else{
          digitalWrite(motor_IN3,LOW);
          digitalWrite(motor_IN4,HIGH);
        }
          digitalWrite(motor_ENB,HIGH);
        break;
      }
    break;
    case Stop:
      switch(FrontRear){
        case Rear:
          digitalWrite(motor_ENA,LOW);
          digitalWrite(motor_IN1,LOW);
          digitalWrite(motor_IN2,LOW);
        break;
        case Front:
          digitalWrite(motor_ENB,LOW);
          digitalWrite(motor_IN3,LOW);
          digitalWrite(motor_IN4,LOW);
        break;
      }
    break;
  }
}

void clutch(int EngageDisengage, int FrontRear, int RightLeft){
  switch(EngageDisengage){
    case Engage:
      switch(FrontRear){
          case Front:
            switch(RightLeft){
              case Right:
              //Front,Right
                digitalWrite(clutchF_ENA,HIGH);
                digitalWrite(clutchF_IN1,HIGH);
                digitalWrite(clutchF_IN2,LOW);
              //Front,Right
              break;
              case Left:
              //Front,Left
                digitalWrite(clutchF_ENB,HIGH);
                digitalWrite(clutchF_IN3,HIGH);
                digitalWrite(clutchF_IN4,LOW);
              //Front,Left
              break;
            }
          break;
          case Rear:
            switch(RightLeft){
              case Right:
              //Rear,Right
                digitalWrite(clutchR_ENA,HIGH);
                digitalWrite(clutchR_IN1,HIGH);
                digitalWrite(clutchR_IN2,LOW);
              //Rear,Right
              break;
              case Left:
              //Rear,Left
                digitalWrite(clutchR_ENB,HIGH);
                digitalWrite(clutchR_IN3,HIGH);
                digitalWrite(clutchR_IN4,LOW);
              //Rear,Left
              break;
            }
          break;
        }
    break;
    case Disengage:
      switch(FrontRear){
          case Front:
            switch(RightLeft){
              case Right:
              //Front,Right
                digitalWrite(clutchF_ENA,LOW);
                digitalWrite(clutchF_IN1,LOW);
                digitalWrite(clutchF_IN2,LOW);
              //Front,Right
              break;
              case Left:
              //Front,Left
                digitalWrite(clutchF_ENB,LOW);
                digitalWrite(clutchF_IN3,LOW);
                digitalWrite(clutchF_IN4,LOW);
              //Front,Left
              break;
            }
          break;
          case Rear:
            switch(RightLeft){
              case Right:
              //Rear,Right
                digitalWrite(clutchR_ENA,LOW);
                digitalWrite(clutchR_IN1,LOW);
                digitalWrite(clutchR_IN2,LOW);
              //Rear,Right
              break;
              case Left:
              //Rear,Left
                digitalWrite(clutchR_ENB,LOW);
                digitalWrite(clutchR_IN3,LOW);
                digitalWrite(clutchR_IN4,LOW);
              //Rear,Left
              break;
            }
          break;
        }
    break;
}

}

