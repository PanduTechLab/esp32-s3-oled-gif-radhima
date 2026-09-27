// ============================================================
//                    PandusTechlab Ccreations
// ============================================================
// YouTube  : https://youtube.com/@pandustechlab?si=7DG_gSCZJBDlr_KW
//
// About PandusTechlab:
// We create Arduino & ESP32 based electronics projects,
// OLED animations, mini games, IoT projects, sensors,
// robotics, DIY circuits and creative embedded systems.
//
// We share project ideas, circuit connections, source code,
// tutorials and experiments to help makers and electronics
// enthusiasts learn and build their own projects.
//
// Follow PandusTechlab for more:
// ✓ Crazy Electronics Projects
// ✓ ESP32 Projects
// ✓ Arduino Projects
// ✓ OLED Animations
// ✓ Mini Games
// ✓ IoT Projects
// ✓ Robotics & Automation
// ✓ Sensors & DIY Electronics
// ✓ Source Code & Tutorials
//
// ============================================================
//
// >>> Adapted for ESP32-S3 + 0.96" SSD1306 OLED (128x64, I2C) <<<
//
// Wiring (ESP32-S3 DevKitC-1 default I2C pins):
//   OLED VCC -> 3V3
//   OLED GND -> GND
//   OLED SDA -> GPIO8
//   OLED SCL -> GPIO9
//
// If your board / breakout uses different pins, just change
// OLED_SDA and OLED_SCL below to match your wiring.
//
// ============================================================

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "animation.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// I2C pins for ESP32-S3 (change these if you wired SDA/SCL differently)
#define OLED_SDA 8
#define OLED_SCL 9

// Most 0.96" SSD1306 modules use I2C address 0x3C.
// Some use 0x3D - change below if the display doesn't turn on.
#define OLED_ADDR 0x3C

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void playGIF(const AnimatedGIF* gif) {
  // Change loop variable to uint16_t to handle >255 frames
  for (uint16_t frame = 0; frame < gif->frame_count; frame++) {
    display.clearDisplay();

    for (uint16_t y = 0; y < gif->height; y++) {
      for (uint16_t x = 0; x < gif->width; x++) {
        uint16_t byteIndex = y * ((gif->width + 7) / 8) + (x / 8);
        uint8_t bitIndex = 7 - (x % 8);

        uint8_t b = pgm_read_byte(&(gif->frames[frame][byteIndex]));

        if (b & (1 << bitIndex)) {
          display.drawPixel(x, y, SSD1306_WHITE);
        }
      }
    }

    display.display();
    delay(gif->delays[frame]);
  }
}

void setup() {
  // ESP32-S3: explicitly start I2C on the chosen SDA/SCL pins
  Wire.begin(OLED_SDA, OLED_SCL);

  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
}

void loop() {
  playGIF(&Radhima_gif);
}


// ============================================================
//                    CONNECT WITH US
// ============================================================
//
// Instagram : @Pandustechlab
// YouTube   : https://youtube.com/@pandustechlab?si=7DG_gSCZJBDlr_KW
//
// Have a doubt about this project?
// Need help with the circuit, code or connections?
//
// Feel free to contact us on Instagram!
// Send us a DM with your question or project doubt.
// We are happy to help and share ideas with fellow makers.
//
// ============================================================
//                 THANK YOU FOR SUPPORTING
//                     Pandustechlab ❤️
// ============================================================
// Learn like an Engineer, Be like an Engineer!
// Keep Creating • Keep Learning • Keep Innovating
//
// More exciting ESP32, Arduino, OLED, IoT, Robotics
// and DIY Electronics projects coming soon!
//
// ============================================================
