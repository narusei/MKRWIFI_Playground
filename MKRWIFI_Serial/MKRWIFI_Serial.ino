void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   while (!Serial);
   
   Serial1.begin(9600);

   char sendPacket[4] = "";
   sprintf(sendPacket, "%02x%02x", "00", "01");
   Serial.println(sendPacket);
   Serial.println(Serial.available());
}

void loop() {
  // put your main code here, to run repeatedly:
}
