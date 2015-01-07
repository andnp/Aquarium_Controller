void setup()
{
  pinMode(7,OUTPUT);
  digitalWrite(7,HIGH);
  pinMode(8,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  int inp = averageRead(100);
  if(inp > 950){
    digitalWrite(8, HIGH);
    delay(15000);
  } else {
    digitalWrite(8, LOW);
  }
  delay(1000);
  Serial.println(inp);
}

int averageRead(int trials){
  float out = 0;
  for(int i = 0; i <= trials; i++){
    out += analogRead(A0);
  }
  return out / trials;
}
