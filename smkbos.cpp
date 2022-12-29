#include "CTBot.h"
CTBot HDev;

void setup() {
    Serial.Begin(9000);
    HDev.wifiConnect("Your WiFi SSID", "Your Password Wifi");
    HDev.setTelegramToken("Your Bot Token");
}

void loop() {
    TBMessage msg;
    if (HDev.getNewMessage(msg))
        Serial.println("Cuit Cuit Sesemes dari: ");
        Serial.Println(msg.sender.id);
        HDev.sendMessage(msg.sender.id, "Hello");
    delay(50);
}
