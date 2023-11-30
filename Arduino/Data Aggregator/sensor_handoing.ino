#include <SoftwareSerial.h>

#define echoPin 2
#define trigPin 3
long duration;
int distance;

SoftwareSerial mySerial(10, 11); // RX, TX

void setup()
{
  Serial.begin(57600);

  // HC-SR04 sensor setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  while (!Serial)
  {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  Serial.println("Goodnight moon!");

  // set the data rate for the SoftwareSerial port
  mySerial.begin(115200);
  mySerial.println("Hello, world?");
}

void loop()
{
  // Measure distance using HC-SR04
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = (duration / 2) / 29.1; // Convert to distance

  // If distance is less than 20cm (indicating something is detected), send '1', otherwise send '0'.
  if (distance < 20 && distance > 0)
  {
    mySerial.write('1');
    Serial.write('1');
  }
  else
  {
    mySerial.write('0');
    Serial.write('0');
  }

  if (mySerial.available())
  {
    Serial.write(mySerial.read());
  }

  if (Serial.available())
  {
    mySerial.write(Serial.read());
  }

  delay(2000); // Delay a bit before the next loop iteration for stable readings
}
