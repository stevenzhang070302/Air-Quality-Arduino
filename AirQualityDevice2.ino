#include "DHT.h"
#define DHTPIN 2     
#define DHTTYPE DHT22   
#include "MQ131.h"
#include <SoftwareSerial.h>
SoftwareSerial pmsSerial(3, 4);

MQ131 sensor(9,A0, LOW_CONCENTRATION, 10000);

DHT dht(DHTPIN, DHTTYPE);
int sensorValue;

void setup() {
  
  Serial.begin(9600);
  pmsSerial.begin(9600);
  dht.begin();
  
  Serial.println("Air Quality Sensors are starting up...");
  //Serial.print("R0 for Ozone Sensor = ");
  //Serial.print(sensor.getR0());
  //Serial.println(" Ohms");
  Serial.print("Please wait ");
  Serial.print("for a few");
  //Serial.print(sensor.getTimeToRead());
  Serial.println(" seconds for the sensors to heat up...");
  Serial.println("");
  delay("5000");
  
}

struct pms5003data {
  uint16_t framelen;
  uint16_t pm10_standard, pm25_standard, pm100_standard;
  uint16_t pm10_env, pm25_env, pm100_env;
  uint16_t particles_03um, particles_05um, particles_10um, particles_25um, particles_50um, particles_100um;
  uint16_t unused;
  uint16_t checksum;
};
 
struct pms5003data data;



void loop() {
 delay(1000);
 //sensor.begin();
  Serial.println("Ozone Sensor: ");
  Serial.print("O3 Value: ");
  
  sensorValue = analogRead(0);       // read analog input pin 0
  Serial.println(sensorValue);  // prints the value read
  Serial.println("");
  Serial.print("Concentration O3 Value: ");
  Serial.print(sensor.getO3(PPM));
  Serial.println(" ppm");
  Serial.print("Concentration O3 : ");
  Serial.print(sensor.getO3(PPB));
  Serial.println(" ppb");
  Serial.print("Concentration O3 : ");
  Serial.print(sensor.getO3(MG_M3));
  Serial.println(" mg/m3");
  Serial.print("Concentration O3 : ");
  Serial.print(sensor.getO3(UG_M3));
  Serial.println(" ug/m3");
  Serial.println();
  delay(2000);  

  
float h = dht.readHumidity();
  float t = dht.readTemperature();
  float f = dht.readTemperature(true);

  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read the Temperature/Humidity sensor!");
    return;
  }

  float hif = dht.computeHeatIndex(f, h);
  float hic = dht.computeHeatIndex(t, h, false);
  Serial.println("Temperature and humidity sensor: ");
  Serial.print("Humidity: ");
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(t);
  Serial.print(" *C   ");
  Serial.print(f);
  Serial.print(" *F ");
  Serial.print(" \t");
  Serial.print("Heat index: ");
  Serial.print(hic);
  Serial.print(" *C   ");
  Serial.print(hif);
  Serial.println(" *F");
  Serial.println("");
 
  float COMethaneValue;

    COMethaneValue = analogRead(A3);
   
    Serial.println("CO/Methane Sensor: ");
    Serial.print("CO and Methane Value = ");
    Serial.println(COMethaneValue);
    delay(1000);
    Serial.println();
    
    Serial.println("Please wait until the Particulate Matter Sensor outputs a value...");
    Serial.println("");
    delay(10000);
  if (readPMSdata(&pmsSerial)) 
  {
    // reading data was successful!
    
    Serial.println("Particulate Matter Sensor: ");
    Serial.println("Concentration Units (standard)");
    Serial.print("PM 1.0: "); Serial.print(data.pm10_standard);
    Serial.print("\t\tPM 2.5: "); Serial.print(data.pm25_standard);
    Serial.print("\t\tPM 10: "); Serial.println(data.pm100_standard);
    Serial.println();
    Serial.println("Concentration Units (environmental)");
    Serial.print("PM 1.0: "); Serial.print(data.pm10_env);
    Serial.print("\t\tPM 2.5: "); Serial.print(data.pm25_env);
    Serial.print("\t\tPM 10: "); Serial.println(data.pm100_env);
    Serial.println();
    Serial.print("Particles > 0.3um / 0.1L air:"); Serial.println(data.particles_03um);
    Serial.print("Particles > 0.5um / 0.1L air:"); Serial.println(data.particles_05um);
    Serial.print("Particles > 1.0um / 0.1L air:"); Serial.println(data.particles_10um);
    Serial.print("Particles > 2.5um / 0.1L air:"); Serial.println(data.particles_25um);
    Serial.print("Particles > 5.0um / 0.1L air:"); Serial.println(data.particles_50um);
    Serial.print("Particles > 10.0 um / 0.1L air:"); Serial.println(data.particles_100um);
    Serial.println();
} 
    Serial.println("Waiting for sensors to take data... ");
    Serial.println("Please wait for sensors to retake new data...");
    Serial.println("");
    delay(5000);
}

boolean readPMSdata(Stream *s) {
  if (! s->available()) {
    return false;
  }
  
  // Read a byte at a time until we get to the special '0x42' start-byte
  if (s->peek() != 0x42) {
    s->read();
    return false;
  }
 
  // Now read all 32 bytes
  if (s->available() < 32) {
    return false;
  }
    
  uint8_t buffer[32];    
  uint16_t sum = 0;
  s->readBytes(buffer, 32);
 
  // get checksum ready
  for (uint8_t i=0; i<30; i++) {
    sum += buffer[i];
  }
 
  /* debugging
  for (uint8_t i=2; i<32; i++) {
    Serial.print("0x"); Serial.print(buffer[i], HEX); Serial.print(", ");
  }
  Serial.println();
 */ 
  
  // The data comes in endian'd, this solves it so it works on all platforms
  uint16_t buffer_u16[15];
  for (uint8_t i=0; i<15; i++) {
    buffer_u16[i] = buffer[2 + i*2 + 1];
    buffer_u16[i] += (buffer[2 + i*2] << 8);
  }
 
  // put it into a nice struct :)
  memcpy((void *)&data, (void *)buffer_u16, 30);
 
  if (sum != data.checksum) {
    Serial.println("Particulate Matter sensor was unable to take data...Please wait...");
    Serial.println();
    return false;
  }
  // success!
  return true;
} 
