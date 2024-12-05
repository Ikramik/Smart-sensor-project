#include <DHT.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x3F,16,2);   

#define DHTPIN 3     // what pin we're connected to
#define DHTTYPE DHT11  
DHT dht(DHTPIN, DHTTYPE); 

int Input = A0;
int Buzzer = 2;
int value;
int MAX = 600;
int h;  //Stores humidity value
int t; //Stores temperature value


void setup(){
	Serial.begin(9600);
	Serial.println("Air Test");
	dht.begin();
	lcd.init(); //initialize the lcd
	lcd.backlight(); //open the backlight
	pinMode(Input ,INPUT);    
	pinMode(Buzzer ,OUTPUT);
}

void loop(){
	value = analogRead(A0);

	if (value >= MAX) {
		lcd.setCursor(0, 0);
		lcd.print(" Smoke or gas detected");
		Serial.println("Smoke or gas detected");
		digitalWrite(Buzzer,HIGH);
	}

	else {	
		digitalWrite(Buzzer,LOW);
		lcd.setCursor(0, 0);
		lcd.print(" Sweet Home            ");
  	}
    //Read data and store it to variables h (humidity) and t (temperature)

	h = dht.readHumidity();
	t = dht.readTemperature();

    //Print temp and humidity values to serial monitor
	if (isnan(h) || isnan(t)) {
		Serial.println("Failed to read from DHT sensor!");
		lcd.setCursor(0, 1);
		lcd.print("Sensor error     ");
	}
	else {
		lcd.setCursor(0, 1);
		lcd.print(" T:");
		lcd.print(t);
		lcd.print("C");
  		lcd.setCursor(11, 1);
		lcd.print("H:");
		lcd.print(h);
		lcd.print("%  ");
	}
	delay(1500); 
	
}


