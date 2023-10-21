void panels_dev(){
    //int boxes[4] = {0, 0, 10, 10};
    int panel_1[4] = {5, 17, 20, 20};
    int panel_2[4] = {35, 17, 20, 20};
    int panel_3[4] = {65, 17, 20, 20};
    int panel_4[4] = {95, 17, 20, 20};
 
    int panel_5[4] = {5, 42, 20, 20};
    int panel_6[4] = {35, 42, 20, 20};
    int panel_7[4] = {65, 42, 20, 20};
    int panel_8[4] = {95, 42, 20, 20};

    int RoundRadius = 7;

    //display.drawRect(boxes[0], boxes[1], boxes[2], boxes[3], 1);
    display.drawRoundRect(panel_1[0], panel_1[1], panel_1[2], panel_1[3],RoundRadius, 1);
    display.drawRoundRect(panel_2[0], panel_2[1], panel_2[2], panel_2[3],RoundRadius, 1);
    display.drawRoundRect(panel_3[0], panel_3[1], panel_3[2], panel_3[3],RoundRadius, 1);
    display.drawRoundRect(panel_4[0], panel_4[1], panel_4[2], panel_4[3],RoundRadius, 1);
    
    display.drawRoundRect(panel_5[0], panel_5[1], panel_5[2], panel_5[3],5, 1);
    display.drawRoundRect(panel_6[0], panel_6[1], panel_6[2], panel_6[3],5, 1);
    display.drawRoundRect(panel_7[0], panel_7[1], panel_7[2], panel_7[3],5, 1);
    display.drawRoundRect(panel_8[0], panel_8[1], panel_8[2], panel_8[3],5, 1);
    display.display();

}

void display_out() {

  if (akt_mil >= ziel_mil) {
    ziel_mil = akt_mil + delay_display;
    //Serial.print("t");
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setTextSize(2);
    display.setCursor(2, 30);
    display.print(buttonState2);
    display.setCursor(30, 2);
    display.setTextSize(0);
    display.print(akt_mil);
    display.print(".  .");
    frameNr++;
    display.print(frameNr);
    /*display.setCursor(2, 18);
    display.print("whilePress?:");
    display.print(whilePress);
    display.print(" ");
    display.print(press_dauer);*/
    panels_dev();
    display.display();
  }
}
