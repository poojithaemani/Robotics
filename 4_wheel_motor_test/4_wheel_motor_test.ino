 
//for motor A
#define ENA 10
#define IN1 22
#define IN2 24

//for motor B
#define ENB 11
#define IN3 26
#define IN4 28

//for motor C
#define ENC 12//ENA slot for second H bridge
#define IN5 30//IN1 slot for second H bridge
#define IN6 32//IN2 slot for second H bridge
//for motor D
#define END 13//ENB slot for second H bridge
#define IN7 34//IN3 slot for second H bridge
#define IN8 36//IN4 slot for second H bridge

int i;

void setup() {
  // put your setup code here, to run once:
  pinMode(ENA, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENC, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(END, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
 
}

void loop() {
  // put your main code here, to run repeatedly:
  for(i=0;i<=5;i++)
  {
    forward(); //Make the robot go forward, full speed
    delay(3000);
    exit(0);
  }
  
  right(); //Make the robot stop
  delay(2000);
    
  
    for(i=0;i<=5;i++)
    {
    forward(); //Make the robot go forward, full speed
    delay(3000);
    exit(0);
  }

 

  
}

void forward()
{
  //analogWrite function is used to change the rpm of motor, it ranges from 0 to 255 where 0 is the min speed and 255 is the max speed
  analogWrite(ENA, 200);//motor on left side
  analogWrite(ENB, 200);//motor on right side
  analogWrite(ENC, 200);
  analogWrite(END, 200);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  
}
void right()
{
  analogWrite(ENA, 200);
  analogWrite(ENB, 0);
  analogWrite(ENC, 200);
  analogWrite(END, 0);
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
}
void halt()
{
  analogWrite(ENA, 0);
  analogWrite(ENB, 0); 
  analogWrite(ENB, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, LOW);
}
