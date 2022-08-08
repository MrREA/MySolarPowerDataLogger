/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// Global Variables
int ADVoltage = 3300; // in mVolt
int ADResolution = 12; // in Bit
#define VoltageChannel A0;
#define CurrentChannel A1;

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorVoltage = analogRead(VoltageChannel);
  int sensorCurrent = analogRead(CurrentChannel);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  //float voltage = sensorValue * (ADVoltage /(2^ADResolution));
  float voltage = sensorVoltage * 0.8;
  float current = sensorCurrent *0.8;
  // print out the value you read:
  Serial.print(current);
  Serial.println(voltage);
}
