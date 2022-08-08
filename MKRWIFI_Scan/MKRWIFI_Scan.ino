/*
  Scan

  This example scans for Bluetooth® Low Energy peripherals and prints out their advertising details:
  address, local name, advertised service UUID's.

  The circuit:
  - Arduino MKR WiFi 1010, Arduino Uno WiFi Rev2 board, Arduino Nano 33 IoT,
    Arduino Nano 33 BLE, or Arduino Nano 33 BLE Sense board.

  This example code is in the public domain.
*/

#include <ArduinoBLE.h>

#define _DEBUG_

void setup() {
  #ifdef _DEBUG_ 
    Serial.begin(9600);
    while (!Serial);
  #endif

  // begin initialization
  if (!BLE.begin()) {
    while (1);
  }
  // start scanning for peripheral
  BLE.scan();
}

void loop() {
  BLEDevice peripheral = BLE.available();

  if (peripheral) {
    if (peripheral.hasAdvertisementData()) {
      int advLen = peripheral.advertisementDataLength();
      int prssi = peripheral.rssi();
      if (advLen == 6) {
        uint8_t advData[advLen];
        peripheral.advertisementData(advData, advLen);

        if (advData[1] == 22 && advData[2] == 7 && advData[3] == 17) {
          char sendPacket[4] = "";
          sprintf(sendPacket, "%02x%02x", advData[4], advData[5]);
          #ifdef _DEBUG_
            Serial.print(sendPacket);
            Serial.print(" ");
            Serial.println(prssi);
          #endif
        }
      }
    }
  }
}
