#include <Servo.h> // Include the servo library

// create servo objects to control rotation and magnet for each leg
// front left
Servo rotate1;
Servo mag1;
// front right
Servo rotate2;
Servo mag2;
// back left
Servo rotate3;
Servo mag3;
// back right
Servo rotate4;
Servo mag4;

int bAngle = -30; // backward angle
int fAngle = 30; // forward angle

int magOn = 180; // mag on angle
int magOff = 0; // mag off angle

//funcs to convert intuitive angles to servo angles
int to13w(int angle) {
  return 90 + angle;
}
int to24w(int angle) {
  return 90 - angle;
}
int to14r(int angle) {
  return angle + 135;
}
int to23r(int angle) {
  return angle + 45;
}

void setup() {
  // initialize serial communications at 9600 bps:
  Serial.begin(9600);
  
  rotate1.attach(2);
  rotate2.attach(3);
  rotate3.attach(4);
  rotate4.attach(5);

  mag1.attach(10);
  mag2.attach(11);
  mag3.attach(12);
  mag4.attach(13);

  mag1.write(magOff);
  mag2.write(magOff);
  mag3.write(magOff);
  mag4.write(magOff);

  rotate1.write(to13w(bAngle));
  rotate2.write(to24w(fAngle));
  rotate3.write(to13w(fAngle));
  rotate4.write(to24w(bAngle));

  delay(3000);
  Serial.println("PUT ON WALL");

  mag2.write(magOn);
  mag3.write(magOn);
  delay(3000);
  Serial.println("Start");
}

void loop() {
  rotate1.write(to13w(fAngle));
  rotate2.write(to24w(bAngle));
  rotate3.write(to13w(bAngle));
  rotate4.write(to24w(fAngle));
  
  delay(3000);
  mag1.write(magOn);
  mag4.write(magOn);
  delay(3000);
  mag2.write(magOff);
  mag3.write(magOff);
  delay(3000);
  
  rotate1.write(to13w(bAngle));
  rotate2.write(to24w(fAngle));
  rotate3.write(to13w(fAngle));
  rotate4.write(to24w(bAngle));
  
  delay(3000);
  mag2.write(magOn);
  mag3.write(magOn);
  delay(3000);
  mag1.write(magOff);
  mag4.write(magOff);
  delay(3000);
}
