//#include <HC_SR04.h>
#include <NewPing.h>

//HC_SR04 ultrasonic(12,13);
NewPing ultrasonic(12,13,200);

int i = 0;
int alt = 0;
int wire_value = 0;
void setup()
{
  pinMode(11,OUTPUT);
  digitalWrite(11,HIGH);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  //int inp = ultrasonic.smoothMedianFilter(500);
  int inp = ultrasonic.convert_cm(ultrasonic.ping_median(50));
  if(inp < 16 && i > 25){
    digitalWrite(8, LOW);
    long start = millis();
    while(inp < 19){
      //inp = ultrasonic.smoothMedianFilter(500);
      inp = ultrasonic.convert_cm(ultrasonic.ping_median(50));
      Serial.println(inp);
      delay(100);
      if(millis() - start > (1000 * 30)) break;
    }
  } else {
    digitalWrite(8, HIGH);
    i++;
  }
  Serial.println(inp);
  delay(100);
  
  if(alt){
    pinMode(A4, OUTPUT);
    digitalWrite(A4, HIGH);
    pinMode(A5, INPUT);
    wire_value = analogRead(A5);
    digitalWrite(A4, LOW);
    alt = 0;
  } else {
    pinMode(A5, OUTPUT);
    digitalWrite(A5, HIGH);
    pinMode(A4, INPUT);
    wire_value = analogRead(A4);
    digitalWrite(A5, LOW);
    alt = 1; 
  }
  Serial.println(wire_value);
  if(wire_value > 1000){
    digitalWrite(8, LOW);
    //Serial.println("touch");
    delay(15000);
    digitalWrite(8, HIGH);
    wire_value = 0; 
  }
}

