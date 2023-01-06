#include <Arduino.h>
#include <Adafruit_SH1106.h>
#include <Wire.h>

const uint8_t PIN_SPI_RST_RES_RESET = 2;
const uint8_t PIN_SPI_DC = 4;
const uint8_t PIN_SPI_CS_SS = 15;
const uint8_t PIN_SPI_SDA_SDI_DARA_IN_MOSI = 13;
const uint8_t PIN_SPI_SDO_DATA_OUT_MISO = 12;
const uint8_t PIN_SPI_SCK_CLK_SCL_SCLK = 14;
const uint8_t PIN_I2C_SDA = 21; // Used for SH1106
const uint8_t PIN_I2C_SCL = 22; // Used for SH1106
const uint8_t PIN_UART_TX = 17;
const uint8_t PIN_UART_RX = 16;

const uint8_t DISPLAY_ADDRESS = 0x3C;
//const uint8_t DISPLAY_ADDRESS = 0x3D;
const uint8_t DISPLAY_RESET = 4;

Adafruit_SH1106 display(DISPLAY_RESET);

TaskHandle_t Task1;
TaskHandle_t Task2;

void setupDisplay() {
    Wire.begin(PIN_I2C_SDA, PIN_I2C_SCL);
    display.begin(SH1106_SWITCHCAPVCC, DISPLAY_ADDRESS);
    display.setRotation(0);
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.clearDisplay();
    display.setCursor(50, 30);
    display.println("Start");
    display.display();
}

void task1(void *pvParameters) {
    while (true) {

    }
}

void task2(void *pvParameters) {
    while (true) {

    }
}

void setupTasks() {
    xTaskCreatePinnedToCore(
            task1,
            "task1",
            50000,
            NULL,
            1,
            &Task1,
            0);
    xTaskCreatePinnedToCore(
            task2,
            "task2",
            50000,
            NULL,
            1,
            &Task2,
            1);
}

void setup() {
    setupDisplay();
//    setupTasks();
}

void loop() {
// write your code here
}