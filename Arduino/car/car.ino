#define MOTOR1A 5
#define MOTOR1B 6
#define MOTOR2A 9
#define MOTOR2B 10

int Speed = 160;
int turnSpeed = 130;

char command;                             

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  pinMode(MOTOR1A, OUTPUT);
  pinMode(MOTOR1B, OUTPUT);
  pinMode(MOTOR2A, OUTPUT);
  pinMode(MOTOR2B, OUTPUT);

  digitalWrite(MOTOR1A, LOW);
  digitalWrite(MOTOR1B, LOW);
  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    command = Serial.read();
    Stop();

    switch(command){
      case'w':
        forward();
        break;
      case's':
        backward();
        break;
      case'a':
        turnLeft();
        break;
      case'd':
        turnRight();
        break; 
      case'x':
        Stop();
        break;       
    }    
  }
}

void forward()
{
  digitalWrite(MOTOR1A, 0);
  //digitalWrite(MOTOR1B, LOW);
  digitalWrite(MOTOR2A, 0);
  //digitalWrite(MOTOR2B, LOW);
  analogWrite(MOTOR1B, Speed);
  analogWrite(MOTOR2B, Speed);
}

void backward()
{

  analogWrite(MOTOR1B, 0);
  analogWrite(MOTOR2B, 0);
  analogWrite(MOTOR1A, Speed);
  analogWrite(MOTOR2A, Speed);
}

void turnLeft()
{
  analogWrite(MOTOR1A, 0);
  analogWrite(MOTOR2A, 0);
  analogWrite(MOTOR1B, Speed - 30);
  analogWrite(MOTOR2B, Speed);
}

void turnRight()
{
  analogWrite(MOTOR1A, 0);
  analogWrite(MOTOR2A, 0);
  analogWrite(MOTOR1B, Speed - 30);
  analogWrite(MOTOR2B, Speed);
}

void Stop()
{
  analogWrite(MOTOR1A, 0);
  analogWrite(MOTOR1B, 0);
  analogWrite(MOTOR2A, 0);
  analogWrite(MOTOR2B, 0);
}

