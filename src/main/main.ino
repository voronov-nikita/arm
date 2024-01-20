void setup(){
  Serial.begin(9600);
  pinMode(3, INPUT);
}

void loop(){
  Serial.println(!digitalRead(3));
}