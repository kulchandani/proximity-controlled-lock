# proximity-controlled-lock
lock that gets triggered if ultrasonic sensor detects an object within a range<br>detection is done by measuring total time taken for a sound wave to return
 (in microseconds)<br><br>

 **V1:** first stage of development, simple circuit setup

 components-
 - 1x HC-SR04 ultrasonic sensor
 - 1x SG-90 servo <br><br>
 <img width="1408" height="839" alt="image" src="https://github.com/user-attachments/assets/1e84b815-b053-4275-b4e9-c8b14dbdab39" /><br>
 
notes-
- works properly
- direct power can be erratic, will need an external power supply module
- need to figure out proper build
- look into other, more powerful servos<br><br>

**2. V2:** using stronger servo, esp32 microcontroller, and external power source

components- 
- MG995 servo
- 25T aluminium servo arm
- HC-SR04 ultrasonic sensor
- ESP32 microcontroller
- 1k resistor
- 2k resistor
- 4x AA batteries
- battery holder (4xAA) with on/off switch and connecting wires<br><br>

diagram not possible, connection list:

ESP32 groun pin creating a ground line on breadboard

- BATTERY PACK negative line connects to ground line
- BATTERY PACK power line connects to HC-SR04 VCC pin

- HC-SR04 gnd pin connects to ground line
- HC-SR04 trig pin connects to ESP32 D5 pin
- HC-SR04 echo pin connects to 1k resistor - which connects to 2k resistor
- END of 2k resistor connects to ground line
- JUNCTION of 1k and 2k resistors connects to ESP32 D18 pin

- SERVO ground wire connects to ground line
- SERVO power wire connects to BATTERY PACK power line
- SERVO signal wire connects to ESP32 D19 pin

- ALUMINIUM ARM is attached to servo<br><br>

notes-
- works fine
- longer delay helps iron out jittery behavior
- pulse delay removed, not effective at avoiding repeat triggers
- instead, used state-based logic
- need to start designing arm
- need to work on esp-now for wireless communication between two microcontrollers
- need to make a more compact build on a prototyping board
