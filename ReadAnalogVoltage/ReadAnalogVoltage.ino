/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/

// Include Libraries


// Global Variables
int ADVoltage = 3300; // in mVolt
int ADResolution = 12; // in Bit
int sensorVoltage = 0;
int sensorCurrent = 0;
float voltage = 0;
float current = 0;
float power = 0;

#define VoltageChannel A0
#define CurrentChannel A3

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(115200);
}

void dataLogger(){
  // Put all the Logginf information in place
  // read the input on analog pin 0:
  sensorVoltage = analogRead(VoltageChannel);
  sensorCurrent = analogRead(CurrentChannel);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  voltage = sensorVoltage * 0.8;
  current = sensorCurrent *0.8;
  power = voltage * current;
}


// the loop routine runs over and over again forever:
void loop() {
  // Log the data
  dataLogger();

  // print out the value you read:
  Serial.print("Current: ");
  Serial.print(current);
  Serial.print("mA Voltage: ");
  Serial.print(voltage);
  Serial.print("mV Power: ");
  Serial.println(power);
}
