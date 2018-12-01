#include <SoftwareSerial.h>

SoftwareSerial bluetoothSerial(5, 6); //RX_PIN, TX_PIN on Arduino

void setup ()
{
  Serial.begin (9600); //Serial baudrate
  Serial.println("Enter AT commands:");
  bluetoothSerial.begin(38400); //HT-05 baudrate
}
void loop ()
{
  // Keep reading from HC-05 and send to Arduino Serial Monitor
  if (bluetoothSerial.available())
    Serial.write(bluetoothSerial.read());

  // Keep reading from Arduino Serial Monitor and send to HC-05
  if (Serial.available())
    bluetoothSerial.write(Serial.read());
}
