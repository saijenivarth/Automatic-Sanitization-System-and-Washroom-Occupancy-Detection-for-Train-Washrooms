#About
 Maintaining hygiene in train washrooms is a critical challenge due to their confined spaces, frequent use, and limited ventilation. Traditional manual cleaning and flushing methods are often insufficient to ensure consistent cleanliness, resulting in discomfort and health risks for passengers. This project proposes an Automatic Sanitization and Washroom Occupancy Detection System designed specifically for train washrooms. By leveraging sensor-based automation, the system improves hygiene standards, reduces manual intervention, and optimizes resource usage.

The system integrates PIR sensors for motion detection and ultrasonic sensors for proximity detection, ensuring reliable identification of user presence and exit. An LED light remains ON while a user is detected and turns OFF only after the person has exited the washroom. A servo motor automates the flushing mechanism, activating immediately upon user exit and holding for 5 seconds before resetting. The implementation prioritizes real-time detection accuracy, eliminating false triggers and ensuring effective flushing with minimal resource wastage.


#Problem Statement
Train washrooms are among the most frequently used public facilities, often with confined spaces and limited ventilation. The high frequency of use creates significant hygiene challenges, with traditional manual cleaning and flushing methods proving to be insufficient. Inadequate hygiene in such environments can lead to the spread of diseases, passenger discomfort, and resource wastage. There is a pressing need for an automated system that ensures cleanliness, prevents contamination, and conserves resources in train washrooms.

#3   Requirements Specification	
3.1 Hardware Requirements
1.	Microcontroller:
•	Arduino Uno:
Used as the primary control unit to process sensor inputs and control the LED and servo motor.
2.	Sensors:
•	PIR Sensor:
Detects motion to identify user entry and exit.
•	Ultrasonic Sensor (HC-SR04):
Measures proximity to detect the user's presence within 5 cm of the washroom facilities.
3.	Actuator:
•	Servo Motor:
Controls the flushing mechanism by activating the flush handle or valve for 5 seconds after user exit.
4.	Indicators:
•	LED with Resistor (220Ω):
Indicates washroom occupancy status. LED remains ON while the washroom is occupied and turns OFF after the user exits.
5.	Power Supply:
•	5V Power Supply:
Provides power to the Arduino, sensors, and LED. An external power source may be required for the servo motor to ensure stable operation.
6.	Other Components:
•	Jumper Wires and Breadboard: For circuit connections and prototyping.
•	Chassis or Enclosure: To house and protect the components.
