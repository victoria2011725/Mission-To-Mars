const int Left_Rev = 12;
const int Left_Fwd = 11;
const int Left_Enable=10;
const int Right_Enable=9;
const int Right_Rev =8;
const int Right_Fwd=7;


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
void left()
{
  digitalWrite(Left_Enable, LOW);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Right_Fwd, HIGH);
  digitalWrite(Left_Rev, LOW);
  digitalWrite(Right_Rev, LOW);
}
void right()
{
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, LOW);
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Right_Fwd, LOW);
  digitalWrite(Left_Rev, LOW);
  digitalWrite(Right_Rev, LOW);
}
void figure_of_eight(){
  unsigned long time;
  for (int i = 0; i < 4; i++) {
    time = millis();
    while (millis() - time < 2000)
    { forward(); }
    stop(); 

    time = millis();
    while (millis() - time < 850)
    { left(); }
    stop();
  }
  for (int i = 0; i < 4; i++) {
    time = millis();
    while (millis() - time < 850)
    { right();}
    stop();
    
    time = millis();
    while (millis() - time < 2000)
    { forward(); }
    stop();
  }
  }


void setup()
{
  pinMode(Left_Rev, OUTPUT);
  pinMode(Left_Fwd,OUTPUT);
  pinMode(Left_Enable,OUTPUT);
  pinMode(Right_Enable,OUTPUT);
  pinMode(Right_Rev,OUTPUT);
  pinMode(Right_Fwd,OUTPUT);
  
  figure_of_eight();
}

void loop(){
 
}



