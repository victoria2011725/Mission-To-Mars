// ---------------------------------------------------------------------------
// Example NewPing library sketch that does a ping about 20 times per second.
// ---------------------------------------------------------------------------
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
void reverse()
{
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Right_Fwd, LOW);
  digitalWrite(Left_Rev, HIGH);
  digitalWrite(Right_Rev, HIGH);
  
}
void left() {
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Left_Rev, HIGH); 
  digitalWrite(Right_Fwd, HIGH); 
  digitalWrite(Right_Rev, LOW);
}
// rover should stop if no ground within 5 cm, max drop height 12 cm so pythagoras gives maximum laser easured distance to be 13.const int Left_Rev = 12;
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
void reverse()
{
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Right_Fwd, LOW);
  digitalWrite(Left_Rev, HIGH);
  digitalWrite(Right_Rev, HIGH);
  
}
void left() {
  digitalWrite(Left_Enable, HIGH);
  digitalWrite(Right_Enable, HIGH);
  digitalWrite(Left_Fwd, LOW);
  digitalWrite(Left_Rev, HIGH); 
  digitalWrite(Right_Fwd, HIGH); 
  digitalWrite(Right_Rev, LOW);
}
// sensor should be angled so that it hits the ground 5 cm away in the horizontal direction from current location
// rover should stop if no ground within 5 cm, max drop height 12 cm so pythagoras gives maximum sensor measured distance to be 13
const int max_expected_distance=13;
#include <NewPing.h>

#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  pinMode(Left_Rev, OUTPUT);
  pinMode(Left_Fwd,OUTPUT);
  pinMode(Left_Enable,OUTPUT);
  pinMode(Right_Enable,OUTPUT);
  pinMode(Right_Rev,OUTPUT);
  pinMode(Right_Fwd,OUTPUT);
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  int distance = sonar.ping_cm();
}
void loop(){
  while (sonar.ping_cm()<=13 and sonar.ping_cm()>0) {
    forward();
    delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    Serial.print("Ping: ");
    Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  }
  stop();
  delay(500);

  reverse();
  delay(500);

  while (True){
    stop();

  }
}
#include <NewPing.h>

#define TRIGGER_PIN  4  // Arduino pin tied to trigger pin on the ultrasonic sensor.
#define ECHO_PIN     5  // Arduino pin tied to echo pin on the ultrasonic sensor.
#define MAX_DISTANCE 200 // Maximum distance we want to ping for (in centimeters). Maximum sensor distance is rated at 400-500cm.

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE); // NewPing setup of pins and maximum distance.

void setup() {
  pinMode(Left_Rev, OUTPUT);
  pinMode(Left_Fwd,OUTPUT);
  pinMode(Left_Enable,OUTPUT);
  pinMode(Right_Enable,OUTPUT);
  pinMode(Right_Rev,OUTPUT);
  pinMode(Right_Fwd,OUTPUT);
  Serial.begin(115200); // Open serial monitor at 115200 baud to see ping results.
  int distance = sonar.ping_cm();
}
void loop(){
  while (sonar.ping_cm()<=13 and sonar.ping_cm()>0) {
    forward();
    delay(50);                     // Wait 50ms between pings (about 20 pings/sec). 29ms should be the shortest delay between pings.
    Serial.print("Ping: ");
    Serial.print(sonar.ping_cm()); // Send ping, get distance in cm and print result (0 = outside set distance range)
  }
  stop();
  delay(500);

  reverse();
  delay(500);

  while (True){
    stop();

  }
}