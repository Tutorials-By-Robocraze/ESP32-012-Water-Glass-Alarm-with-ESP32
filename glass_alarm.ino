// Final Code for the ESP32 Water Glass Alarm 💧🥤

// This section defines the GPIO pins that are connected to our components.
// Make sure these numbers match your physical wiring.
const int switchPin = 14;  // The pin connected to the microswitch's NO terminal.
const int ledPin = 27;     // The pin connected to the LED's resistor.
const int buzzerPin = 26;  // The pin connected to the active buzzer's positive (+) pin.

// This variable will hold the state of the switch (pressed or not pressed).
int switchState = 0;

void setup() {
  // Initialize Serial Monitor for debugging. You can view messages in the Arduino IDE.
  Serial.begin(115200);

  // Configure the pin modes.
  // The LED and Buzzer are OUTPUTS because the ESP32 sends signals to them.
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // The switch is an INPUT. We use INPUT_PULLUP to activate an internal
  // resistor. This keeps the pin HIGH by default. When the switch is pressed,
  // it connects the pin to GND, pulling its state LOW.
  pinMode(switchPin, INPUT_PULLUP);

  Serial.println("Water Glass Alarm is ready and waiting for a glass!");
}

void loop() {
  // In every loop, read the current state of the switch pin.
  switchState = digitalRead(switchPin);

  // This is the core logic of the alarm.
  // Because we used INPUT_PULLUP, a LOW signal means the switch is pressed.
  if (switchState == LOW) {
    // --- CONDITION: The glass IS on the coaster ---
    // The switch is pressed, connecting GPIO 14 to Ground.
    
    digitalWrite(ledPin, HIGH);   // Turn the confirmation LED ON.
    digitalWrite(buzzerPin, LOW);    // Keep the buzzer silent.
    
  } else {
    // --- CONDITION: The glass IS NOT on the coaster ---
    // The switch is released, and the internal pull-up resistor makes GPIO 14 HIGH.
    
    digitalWrite(ledPin, LOW);     // Turn the LED OFF.
    digitalWrite(buzzerPin, HIGH);   // Sound the alarm!
  }

  // A small delay helps prevent errors from the switch bouncing.
  delay(50); 
}