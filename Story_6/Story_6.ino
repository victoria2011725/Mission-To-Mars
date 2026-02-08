const int RIGHT_FEEDBACK = 2; // Pin numbers on Rover for each motor sensor
const int LEFT_FEEDBACK = 3;
const int Left_Rev = 12;
const int Left_Fwd = 11;
const int Left_Enable=10;
const int Right_Enable=9;
const int Right_Rev =8;
const int Right_Fwd=7;

volatile int rightcounter = 0; 
volatile int leftcounter = 0;



void forward()
{
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Right_Fwd, HIGH);
  digitalWrite(Left_Rev, LOW);
  digitalWrite(Right_Rev, LOW);
  }
void stop()
{ 
  digitalWrite(Left_Enable, LOW);
  digitalWrite(Right_Enable, LOW);
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Right_Fwd, LOW);
  digitalWrite(Left_Rev, LOW);
  digitalWrite(Right_Rev, LOW);
}

void RightMotorISR(){
  // adds one to the counter on each motor revolution   
  rightcounter++;
}
void LeftMotorISR(){
  leftcounter++;
}

void setup()
{
  Serial.begin(115200);
  pinMode(RIGHT_FEEDBACK, INPUT);
  pinMode(LEFT_FEEDBACK,INPUT);
  attachInterrupt(digitalPinToInterrupt(RIGHT_FEEDBACK),RightMotorISR,RISING);
  attachInterrupt(digitalPinToInterrupt(LEFT_FEEDBACK),LeftMotorISR,RISING);
  pinMode(Left_Rev, OUTPUT);
  pinMode(Left_Fwd,OUTPUT);
  pinMode(Left_Enable,OUTPUT);
  pinMode(Right_Enable,OUTPUT);
  pinMode(Right_Rev,OUTPUT);
  pinMode(Right_Fwd,OUTPUT);
}

void loop(){
  // check if 2m or over has been driven, if no continue if yes stop
  while (rightcounter < 870 and leftcounter <870) 
{ 
  forward();  
  // print out the values to show counters are operating
  Serial.println(rightcounter);
  Serial.println(leftcounter);
}
  stop();
  exit(0);
  
}



