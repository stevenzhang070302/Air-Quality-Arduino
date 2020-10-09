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

![Wiring_Diagram](https://lh3.googleusercontent.com/Jjp_cTEuAw5aX366ZqYGpybXrH-67-lAyqVje-vN_xGWLm6asoK9RkouWkbFYRTBOUU4y220EJtAMMO8HEyfXCCTo2lSc6qVPqJ80cb0vF3X8WgIXGU63moIwrO02Y1lCFj6vXRbD_jVfrO8_7acDlAP3CR18bg1XJmaeeLMyU_qwDqB_H4DwAuBHV9a-TpJukKLOT50FySv0HqSrJpsaxEVHKH2q3QJMiChyR2abnz9U5Jy8B6F2K50DTzvgi8cwd7mthbzgNNy30Ddx4h-GYC29qWHbGHMgPCUBJZv9f1LWCReWavE_EV3MuJim_FsM8Ra9-IJdtdhOmhAOG2LDGi82UIRHSlPcClFAkgH5ssh25_8cE6Da41Mrro-Pa14a17-uDo-nlCtvH3gbgh6OiAulNq1Bh5dGPr5DjQnv_qGvswMW0pvGhZgq8_SQL-KklliViiDlne5cqYthVUzlXjSbmjf0lXdIdwZN4d1AXgym2p_8Sp24CXjiggmYzokSd10nhwXsGw2dYSBYyIvmyZtGMtruZYaAdhGB5aCPm3lFCz3DAybe4kLTwYQfvmNVw3GmnooM1wxLhGVNQN7yz5WPHGw1itqcMiN0OYN7lrPabB8rgrAlflC01iQFnEHCTetcc1zusQ65xSl41hM2DyZziOYrv-6_A1apeV7odLybqB36tZcjvt7V46otg=w574-h379-no?authuser=0)

![Arduino_Setup](https://lh3.googleusercontent.com/1DBpftFq3inRmMBGgmSWflBoi9tQxH4pHRPuD1bEQsUuPfOvjZKIn7PK7szePEELgbd2kpx_JdRnVAPNv7uFG_B5h6EOAPeOfe5EJDv3My98DbIjMZ1cUdv5pXxh9IZGA6rDMxXPiZDC11FuvKkr0BxHxpQu6tMyfsvdJjJA7GZQ5PKjhYh94KkKlS717fFF9FuJ9x3CLH80TcSCC1TSEoM2_Q2JfBamU670kHLnH-pnJ_R2dok4wzPq3nv0lrLRHcwsLUH4IVF5daqqrCVdNfj4AkEuJw27na4Ao9ZDDX9HpaLhlZzoEQRZCjigoR-4a-YwdNY8g2ypCBvI8_Nbs3cSuJzRNS_jgEY68o4bqrEexZ0EJcFtSnW7jbf_HzCF1u9IJSCjHNQfymdCsDs4dhJxCJsIsVHqdk_RuCLeD_DYbSem9Yo_B4ok9wGHwtJIVxrFu_ywJVnFWzjI5Exhf2DedB0lQeVOjuS23MgX4p3Uj8GbJ08DRKET4E5dgnUmHLPkKOy7ePevTOW2ZzN_PKhyw9keHQZi0eDJ5rgkKc3hTtduab0gc1hUf6JqEnJAOTYAaG4zHh7Wl3RPZP5gxBpTGxOiy6bsBPRD9YAdwaTEPn6fq7eEO9aza8avOAlCAWZ_NbRfEktgU2Tfo5ucMUEFlOU-8qOio1AV25a-dYQJPmMHB6XaCfxtLIv6SA=w1350-h760-no?authuser=0)

![Sample_Output](https://lh3.googleusercontent.com/0LXs8d250mqgBz_axvkPTbBL7z27birbNTs_vDIn-M75HzFK2fKSI26p4rMc4bz8Z7Yz7_VLFm-d9ydRIMBwywyy-tsfa_V3cXMXwau2qgl4bM9CM-TNbg2Ae4QffuSZdIlUmgrKJl5CJP7c-nD-tvRfksfeEK5tC3JBKfHmgmykHuVWT6Z37tdV9SMmQbbTaLTtDFSd24vwQWUpr595ubWAZ-ZPUBF4vt8dJVu0cwCYmueOf5eLW-o4yQUSi47gJFlR6O2E8MBvQ24dmZDwMYBY-8bXt1bsuHaM25fbxMScmD5gCNp6eyZRSi9-Fz2kEAxI15CSVJNneB2OdaeATN7-SKedXMXYMOPkJB6aqpXaXMtItNVIdY8dqmw8hlLDIXBNhE4m1D7GS2MYQHTX70o9BIGbVbmci_S6IDVrXjCITa1g8JOTwb0pCgF-aQZ2BrsBajMD3g8178IhgQWjahbpA6kfYrE6KgvInP7D3kRRbU96Yh62P5gldyxHnP9k6-crehBGHAGWhIj-ROUxu8EeYlAY28RuJ_UHAILQM-I5980C0E4_8h9VWpBKxrVaen9GmSQUDsXrrLtGr-TWCkFIC_zzE6QgFAsgpxfZs_pYd7wse0IYJ5zXgTnHtd3Nf9RvOvZwdJFv_gNX_zElGKZN5v44y1AROYn9CscyD5LoXc8iLp6eiPucU0iwyA=w619-h825-no?authuser=0)
