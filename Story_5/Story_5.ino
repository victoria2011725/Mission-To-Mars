// C++ code
//
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

void right()
{
  analogWrite(Left_Enable,200);
  analogWrite(Right_Enable,90);
  analogWrite(Right_Fwd,90);
  analogWrite(Left_Fwd,200);
  digitalWrite(Left_Rev,LOW);
  digitalWrite(Right_Rev,LOW);
}
void left()
{
  analogWrite(Left_Enable,90);
  analogWrite(Right_Enable,200);
  analogWrite(Right_Fwd,200);
  analogWrite(Left_Fwd,90);
  digitalWrite(Left_Rev,LOW);
  digitalWrite(Right_Rev,LOW);
  
}
  
    
void setup()
{
  pinMode(Left_Rev, OUTPUT);
  pinMode(Left_Fwd,OUTPUT);
  pinMode(Left_Enable,OUTPUT);
  pinMode(Right_Enable,OUTPUT);
  pinMode(Right_Rev,OUTPUT);
  pinMode(Right_Fwd,OUTPUT);
    
}


void loop() 
{
  //2 seconds straight, 2 seconds left, 2 seconds right, 2 left, 2 right
  
  int recorded_time = millis();
  while (millis()-recorded_time<2000)
  {
    forward();    
  }
  
  recorded_time = millis();
  while (millis()-recorded_time<2000)
  {
    left();    
  }

  recorded_time = millis();
  while (millis()-recorded_time<2000)
  {
    right();    
  }
  
  
  recorded_time = millis();
  while (millis()-recorded_time<2000)
  {
    left();    
  }

  recorded_time = millis();
  while (millis()-recorded_time<2000)
  {
    right();    
  }
    
  
   
  
}
  