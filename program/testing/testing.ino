#include"DHT.h";
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define dht_1 A5
#define pump 9
#define fan 10
#define heater 11
#define buzzer 8

#define DHTTYPE DHT11
DHT dht(dht_1,DHTTYPE);
int soilPin = A7, airPin = A6;


void setup() {
  Serial.begin(9600);
  
  dht.begin();
  lcd.begin(16, 2);
  lcd.print("Smart Green House");
  lcd.setCursor(0,1);
  lcd.print(" Vishal Thorat");
  lcd.setCursor(0,2);
  delay(1000);
  lcd.clear();
  lcd.print(" Mayuri Shimpi");
  lcd.setCursor(0,1);
  lcd.print(" Shivani Gavadhe");
  delay(1000);
  
  pinMode(soilPin, INPUT);
  pinMode(airPin, INPUT);
  pinMode(pump, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(buzzer, OUTPUT);
  lcd.clear();
}

void All()
{
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  int soilData = analogRead(soilPin);
  int airData = analogRead(airPin);

  lcd.clear();
  Serial.print("Soil Moisture = ");
  Serial.println(soilData);
  lcd.setCursor(0,0);
  lcd.print("Soil Mois=");
  lcd.setCursor(12,0);
  lcd.print(soilData);

  Serial.print("Air Quality = ");
  Serial.println(airData);
  lcd.setCursor(0,1);
  lcd.print("Air Qual = ");
  lcd.setCursor(12,1);
  lcd.print(airData);
   delay(1000);

  lcd.clear();
  Serial.print("Humidity = ");
  Serial.println(humi);
  lcd.setCursor(0,0);
  lcd.print("Humidity = ");
  lcd.setCursor(11,0);
  lcd.print(humi);

  Serial.print("Temperature = ");
  Serial.println(temp);
  lcd.setCursor(0,1);
  lcd.print("Temper=");
  lcd.setCursor(12,1);
  lcd.print(temp);
     delay(1000);
   lcd.clear();
}


void loop() {
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  int soilData = analogRead(soilPin);
  int airData = analogRead(airPin);

 if(temp>45)
 {
     All();
     lcd.setCursor(0,0);
     digitalWrite(fan,HIGH);
     lcd.print("Fan On");
     delay(1000);
    
    if(humi>80)
    { 
      lcd.setCursor(0,1);
      digitalWrite(heater,HIGH);
      lcd.print("Heater On");
      digitalWrite(heater,HIGH);
      delay(1000);
    }
    else
    {
       digitalWrite(heater,LOW);
       delay(1000);
     }
   lcd.clear();
  
  
  if(airData>=450)
  {
    lcd.clear();
    digitalWrite(buzzer,HIGH);
    lcd.setCursor(0,0);
    lcd.print("Gas detected");
    delay(1000);
    
    }
  else
  {
    digitalWrite(buzzer,LOW);
    delay(1000);
   }
  if(soilData>550)
  {
    lcd.clear();
    digitalWrite(pump,HIGH);
    lcd.setCursor(0,1);
    lcd.print("Pump On");
    delay(1000);
   }
  
  else
  {
     digitalWrite(pump,LOW);
  }
}


  if(temp<10)
  {
    All();
    digitalWrite(heater,HIGH);
    lcd.setCursor(0,0);
    lcd.print("Heater On");
    delay(1000);
   
   if(humi<15)
   { 
     lcd.setCursor(0,1);
     lcd.print("Fan On");
     delay(1000);
    }
   else
   {
    digitalWrite(fan,LOW);
    
    }
   lcd.clear();

   if(airData>=450)
   {
     lcd.clear();
     digitalWrite(buzzer,HIGH);
     lcd.setCursor(0,0);
     digitalWrite(fan,HIGH);
     lcd.print("Gas detected");
     delay(1000);
     }
   else
   {   
     digitalWrite(buzzer,LOW);
     digitalWrite(fan,LOW);
     }
  lcd.clear();
   
   if(soilData>550)
   {
     lcd.clear();
     digitalWrite(pump,HIGH);
     lcd.setCursor(0,1);
     lcd.print("Pump On");
     delay(1000);
     }
  else
  {   
    digitalWrite(pump,LOW);
   }
}


 
 if(temp>=10&&temp<=45)
 {
    All();
    digitalWrite(fan,LOW);
    
    if(humi>80)
    { 
      lcd.setCursor(0,1);
      lcd.print("Heater On");
      delay(1000);
      digitalWrite(heater,HIGH);
      }
    else
    {
      digitalWrite(heater,LOW);
      }
    if(airData>=450)
    {
      lcd.clear();
      digitalWrite(buzzer,HIGH);
      lcd.setCursor(0,1);
      lcd.print("Gas detected");
      delay(1000);
     }
    else
    {
      digitalWrite(buzzer,LOW);
      }
    if(soilData>550)
    {
      lcd.clear();
      digitalWrite(pump,HIGH);
      lcd.setCursor(0,1);
      lcd.print("Pump On");
      delay(1000);
      }
    else
    {
      digitalWrite(pump,LOW);
      }
}

  
}
