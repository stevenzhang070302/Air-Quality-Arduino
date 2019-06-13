/* MQ-7 Carbon Monoxide Sensor Circuit with Arduino */
const int AOUTpin = 0;
const int DOUTpin = 8;
int limit;
int value;
/* MQ-3 Alcohol Sensor Circuit with Arduino */
const int AOUTpin1 = 1;
const int DOUTpin1 = 7;
int limit1;
int value1;
/* MQ-8 Hydrogen Sensor Circuit with Arduino */
const int AOUTpin2 = 2;
const int DOUTpin2 = 6;
int limit2;
int value2;
/* MQ-2 CO2 Sensor Circuit with Arduino */
const int AOUTpin3 = 3;
const int DOUTpin3 = 5;
int limit3;
int value3;
/* MQ-135 Ammonia, Sulfide, Benzene Sensor Circuit with Arduino */
const int AOUTpin4 = 4;
const int DOUTpin4 = 4;
int limit4;
int value4;
/* MQ-135 Methane, Propane, Butane Sensor Circuit with Arduino */
const int AOUTpin5 = 5;
const int DOUTpin5 = 3;
int limit5;
int value5;
//BT
#include <SoftwareSerial.h>
SoftwareSerial BTserial(10, 9); // RX | TX
char c = ' ';

void setup() {
  //MQ-7
  Serial.begin(9600);//sets the baud rate
  pinMode(DOUTpin, INPUT);//sets the pin as an input to the arduino
  pinMode(DOUTpin1, INPUT);//sets the pin as an input to the arduino
  pinMode(DOUTpin2, INPUT);//sets the pin as an input to the arduino
  pinMode(DOUTpin3, INPUT);//sets the pin as an input to the arduino
  pinMode(DOUTpin4, INPUT);//sets the pin as an input to the arduino
  pinMode(DOUTpin5, INPUT);//sets the pin as an input to the arduino
  //BT
  Serial.begin(9600);
  Serial.println("Enter AT commands:");
  BTserial.begin(9600);
}

void loop()
{
  //MQ-7
  value = analogRead(AOUTpin); //reads the analaog value from the CO sensor's AOUT pin
  limit = digitalRead(DOUTpin); //reads the digital value from the CO sensor's DOUT pin
  Serial.print("CO: ");
  Serial.println(value);//prints the CO value
  BTserial.println("CO value: ");
  BTserial.println(value);
  //MQ-3
  value1 = analogRead(AOUTpin1);
  limit1 = digitalRead(DOUTpin1);
  Serial.print("Alcohol: ");
  Serial.println(value1);
  BTserial.println("Alcohol value: ");
  BTserial.println(value1);
  //MQ-8
  value2 = analogRead(AOUTpin2);
  limit2 = digitalRead(DOUTpin2);
  Serial.print("Hydrogen: ");
  Serial.println(value2);
  BTserial.println("Hydrogen Value: ");
  BTserial.println(value2);
  //MQ-2
  value3 = analogRead(AOUTpin3);
  limit3 = digitalRead(DOUTpin3);
  Serial.print("CO2: ");
  Serial.println(value3);
  BTserial.println("CO2: ");
  BTserial.println(value3);
  //MQ-135
  value4 = analogRead(AOUTpin4);
  limit4 = digitalRead(DOUTpin4);
  Serial.print("Ammonia, Sulfide, Benzene: ");
  Serial.println(value4);
  BTserial.println("Ammonia, Sulfide, Benzene: ");
  BTserial.println(value4);
  //MQ-4
  value5 = analogRead(AOUTpin5);
  limit5 = digitalRead(DOUTpin5);
  Serial.print("Methane, Propane, Butane: ");
  Serial.println(value5);
  BTserial.println("Methane, Propane, Butane: ");
  BTserial.println(value5);
  delay(1000);
}
