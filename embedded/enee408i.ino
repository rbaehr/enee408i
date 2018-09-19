#define INA1 2
#define INB1 4
#define INA2 7
#define INB2 8

#define PWM1 3
#define PWM2 5

#define PING1 6
#define PING2 13

#define SPEED_HIGH 100
#define SPEED_MED 75
#define SPEED_LOW 25

#define MAGIC 33

void setup() {
  Serial.begin(9600);
   
  pinMode(INA1, OUTPUT);
  pinMode(INB1, OUTPUT);
  pinMode(INA2, OUTPUT);
  pinMode(INB2, OUTPUT);
  
  pinMode(PING1, OUTPUT);
  pinMode(PING2, OUTPUT);
  

}

void cwLeft(int speed) {
  digitalWrite(INA1, HIGH);
  digitalWrite(INB1, LOW);
  analogWrite(PWM1, speed); 
}

void cwRight(int speed) {
  digitalWrite(INA2, LOW);
  digitalWrite(INB2, HIGH);
  analogWrite(PWM2, speed); 
}

void ccwLeft(int speed) {
  digitalWrite(INA1, LOW);
  digitalWrite(INB1, HIGH);
  analogWrite(PWM1, speed); 
}

void ccwRight(int speed) {
  digitalWrite(INA2, HIGH);
  digitalWrite(INB2, LOW);
  analogWrite(PWM2, speed); 
}

void forward(int speed) {
  ccwLeft(speed);
  ccwRight(speed + MAGIC);  
}

void backward(int speed) {
  cwLeft(speed);
  cwRight(speed + MAGIC);
}

void left(int speed) {
  cwLeft(speed);
  ccwRight(speed + MAGIC);
}

void right(int speed) {
  ccwLeft(speed);
  cwRight(speed + MAGIC);
}

long getPing1() {
  pinMode(PING1, OUTPUT);
  digitalWrite(PING1, LOW);
  delayMicroseconds(2);
  digitalWrite(PING1, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING1, LOW);
  
  pinMode(PING1, INPUT);
  
  return pulseIn(PING1, HIGH); 
}

long getPing2() {
  pinMode(PING2, OUTPUT);
  digitalWrite(PING2, LOW);
  delayMicroseconds(2);
  digitalWrite(PING2, HIGH);
  delayMicroseconds(5);
  digitalWrite(PING2, LOW);
  
  pinMode(PING2, INPUT);
  
  return pulseIn(PING2, HIGH); 
}

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

void loop() {
  long a = getPing1();
  long b = getPing2();
  
  long incha = microsecondsToInches(a);
  long inchb = microsecondsToInches(b);
  
  Serial.print(incha);
  Serial.print(" ");
  Serial.print(inchb);
  Serial.println();
  
  delay(100);
  
    //forward(SPEED_LOW);
}
