 
 int temp(){
  int Vo;
 float R1 = 1000 ;
float logR2, R2, T;
float c1 = 1.009249522e-03, c2 = 2.378405444e-04, c3 = 2.019202697e-07;


  
  // select multiplexer address of temperature sensor
  digitalWrite(S0, HIGH); 
  digitalWrite(S1, LOW);
 
  for(int j=0; j<10 ; j++)
    {
       Vo +=  analogRead(analogpin)/10 ;
    }
  R2 = R1 * (440.0 / (float)Vo - 1.0);
  logR2 = log(R2);
  T = (1.0 / (c1 + c2*logR2 + c3*logR2*logR2*logR2));
  T = T - 273.15;


  
  return T;
  } 
