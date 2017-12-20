#define MOTOR1A 5
#define MOTOR1B 6
#define MOTOR2A 10
#define MOTOR2B 11

int Speed = 160;
int turnSpeed = 130;

char new_command, old_command;

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
    
    new_command = Serial.read();
    if(new_command == old_command) continue;

    switch(new_command){
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

    old_command = new_command;
  }
}

void forward()
{
  digitalWrite(MOTOR1A, HIGH);
  digitalWrite(MOTOR1B, LOW);
  digitalWrite(MOTOR2A, HIGH);
  digitalWrite(MOTOR2B, LOW);
  //analogWrite(MOTOR1B, Speed);
  //analogWrite(MOTOR1B, Speed);
}

void backward()
{
  
  digitalWrite(MOTOR1A, LOW);
  digitalWrite(MOTOR1B, HIGH);
  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, HIGH);
  //analogWrite(MOTOR1A, Speed);
  //analogWrite(MOTOR1A, Speed);
}

void turnLeft()
{
  digitalWrite(MOTOR1A, LOW);
  digitalWrite(MOTOR1B, HIGH);
  digitalWrite(MOTOR2A, HIGH);
  digitalWrite(MOTOR2B, LOW);
  //analogWrite(MOTOR1B, turnSpeed);
  //analogWrite(MOTOR2B, turnSpeed);
}

void turnRight()
{
  digitalWrite(MOTOR1A, HIGH);
  digitalWrite(MOTOR1B, LOW);
  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, HIGH);
  //analogWrite(MOTOR1B, turnSpeed);
  //analogWrite(MOTOR2B, turnSpeed);
}

void Stop()
{
  digitalWrite(MOTOR1A, LOW);
  digitalWrite(MOTOR1B, LOW);
  digitalWrite(MOTOR2A, LOW);
  digitalWrite(MOTOR2B, LOW);
}

