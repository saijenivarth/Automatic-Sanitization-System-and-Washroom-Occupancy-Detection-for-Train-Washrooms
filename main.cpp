 #include <Servo.h>

// PIR Sensor and Ultrasonic Sensor Pins
const int pirPin = 8;   // PIR Sensor pin
const int trigPin = 9;  // Ultrasonic TRIG pin
const int echoPin = 10; // Ultrasonic ECHO pin

// Servo Motor
Servo flushServo;
const int servoPin = 6;

// LED Pin
const int ledPin = 7;  // LED connected to pin 7

// Variables for PIR and Ultrasonic
int pirState = LOW;       // To store PIR sensor state
long duration;            // To store ultrasonic pulse duration
int distance;             // To store calculated distance
bool userDetected = false;
bool isFlushed = false;

void setup() {
  pinMode(pirPin, INPUT);    // Set PIR pin as input
  pinMode(trigPin, OUTPUT);  // Set TRIG pin as output
  pinMode(echoPin, INPUT);   // Set ECHO pin as input
  pinMode(ledPin, OUTPUT);   // Set LED pin as output

  flushServo.attach(servoPin);  // Attach servo to pin
  flushServo.write(0);          // Set servo to initial position (0 degrees)

  Serial.begin(9600);  // Initialize Serial Monitor
}

void loop() {
  // PIR Sensor - Detect Motion
  int motion = digitalRead(pirPin);

  // Ultrasonic Sensor - Measure Distance
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Detect Entry and LED ON
  if (motion == HIGH) {  // PIR detects motion
    pirState = HIGH;
    if (distance <= 5) { // User detected by ultrasonic sensor
      userDetected = true;
      digitalWrite(ledPin, HIGH); // Turn ON LED
      Serial.println("User detected, LED ON.");
    }
  }

  // Detect Exit and Flush
  if (motion == LOW && pirState == HIGH) { // PIR detects no motion
    if (distance > 5 && userDetected) {    // Ultrasonic confirms no proximity
      digitalWrite(ledPin, LOW);           // Turn OFF LED
      Serial.println("User exited, LED OFF. Flushing...");

      flushServo.write(90); // Move servo to 90 degrees to flush
      delay(5000);          // Hold position for 5 seconds
      flushServo.write(0);  // Return servo to initial position

      userDetected = false; // Reset user detection
      isFlushed = true;     // Mark flush as completed
      Serial.println("Flush completed.");
    }
  }

  delay(50); // Short delay for quick responsiveness
}
