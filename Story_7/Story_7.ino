const int Left_Rev = 12;
const int Left_Fwd = 11;
const int Left_Enable = 10;
const int Right_Enable = 9;
const int Right_Rev = 8;
const int Right_Fwd = 7;

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
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Left_Rev, HIGH); 
  digitalWrite(Right_Fwd, HIGH); 
  digitalWrite(Right_Rev, LOW);
}
void right()
{
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Left_Fwd, HIGH);
  digitalWrite(Right_Fwd, LOW);
  digitalWrite(Left_Rev, LOW);
  digitalWrite(Right_Rev, HIGH);
}
void figure_of_eight()
{
  for (int i = 0; i < 4; i++) 
  {
    forward();
    delay(2000);
    left();
    delay(850);
  }
  for (int i = 0; i < 4; i++) 
  {
    right();
    delay(850);
    forward();
    delay(2000);
  }
}


void setup()
{
  pinMode(Left_Rev, OUTPUT);
  pinMode(Left_Fwd, OUTPUT);
  pinMode(Left_Enable, OUTPUT);
  pinMode(Right_Enable, OUTPUT);
  pinMode(Right_Rev, OUTPUT);
  pinMode(Right_Fwd, OUTPUT);
  
  figure_of_eight();
}

void loop()
{
}



