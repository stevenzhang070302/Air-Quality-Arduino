# Air-Quality-Arduino-Data-Collection
Project under Vdart Digital

# Objective: 
The purpose is to implement fundamentals of Smart City technology into the field of urban air pollution. By implementing an air monitor in urban areas, this device can display the relative values of the air quality in the area ultimately determining whether the air is safe or polluted. The main focus would be allowing the citizens of Tiruchirappalli, India to benefit from this technology as much as possible.

# Pollutants Measured:
This air quality IoT device measures for the following gases:
* Carbon Monoxide: Resistance/Ohms
* Alcohol/Ethane: Resistance/Ohms
* Hydrogen Gas: Resistance/Ohms
* Methane: Resistance/Ohms
* Propane/Butane: Resistance/Ohms
* Smoke/Flammable Gas: Resistance/Ohms
* Ozone: PPM
* Particulate Matter 2.5 and 10: Microns per 0.1 L of air
* Temperature and Humidity: Fahrenheit and Celcius and % Humidity
* Carbon Dioxide: PPM

# Items:
* Air Sensors(MQ-2, MQ-3, MQ-4, MQ-7, MQ-8, MQ-9, MQ-135, Temperature/Humitdity Arduino Sensor
* Particulate Matter 2.5 and 10 Sensor, Ozone Sensor)
* Arduino Mega
* Male/Male Jumper Wires
* 220 Ohm Resistors
* Breadboards
* Bluetooth Module
* Batter Holders

# Circuit Diagram:
Pins to connect to on Device 1:
* (MQ-7: Digital 8, Analog 0)
* (MQ-3: Digital 7, Analog 1)
* (MQ-8: Digital 6, Analog 2)
* (MQ-2: Digital 5, Analog 3)
* (MQ-135: Digital 4, Analog 4)
* (MQ-4: Digital 3, Analog 5)
* (Bluetooth: Digital 9 and 10)

Pins to connect to on Device 2:
* (DHT-22(With Resistor): Digital 11)
* (MQ-131: Digital 2, Analog 6)
* (***PMS5003: Connect TXD to Digital 2 on another Arduino Uno board***)

There may be a bug where you have to reset the arduino module to retake PM data...
Starred sensors are not on the diagram and need to be wired according to the pins specified above and also wired with (both) GND connected to the Negative Power strip and VCC connected to the Positive Power strip on the edge of the breadboard(Also make sure GND from the arduino powers the Negative Power strip and 5V/3.3V powers the Positive Power strip).
Diagrams:(These diagrams show a relative way to connect the sensors; please follow the specifications above to accommodate the code.)

![Wiring_Diagram](https://lh3.googleusercontent.com/1DBpftFq3inRmMBGgmSWflBoi9tQxH4pHRPuD1bEQsUuPfOvjZKIn7PK7szePEELgbd2kpx_JdRnVAPNv7uFG_B5h6EOAPeOfe5EJDv3My98DbIjMZ1cUdv5pXxh9IZGA6rDMxXPiZDC11FuvKkr0BxHxpQu6tMyfsvdJjJA7GZQ5PKjhYh94KkKlS717fFF9FuJ9x3CLH80TcSCC1TSEoM2_Q2JfBamU670kHLnH-pnJ_R2dok4wzPq3nv0lrLRHcwsLUH4IVF5daqqrCVdNfj4AkEuJw27na4Ao9ZDDX9HpaLhlZzoEQRZCjigoR-4a-YwdNY8g2ypCBvI8_Nbs3cSuJzRNS_jgEY68o4bqrEexZ0EJcFtSnW7jbf_HzCF1u9IJSCjHNQfymdCsDs4dhJxCJsIsVHqdk_RuCLeD_DYbSem9Yo_B4ok9wGHwtJIVxrFu_ywJVnFWzjI5Exhf2DedB0lQeVOjuS23MgX4p3Uj8GbJ08DRKET4E5dgnUmHLPkKOy7ePevTOW2ZzN_PKhyw9keHQZi0eDJ5rgkKc3hTtduab0gc1hUf6JqEnJAOTYAaG4zHh7Wl3RPZP5gxBpTGxOiy6bsBPRD9YAdwaTEPn6fq7eEO9aza8avOAlCAWZ_NbRfEktgU2Tfo5ucMUEFlOU-8qOio1AV25a-dYQJPmMHB6XaCfxtLIv6SA=w1350-h760-no?authuser=0)

