#include <LiquidCrystal_I2C.h>

// set the LCD number of columns and rows
int lcdColumns = 16;
int lcdRows = 2;

// set LCD address, number of columns and rows
// if you don't know your display address, run an I2C scanner sketch
LiquidCrystal_I2C lcd(0x27, lcdColumns, lcdRows);  
  
 #define BLYNK_PRINT Serial
 
 
 #define BLYNK_TEMPLATE_ID "TMPL402m42k7"  ///replace with your temeplate id.
#define BLYNK_DEVICE_NAME "QAWMp"    ///replace with your device name.
 
 /* Fill-in your Template ID (only if using Blynk.Cloud) */
char auth[] = "F3BOI1vrf9EYMRUDZxxxxxxxxxx";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "Prumwire";
char pass[] = "22580540aaa";


 #include <ESP8266WiFi.h>
 #include <BlynkSimpleEsp8266.h> 

 #define analogpin  A0 //single analog input pin

 // multiplexer to nodemcu pins
#define S0   13 
#define S1   0
BlynkTimer timer;


 void setup() {
  
  // put your setup code here, to run once:
    Serial.begin(9600);   
    pinMode(analogpin, INPUT);
     pinMode(S0, OUTPUT);
      pinMode(S1, OUTPUT);
      Blynk.begin(auth, ssid, pass);
        // initialize LCD
  lcd.init();
  // turn on LCD backlight                      
  lcd.backlight();
timer.setInterval(1000L,sendvalue); 

 }  


  //turbidity function
float  TURBID()
{
  
   float ntu;
  float tvolt;


  
  // select multiplexer address of turbidity sensor
   digitalWrite(S0, LOW);
  digitalWrite(S1, LOW);
   
    tvolt = 0;
    for(int i=0; i<800; i++)
    {
        tvolt += ((float)analogRead(analogpin)/1023)*8 ;// conversion of input analog value to 10 bit 5volt voltage value
    }
    tvolt = tvolt/1004 ;
    tvolt = round_to_dp(tvolt,2);
    if (tvolt >5 ){
      ntu = 1;
      } 
      else{
    ntu =map(tvolt,0,5.722,250,0);
    
      }
  lcd.clear();  
  lcd.setCursor(0,0);
  lcd.print("TURBIDITY" );
  lcd.setCursor(0, 1); 
  lcd.print(ntu);
  lcd.print ("ppm");
  delay(3000);
  
 
  return ntu ;
}
 
float round_to_dp( float in_value, int decimal_place ) 
{
  float multiplier = powf( 10.0f, decimal_place );
  in_value = roundf( in_value * multiplier ) / multiplier;


  
  return in_value;
  }
