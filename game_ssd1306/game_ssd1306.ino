
/*
  A simple Pong game:
*/

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <avr/pgmspace.h>
#include <math.h>
#include <EEPROM.h>

#define LEFT_SHOULDER_BUTTON A1
#define RIGHT_SHOULDER_BUTTON A2
#define LEFT_BUTTON 5
#define RIGHT_BUTTON 7
#define VBATPIN A6

static bool left_shoulder_button_state = false;
static bool right_shoulder_button_state = false;
static bool left_button_state = false;
static bool right_button_state = false;

uint16_t highscore = 0;

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void drawCourt();


uint8_t STATE = 0;
bool first = true;

unsigned long elaspedTime = millis();

void setup() {
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  getHighscore();

  display.display();


  pinMode(LEFT_BUTTON, INPUT_PULLUP);
  pinMode(RIGHT_BUTTON, INPUT_PULLUP);

  display.clearDisplay();
  // drawCourt();

  while (millis() - elaspedTime < 100);

  display.display();

  resetHighscore();

}

void loop() {
  bool update = false;
  elaspedTime = millis();

  left_shoulder_button_state = false;
  right_shoulder_button_state = false;
  left_button_state = false;
  right_button_state = false;

  left_button_state |= (digitalRead(LEFT_BUTTON) == LOW);
  right_button_state |= (digitalRead(RIGHT_BUTTON) == LOW);


  if (STATE == 0) {
    menu_init();
    menu_display();
    menu_input_handle();
  } else if (STATE == 1) {
    dino_game_display();
    dino_game_input_handle();
  } else if (STATE == 2) {
    dino_game_display();
    dino_game_input_handle();
  } else if (STATE == 3) {
    dino_game_display();
    dino_game_input_handle();
  } else if (STATE == 4) {
    //QR_code_page_display();
    //QR_code_page_input_handle();
    dino_game_display();
    dino_game_input_handle();
  }

}

void resetHighscore(){
  EEPROM.write(0, (uint16_t) 0);
}

void getHighscore() {
  EEPROM.get(0, highscore);
}

void updateHighscore(uint16_t currentRunScore) {
  if (currentRunScore > highscore) {
    EEPROM.write(0, currentRunScore);
    highscore = currentRunScore;
  }
}

void drawCourt() {
  display.drawRect(0, 0, 128, 64, WHITE);
}
