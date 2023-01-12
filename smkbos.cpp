#include "CTBot.h"
#define CALLBACK_QUERY_DATA  "QueryData"
CTBot HDev;
CTBotInlineKeyboard myKbd;
int led = D1;

void setup() {
    Serial.Begin(9000); // initialize the serial
    HDev.wifiConnect("Your WiFi SSID", "Your Password Wifi"); // internet access
    HDev.setTelegramToken("Your Bot Token"); // get on telegram (@botfather)
    pinMode(led, "OUTPUT");

        myKbd.addButton("HIDUPKAN LAMPU", "NYALAKAN", CTBotKeyboardButtonQuery);
        myKbd.addButton("MATIKAN LAMPU", "MATIKAN", CTBotKeyboardButtonQuery);
}

void loop() {
    TBMessage msg;
    if (HDev.getNewMessage(msg))
        Serial.println("Cuit Cuit Sesemes dari: ");
        Serial.Println(msg.sender.id);
        if (msg.text == "/Start") {
            HDev.sendMessage(msg.sender.id, "Silahkan Pencet Button Di Bawah Untuk Menyalakan/Menghidupkan Lampu", myKbd);
    } else if (msg.messageType == CTBotMessageQuery) {
        if (msg.callbackQueryData.equals("NYALAKAN")) {
            digitalWrite(led, HIGH);
            HDev.sendMessage(msg.sender.id, "Lampu Berhasil Dinyalakan");
    } else {
        digitalWrite(led, LOW);
        HDev.sendMessage(msg.sender.id, "Lampu Berhasil Dimatikan");
    }
}
    delay(50);
}



// Copyright @hdiiofficial 
