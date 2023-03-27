#include <Servo.h>

// Pin assignments
const int button_Pin = 2;
const int curmotor_1_Pin = 8;
const int curmotor_2_Pin = 9;
const int mouth_2_Pin = 10;
const int hand_3_Pin = 11;
const int door_4_Pin = 12;
const int fire_led_Pin = 5;
const int blood_led_Pin = 6;

// Servo assignments
Servo cur_servo1;
Servo cur_servo2;
Servo mth_servo2;
Servo han_servo3;
Servo dor_servo4;

// Servo initial positions
const int cur_servo1InitPos = 0;
const int cur_servo2InitPos = 90;
const int mth_servo2InitPos = 1;
const int han_servo3InitPos = 75;
const int dor_servo4InitPos = 100;

// Servo target positions
const int cur_servo1TargetPos = 90;
const int cur_servo2TargetPos = 0;
const int mth_servo2TargetPos = 50;
const int han_servo3TargetPos = 0;
const int dor_servo4TargetPos = 30;

void setup() {
  // Set up button pin
  pinMode(button_Pin, INPUT_PULLUP);

  // Set up LED pins
  pinMode(fire_led_Pin, OUTPUT);
  pinMode(blood_led_Pin, OUTPUT);

  // Attach servos to pins
  cur_servo1.attach(curmotor_1_Pin);
  cur_servo2.attach(curmotor_2_Pin);
  mth_servo2.attach(mouth_2_Pin);
  han_servo3.attach(hand_3_Pin);
  dor_servo4.attach(door_4_Pin);

  // Set initial servo positions
  cur_servo1.write(cur_servo1InitPos);
  cur_servo2.write(cur_servo2InitPos);
  mth_servo2.write(mth_servo2InitPos);
  han_servo3.write(han_servo3InitPos);
  dor_servo4.write(dor_servo4InitPos);
}

void loop() {
  // Button press
  while (digitalRead(button_Pin) == HIGH) {
    delay(10);
  }
  delay(50);
  while (digitalRead(button_Pin) == LOW) {
    delay(10);
  }

  // 0. Light up fireplace
  digitalWrite(fire_led_Pin, HIGH);
  delay(2000);

  // 1. Drop curtains from servos
  cur_servo1.write(cur_servo1TargetPos);
  delay(300);

  cur_servo2.write(cur_servo2TargetPos);
  delay(3000);

  // 2. Move mouth and hand to their target positions
  mth_servo2.write(mth_servo2TargetPos);
  delay(1000);
  
  han_servo3.write(han_servo3TargetPos);
  delay(1000); 

  // 3. Make mouth perform rapid up-down movements and flash the "blood" LEDs
  for (int i = 0; i < 6; i++) {
    mth_servo2.write(mth_servo2InitPos);
    digitalWrite(blood_led_Pin, HIGH);
    delay(200);
    
    mth_servo2.write(mth_servo2TargetPos);
    digitalWrite(blood_led_Pin, LOW);
    delay(200);
  }
  mth_servo2.write(mth_servo2InitPos);
  delay(800);

  // 4. Move door (hunter) to its target position and flash all LEDs
  dor_servo4.write(dor_servo4TargetPos);
  delay(600);

  for (int i = 1; i < 14; i++) {
    digitalWrite(fire_led_Pin, LOW);
    digitalWrite(blood_led_Pin, HIGH);
    delay(100);
    
    digitalWrite(fire_led_Pin, HIGH);
    digitalWrite(blood_led_Pin, LOW);
    delay(100);
  }
  delay(1000);

  // 5. Move mouth to open (wolf dead); Move hand down (red saved)
  mth_servo2.write(20);
  delay(200);
  han_servo3.write(10);
  delay(200);
  mth_servo2.write(35);
  delay(200);
  han_servo3.write(20);
  delay(200);
  mth_servo2.write(mth_servo2TargetPos);
  delay(200);
  han_servo3.write(30);
  delay(200);
  han_servo3.write(40);
  delay(200);
  han_servo3.write(50);
  delay(200);
  han_servo3.write(60);
  delay(200);
  han_servo3.write(70);
  delay(200);
  han_servo3.write(80);
  delay(200);
  han_servo3.write(90);
  delay(200);
  han_servo3.write(96);
  delay(1000);

  // - Wait for 5 seconds -
  delay(5000);

  // Reset sequence
  digitalWrite(fire_led_Pin, LOW);
  delay(200);
  cur_servo1.write(cur_servo1InitPos);
  delay(1000);
  cur_servo2.write(cur_servo2InitPos);
  delay(1000);
  mth_servo2.write(mth_servo2InitPos);
  delay(1000);
  han_servo3.write(han_servo3InitPos);
  delay(1000);
  dor_servo4.write(60);
  delay(300);
  dor_servo4.write(dor_servo4InitPos);
  delay(1000);
}
