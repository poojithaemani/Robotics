#define ENA 7 // Echo Pin
#define ENB 8 // Trigger Pin

long duration, distance; // Duration used to calculate distance
long startTime ;                    // start time for stop watch
long elapsedTime ;                  // elapsed time for stop watch
long Speed;

void setup() {
 Serial.begin (9600);
 pinMode(ENA, OUTPUT);
 pinMode(ENB, INPUT);
 }

void loop() {
digitalWrite(ENA, LOW); 
 delayMicroseconds(2); 

 digitalWrite(ENB, HIGH);
 delayMicroseconds(10); 

 digitalWrite(ENA, LOW);
 duration = pulseIn(ENB, HIGH);

 //Calculate the distance (in cm) based on the speed of sound.
 distance = duration/58.2;

 if(distance>4)
 {
  startTime=millis();
 }

 elapsedTime =   millis() - startTime;
float Speed = 0.75/(elapsedTime*1000);  //0.75 is fixed value


 Serial.println(elapsedTime); Serial.println(Speed);
  delay(50);
}
