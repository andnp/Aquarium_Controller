//#include <HC_SR04.h>
#include <NewPing.h>

//HC_SR04 ultrasonic(12,13);
NewPing ultrasonic(12,13,200);

int i = 0;
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
  if(inp < 8 && i > 25){
    digitalWrite(8, LOW);
    long start = millis();
    while(inp < 10){
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
}

