#include "CTBot.h"
#define CALLBACK_QUERY_DATA  "QueryData"
CTBot HDev;
CTBotInlineKeyboard myKbd;
int led = D1;
int lamp = D2;

void setup() {
    Serial.Begin(9000); // initialize the serial
    HDev.wifiConnect("Your WiFi SSID", "Your Password Wifi"); // internet access
    HDev.setTelegramToken("Your Bot Token"); // get on telegram (@botfather)
    pinMode(led, "OUTPUT");
    pinMode(lamp, "OUTPUT");

        myKbd.addButton("HIDUPKAN LAMPU 1", "NYALAKAN1", CTBotKeyboardButtonQuery);
        myKbd.addButton("HIDUPKAN LAMPU 2", "NYALAKAN2", CTBotKeyboardButtonQuery);
        myKbd.addButton("MATIKAN LAMPU 1", "MATIKAN1", CTBotKeyboardButtonQuery);
        myKbd.addButton("MATIKAN LAMPU 2", "MATIKAN2", CTBotKeyboardButtonQuery);
}

void loop() {
    TBMessage msg;
    if (HDev.getNewMessage(msg))
        Serial.println("Cuit Cuit Sesemes dari: ");
        Serial.Println(msg.sender.id);
        if (msg.text == "/Start") {
            HDev.sendMessage(msg.sender.id, "Silahkan Pencet Button Di Bawah Untuk Menyalakan/Menghidupkan Lampu", myKbd);
    } else if (msg.messageType == CTBotMessageQuery) {
        if (msg.callbackQueryData.equals("NYALAKAN1")) {
            digitalWrite(led, HIGH);
            HDev.sendMessage(msg.sender.id, "Lampu 1 Berhasil Dinyalakan");
    } else if (msg.callbackQueryData.equals("NYALAKAN2")) {
                digitalWrite(lamp, HIGH);
                HDev.sendMessage(msg.sender.id, "Lampu 2 Berhasil Dinyalakan");
    } else if (msg.callbackQueryData.equals("MATIKAN1")) {
                digitalWrite(led, LOW);
                HDev.sendMessage(msg.sender.id, "Lampu 1 Berhasil Dimatikan");
    } else if (msg.callbackQueryData.equals("MATIKAN2")) {
                digitalWrite(lamp, LOW);
                HDev.sendMessage(msg.sender.id, "Lampu 2 Berhasil Dimatikan");
    }
}
    delay(50);
}



// Copyright @hdiiofficial 
// Ini jangan di hapus bang 
// Don't remove this bro 
// Copy paste gaush hapus hapus copyright
// If just rewrite or copy and paste don't remove my copyright
// Kalo lu mau yg gada copyright ku ya mikir sendiri 
// If you want write without my copyright please read the docs and use your brain LoL.
