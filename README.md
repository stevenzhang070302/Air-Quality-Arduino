# Air-Quality-Arduino-Data-Collection
IoT Project under Vdart Digital

Authors:
- Steven Zhang^[Georgia Institute of Technology, stevenzhang070302@gmail.com]
- Gowrav Thota^[Georgia Institute of Technology, gtthota@gmail.com]

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

* There may be a bug where you have to reset the arduino module to retake PM data...
* Starred sensors are not on the diagram and need to be wired according to the pins specified above and also wired with (both) GND connected to the Negative Power strip and VCC connected to the Positive Power strip on the edge of the breadboard(Also make sure GND from the arduino powers the Negative Power strip and 5V/3.3V powers the Positive Power strip).
Diagrams:(These diagrams show a relative way to connect the sensors; please follow the specifications above to accommodate the code.)

![Wiring_Diagram](https://github.com/stevenzhang070302/Air-Quality-Arduino/blob/master/wiring_diagram.PNG?raw=true)

![Arduino_Setup](https://github.com/stevenzhang070302/Air-Quality-Arduino/blob/master/arduinoImage1.jpg?raw=true)

![Sample_Output](https://github.com/stevenzhang070302/Air-Quality-Arduino/blob/master/arduinoData1.jpg?raw=true)

# Instructions
* The necessary code to run the project should be in the Arduino-mega folder
* The file PMSensor3.ino contains the code for the PM sensor as you would attach it to another arduino uno board instead, due to inaccuracies when reading values with the rest of the other sensors on the arduino mega.
* The file AirArduino.ino refers to using the arduino mega board as all the sensors will be used. The only missing sensor is the PM sensor due to errors as it will be also be posted in the same folder but will need to be uploaded to a different board, arduino uno board.
* To run the code, download the Arduino IDE and this repository. After wiring, connect the arduino to the usb port of a computer. Open and click run on either the AirArduino.ino file or the PMSensor3.ino file from this repository. 


