

  uint8_t cursor_pos_state = 0;
  uint8_t cursor_pos_y[] = {25};
  
  static void menu_init(){
    display.clearDisplay();
    display.setTextSize(2);
    display.setTextColor(WHITE);
  
    display.setCursor(12, 0);
    display.println(F("DINO BOY!"));
  
    display.setTextSize(1);
    display.setCursor(92, 25);
    display.println(F("By:"));
    display.setCursor(92, 35);
    display.println(F("Ziddy"));
    display.setCursor(92, 45);
    display.println(F("Makes"));

    display.setCursor(30, 25);
    display.println(F("PLAY"));


    display.setCursor(20, 40);
    display.println(F("Highscore:"));
    display.setCursor(20, 50);
    display.println(highscore);

    
    
     /*display.setCursor(10, 25);
    display.println(F("Pong Game"));
    display.setCursor(10, 35);
    display.println(F("Dino Game"));
    display.setCursor(4, 45);
    display.println(F("Space Game"));
    display.setCursor(22, 55);
    display.println(F("QR Code"));*/
    
    
  }

  static void menu_display(){
    display.setTextSize(1);
    display.drawChar(55, cursor_pos_y[cursor_pos_state], '<', WHITE, 0, 1);
    display.display();
    
  }

  static void menu_input_handle(){//(bool LS, bool RS, bool L, bool R){
    if(right_button_state){
      display.clearDisplay();
      delay(100);  
      STATE = cursor_pos_state+1;
    } else if (left_button_state){
      cursor_pos_state++;
      if(cursor_pos_state > 3){
        cursor_pos_state = 0;
      } 
      display.clearDisplay();
      delay(100);  
    }
  }
