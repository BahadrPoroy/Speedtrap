#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 6, 5, 4, 3);// RS,E,D4,D5,D6,D7
// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 8;
// defines variables
long duration;
double distance1=0;
double distance2=0;
double Speed=0;
int distance=0;

void setup() 
{
lcd.begin(20, 4);// LCD 16X2
lcd.clear();
lcd.setCursor(0,0);
lcd.print("POROY");
lcd.setCursor(12,2);
lcd.print("SOFTWARE");
delay(1000);
lcd.clear();
pinMode(buzzer, OUTPUT);
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
digitalWrite(buzzer, HIGH);
delay(200);
digitalWrite(buzzer, LOW);
Serial.begin(9600); // Starts the serial communication
lcd.setCursor(0,2);
lcd.print("POROY");
lcd.setCursor(12,2);
lcd.print("SOFTWARE");
lcd.setCursor(0,3);
lcd.print("SPEEDOMETER");
lcd.setCursor(16,3);
lcd.print("V0.1");
}


void loop() 
{

//calculating Speed
   distance1 = ultrasonicRead(); //calls ultrasoninicRead() function below
   Serial.print("Distance1: ");
   Serial.print(distance1);
   delay(1000);//giving a time gap of 1 sec
   
   distance2 = ultrasonicRead(); //calls ultrasoninicRead() function below
   
   //formula change in distance divided by change in time
   Speed = (distance2 - distance1)/1.0; //as the time gap is 1 sec we divide it by 1.
//Displaying Speed
  Serial.print("Speed in cm/s  :"); 
  Serial.println(Speed);
lcd.setCursor(0,1); 
lcd.print("Speed  cm/s ");
lcd.print(Speed);
lcd.print(" "); 
}

float ultrasonicRead ()
{
// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);

// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);

//calculating distance
distance= duration*0.034/2;
// Prints the distance on the Serial Monitor
Serial.print("Distance in cm : ");
Serial.println(distance);
lcd.setCursor(0,0);
lcd.print("Dist. in cm ");
lcd.print(distance);
lcd.print("   ");
return distance;

}
