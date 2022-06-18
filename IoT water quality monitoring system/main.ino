 // blynk update function
 void sendvalue(){ 
  Blynk.virtualWrite(V1, temp() );
  Blynk.virtualWrite(V2, TURBID());
  Blynk.virtualWrite(V3, TDS());
   Blynk.virtualWrite(V4, ph());

//  serial monitor display
  Serial.print(TURBID());
   Serial.println("NTU:");
   Serial.print("Temperature: "); 
  Serial.print(temp());
  Serial.println(" c"); 
  Serial.print("Tds: "); 
  Serial.print(TDS());
  Serial.println("ppm");  
  
  // print on lcd
  lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,0); // set cursor possition
  lcd.print("TEMPERATURE");
    lcd.setCursor(0, 1); // set cursor possition
  // print message
  lcd.print(temp());
  lcd.print ("C");
  delay(3000);

  
 
  }
   /////////////////////////////////////////////////////////////////////////////////////////////////
   //main program exection
void loop() {
  sendvalue(); 
  Blynk.run();
  timer.run();
}
 
