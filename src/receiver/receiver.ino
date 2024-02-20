int pinEN = 8;
int dirPinX = 2;
int stepPinX = 5;

int stepsPerRevolution = 200;  // 1/1 
// int stepsPerRevolution = 400;  // 1/2  
//int stepsPerRevolution = 1600; // 1/8 
// int stepsPerRevolution = 3200;   // 1/16 

int dataSerial = 0;
int nilai = 0;
int nilaiDelay = 500;

void setup() {
  Serial.begin(9600);
  pinMode(stepPinX, OUTPUT);
  pinMode(dirPinX, OUTPUT);
  pinMode(pinEN, OUTPUT);
}

void loop()
{
  if (Serial.available() != 0)
  {
    digitalWrite(pinEN, LOW);       //Aktifkan driver
    dataSerial = Serial.parseInt();
    nilai = map(dataSerial, 0, 360, 0, stepsPerRevolution);

    Serial.print("Dari Serial:");
    Serial.print(dataSerial);
    Serial.print("   Step:");
    Serial.println(nilai);
  }

  //if value +, turn right
  if (dataSerial > 0)
  {
    digitalWrite(dirPinX, LOW);

    for (int i = 0; i < nilai; i++)
    {
      digitalWrite(stepPinX, HIGH);
      delayMicroseconds(nilaiDelay);
      digitalWrite(stepPinX, LOW);
      delayMicroseconds(nilaiDelay);
    }

  }

  //If value -, turn left
  if (dataSerial < 0)
  {
    digitalWrite(dirPinX, HIGH);

    for (int i = 0; i > nilai; i--)
    {
      digitalWrite(stepPinX, HIGH);
      delayMicroseconds(nilaiDelay);
      digitalWrite(stepPinX, LOW);
      delayMicroseconds(nilaiDelay);
    }
  }

  delay(1000);
  digitalWrite(pinEN, 0); //Turn off the driver, use this for testing only, to keep the stepper motor from overheating. 
}