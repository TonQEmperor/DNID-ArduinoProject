#include <Servo.h>

unsigned long startTime;
const unsigned long duration = 10000;

Servo m1;
Servo m2;

void setup() {
  m1.attach(9);
  m2.attach(10);

  startTime = millis();
}

void loop() {
  m2.write(70);
  delay(1000);

  m1.write(95);
  delay(500);

  m2.write(110);
  delay(500);
  
  for( int i=0; i<10; i++ )
  {
    m1.write(70);
    delay(300);

    m1.write(90);
    delay(300);
  }

  m1.write(70);
  delay(500);
 
  if( millis() - startTime >= duration )
  {
    while( true ) {}
  }
}
