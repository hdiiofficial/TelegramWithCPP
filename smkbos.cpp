#include "CTBot.h"
CTBot HDev;

void setup() {
    Serial.Begin(9000); // initialize the serial
    HDev.wifiConnect("Your WiFi SSID", "Your Password Wifi"); // internet access
    HDev.setTelegramToken("Your Bot Token"); // get on telegram (@botfather)
}

void loop() {
    TBMessage msg;
    if (HDev.getNewMessage(msg))
        Serial.println("Cuit Cuit Sesemes dari: ");
        Serial.Println(msg.sender.id);
        HDev.sendMessage(msg.sender.id, "Hello");
    delay(50);
}
