// Include the servo library:
#include <Servo.h>
// Create a new servo object:
Servo servo1;
// Define the servo pin:
#define servoPin 11
// Create a variable to store the servo position:
int angle = 0;
void setup() {
  // Attach the Servo variable to a pin:
  servo1.attach(servoPin);
}
void loop() {
  // Tell the servo to go to a particular angle:
  /*servo1.write(90);
  delay(1000);
  servo1.write(180);
  delay(1000);
  servo1.write(0);
  delay(1000);*/
  // Sweep from 0 to 180 degrees:
  for (angle = 0; angle <= 45; angle ++) {
    servo1.write(angle);
    delay(100);
    
  }
  // And back from 180 to 0 degrees:
  for (angle = 45; angle >= 0; angle --) {
    servo1.write(angle);
    delay(70);
    
    
  }
  //delay(1000);
}
