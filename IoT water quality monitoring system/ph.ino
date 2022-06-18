// note this ph values are not accurate,it is a demo that uses other tds values for its calculation
// you can comment it out if you are not interested
int ph(){
  double pH;
 
  int PHv = TDS();
     
 
   
   if (PHv <=300 ){
    pH = map(PHv, 0,300,  6 , 7.5);
  
  } 

       else if (PHv >= 1501) {
    pH = map(PHv, 1501,6000,  5.9 , 0);
  
  } 
  
     else if (PHv >=301 && PHv  <= 1500){
    pH = map(PHv, 301,1500,  7.6, 14);
  
  } 

    
  lcd.clear();
  // set cursor to first column, second row
  lcd.setCursor(0,0);
  lcd.print("pH");
    lcd.setCursor(0, 1);
  // print message
  lcd.print(pH); 
  delay(3000);

  return pH;
  
  }
