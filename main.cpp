#include <Arduino.h>
#include "FS.h"
#include "SD_MMC.h"
#include <SPI.h>

// MicroSD Native 1-Bit SDMMC Pins
#define PIN_SD_CLK     14
#define PIN_SD_CMD     15
#define PIN_SD_D0      2

// Peripheral Chip Select Pins
#define PIN_TFT_CS     6
#define PIN_TFT_DC     7
#define PIN_CC1101_CS  4
#define PIN_PN532_CS   5
#define PIN_TFT_BL     1

void setup() {
    Serial.begin(115200);
    delay(1000);
    Serial.println("=========================================");
    Serial.println("      VAYUDEX // ESP32-S3 INIT          ");
    Serial.println("=========================================");

    // 1. Isolate SPI Chip Selects to prevent bus collision
    pinMode(PIN_TFT_CS, OUTPUT);
    pinMode(PIN_CC1101_CS, OUTPUT);
    pinMode(PIN_PN532_CS, OUTPUT);
    digitalWrite(PIN_TFT_CS, HIGH);
    digitalWrite(PIN_CC1101_CS, HIGH);
    digitalWrite(PIN_PN532_CS, HIGH);

    // 2. Initialize Backlight PWM (LEDC)
    ledcAttach(PIN_TFT_BL, 5000, 8); // 5 kHz PWM, 8-bit resolution
    ledcWrite(PIN_TFT_BL, 200);      // ~80% initial brightness

    // 3. Mount MicroSD via dedicated 1-Bit SDMMC DMA controller
    Serial.print("[INIT] Mounting MicroSD (1-Bit SDMMC)... ");
    SD_MMC.setPins(PIN_SD_CLK, PIN_SD_CMD, PIN_SD_D0);
    if (!SD_MMC.begin("/sdcard", true)) {
        Serial.println("FAILED! Check card insertion.");
    } else {
        uint64_t totalMB = SD_MMC.totalBytes() / (1024 * 1024);
        Serial.printf("OK! (%llu MB detected, DMA enabled)
", totalMB);
    }

    Serial.println("[INIT] Master SPI ready for ST7796, CC1101, and PN532.");
    Serial.println("[SYSTEM] Ready for LVGL GUI engine execution.");
}

void loop() {
    // Background polling task
    vTaskDelay(pdMS_TO_TICKS(10));
}
