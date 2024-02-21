#include"DHT.h";
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
#define dht_1 8
#define pump 9
#define fan 10
#define heater 11
#define buzzer 12

#define DHTTYPE DHT11
DHT dht(dht_1,DHTTYPE);
int soilPin = A7, airPin = A6;


void setup() {
  Serial.begin(9600);
  
  dht.begin();
  lcd.begin(20, 4);
  lcd.print("Smart Green House");
  lcd.setCursor(0,1);
  lcd.print("Vishal Thorat");
  lcd.setCursor(0,2);
  lcd.print("Mayuri Shimpi");
  lcd.setCursor(0,4);
  lcd.print("Shivani Gavadhe");
  delay(1000);
  lcd.clear();
  pinMode(soilPin, INPUT);
  pinMode(airPin, INPUT);
  pinMode(pump, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(heater, OUTPUT);
  pinMode(buzzer, OUTPUT);

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
  lcd.print("Soil Moisture=");
  lcd.setCursor(15,0);
  lcd.print(soilData);

  Serial.print("Air Quality = ");
  Serial.println(airData);
  lcd.setCursor(0,1);
  lcd.print("Air Quality = ");
  lcd.setCursor(15,1);
  lcd.print(airData);

  
  Serial.print("Humidity = ");
  Serial.println(humi);
  lcd.setCursor(0,2);
  lcd.print("Humidity = ");
  lcd.setCursor(15,2);
  lcd.print(humi);

  Serial.print("Temperature = ");
  Serial.println(temp);
  lcd.setCursor(0,3);
  lcd.print("Temperature = ");
  lcd.setCursor(15,3);
  lcd.print(temp);
}


void loop() {
  float humi = dht.readHumidity();
  float temp = dht.readTemperature();
  int soilData = analogRead(soilPin);
  int airData = analogRead(airPin);

  if(soilData >=550)
  {
      All();
      delay(500);     
      digitalWrite(pump, HIGH);
      Serial.println("PUMP is ON Need Water, Soil moisture is 550");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("PUMP ON - Need Water");
  }
  else if(airData >=450)
  {
      All();
      delay(500);     
      digitalWrite(buzzer, HIGH);
      Serial.println("Gas Detected-Fan ON gas value >450");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Gas Detected");
  }

  else if(humi >= 60)
    {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      Serial.println("Fan is ON ");
      Serial.println("Heater is ON humi is >60");
      lcd.clear();
      lcd.setCursor(0,3);
      lcd.print("FAN ON humi >60");
      lcd.setCursor(0,2);
      lcd.print("Heater ON humi>60");  
    }
  else if(humi <= 20)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      Serial.println("Fan is ON ");
      lcd.clear();
      lcd.setCursor(0,2);
      lcd.print("FAN is ON");
  }
    
  else if(temp >= 45)
    {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      Serial.println("Fan is ON temp is >45");
      lcd.clear();
      lcd.setCursor(0,3);
      lcd.print("FAN is ON temp>45");
     
    }
  else if(temp <= 10)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      Serial.println("Heater is ON temp <10 ");
      lcd.clear();
      lcd.setCursor(0,3);
      lcd.print("Heater is ON ");
  }
  
  else if(temp <= 10 && humi <= 20)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Heater is ON temp is <10");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi <20"); 
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");  
  }

    else if(temp <= 10 && humi >=60)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Heater is ON temp is <10");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");  
  }
    else if(temp <= 10 && 20 < humi <60)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      Serial.println("Heater is ON temp is <10");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");  
  } 

  else if(temp >= 45 && humi <= 20)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Fan is ON Temp > 45");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Heter On humi<20"); 
      lcd.setCursor(0,1);
      lcd.print("Fan On temp>45");  
  }

    else if(temp >=45 && humi >=60)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Fan is ON temp is >45");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp>45");  
  }
    else if(temp >=45 && 20 < humi <60)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      Serial.println("Fan ON temp >45 ");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp >45");  
  } 


  else if(10< temp <45 && humi <= 20)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Fan is ON Temp > 45");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Heter On humi<20"); 
      lcd.setCursor(0,1);
      lcd.print("Fan On temp>45");  
  }

    else if(10< temp <45 && humi >=60)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Fan is ON temp is >45");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp>45"); 
  }
    else if(10< temp <45 && 20 < humi< 60)
  {
      All();
      delay(500);
  } 

  else if(temp <= 10 && humi <= 20 && airData >=450)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Heater is ON temp is <10");
      Serial.println("Gas Found");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi <20"); 
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10"); 
      lcd.setCursor(0,2);
      lcd.print("Gas Found");   
  }

    else if(temp <= 10 && humi >=60 && airData >=450)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Heater is ON temp is <10");
      Serial.println("Gas Found");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");
      lcd.setCursor(0,2);
      lcd.print("Gas Found");  
  }
    else if(temp <= 10 && 20 < humi <60 && airData >=450)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("Heater is ON temp is <10");
      Serial.println("Gas Found");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");  
      lcd.setCursor(0,2);
      lcd.print("Gas Found"); 
  } 

  else if(temp >= 45 && humi <= 20 && airData >=450)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Fan is ON Temp > 45");
      Serial.println("Gas Found");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Heter On humi<20"); 
      lcd.setCursor(0,1);
      lcd.print("Fan On temp>45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found"); 
  }

    else if(temp >=45 && humi >=60 && airData >=450 )
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Fan is ON temp is >45");
      Serial.println("Gas Found");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp>45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found");   
  }
    else if(temp >=45 && 20 < humi <60 && airData >=450)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("Fan ON temp >45 ");
      Serial.println("Gas Found");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp >45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found");   
  } 


  else if(10< temp <45 && humi <= 20 && airData >=450)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Fan is ON Temp > 45");
      Serial.println("Gas Found");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Heter On humi<20"); 
      lcd.setCursor(0,1);
      lcd.print("Fan On temp>45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found");    
  }

    else if(10< temp <45 && humi >=60 && airData >=450)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Fan is ON temp is >45");
      Serial.println("Gas Found");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp>45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found");    
  }
    else if(10< temp <45 && 20 < humi< 60 && airData >=450)
  {
      All();
      delay(500);
      digitalWrite(buzzer, HIGH);
      Serial.println("Gas Found");
      lcd.clear();
      lcd.setCursor(0,2);
      lcd.print("Gas Found");   
  } 

  else if(temp <= 10 && humi <= 20 && airData >=450 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Heater is ON temp is <10");
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi <20"); 
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10"); 
      lcd.setCursor(0,2);
      lcd.print("Gas Found"); 
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");   
  }

    else if(temp <= 10 && humi >=60 && airData >=450 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Heater is ON temp is <10");
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");
      lcd.setCursor(0,2);
      lcd.print("Gas Found"); 
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water"); 
  }
    else if(temp <= 10 && 20 < humi <60 && airData >=450  && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Heater is ON temp is <10");
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");  
      lcd.setCursor(0,2);
      lcd.print("Gas Found");
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water"); 
  } 

  else if(temp >= 45 && humi <= 20 && airData >=450  && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Fan is ON Temp > 45");
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Heter On humi<20"); 
      lcd.setCursor(0,1);
      lcd.print("Fan On temp>45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found");
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");   
  }

    else if(temp >=45 && humi >=60 && airData >=450  && soilData >=550 )
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Fan is ON temp is >45");
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp>45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found"); 
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");    
  }
    else if(temp >=45 && 20 < humi <60 && airData >=450  && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan ON temp >45 ");
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp >45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found");
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");     
  } 


  else if(10< temp <45 && humi <= 20 && airData >=450  && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Fan is ON Temp > 45");
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Heter On humi<20"); 
      lcd.setCursor(0,1);
      lcd.print("Fan On temp>45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found"); 
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");     
  }

    else if(10< temp <45 && humi >=60 && airData >=450 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Fan is ON temp is >45");
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp>45");
      lcd.setCursor(0,2);
      lcd.print("Gas Found");  
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");    
  }
    else if(10< temp <45 && 20 < humi< 60 && airData >=450 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,2);
      lcd.print("Gas Found");   
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");  
  }


 else if(temp <= 10 && humi <= 20 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Heater is ON temp is <10");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi <20"); 
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");  
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");   
  }

    else if(temp <= 10 && humi >=60 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Heater is ON temp is <10");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");
      lcd.setCursor(0,2);
      lcd.print("Pump On Need Water"); 
  }
    else if(temp <= 10 && 20 < humi <60 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Heater is ON temp is <10");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Heater ON temp <10");  
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water"); 
  } 

  else if(temp >= 45 && humi <= 20 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Fan is ON Temp > 45");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Heter On humi<20"); 
      lcd.setCursor(0,1);
      lcd.print("Fan On temp>45");
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");   
  }

    else if(temp >=45 && humi >=60 && soilData >=550 )
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Fan is ON temp is >45");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp>45");
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");    
  }
    else if(temp >=45 && 20 < humi <60 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(heater, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan ON temp >45 ");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp >45");
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");     
  } 


  else if(10< temp <45 && humi <= 20 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is <20");
      Serial.println("Fan is ON Temp > 45");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Heter On humi<20"); 
      lcd.setCursor(0,1);
      lcd.print("Fan On temp>45");
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");     
  }

    else if(10< temp <45 && humi >=60 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(fan, HIGH);
      digitalWrite(heater, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Fan is ON humi is >60");
      Serial.println("Fan is ON temp is >45");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,0);
      lcd.print("Fan ON Humi >60"); 
      lcd.setCursor(0,1);
      lcd.print("Fan ON temp>45"); 
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");    
  }
    else if(10< temp <45 && 20 < humi< 60 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(pump, HIGH);
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");  
  }
    else if(airData >=450 && soilData >=550)
  {
      All();
      delay(500);
      digitalWrite(buzzer, HIGH);
      digitalWrite(pump, HIGH);
      Serial.println("Gas Found");
      Serial.println("Pump On Need Water");
      lcd.clear();
      lcd.setCursor(0,2);
      lcd.print("Gas Found");   
      lcd.setCursor(0,3);
      lcd.print("Pump On Need Water");  
  }

 else
 {
  All();
  digitalWrite(fan, LOW);
  digitalWrite(heater, LOW);
  digitalWrite(pump, LOW);
  digitalWrite(buzzer, LOW);
  delay(500);
  }

  
}
