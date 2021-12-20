/*
 * Sensor DHT11 suoer simple
 * https://www.youtube.com/c/Radal05
 * 20 Desember 2021
 */


#define RED 0     //define red color pin PB0
#define GREEN 1   //define green color pin PB1
#define BLUE 2    //define blue color pin PB2


#include <DHT.h>    //dht sensor library
DHT dht(4, DHT11);  //Data sensor DHT ke PB4

void setup()
{
  pinMode (RED,OUTPUT);  
  pinMode (GREEN,OUTPUT);  
  pinMode (BLUE,OUTPUT);
  digitalWrite (RED, HIGH); //Membuat Off led red dan buzzer
  dht.begin();
}

void loop()
{ float t = dht.readTemperature();
  float h = dht.readHumidity();

   /*
    * bila sensor tidak membaca
    * nyalakan led green dan blue
    */
  if (isnan(t) ) {          
  digitalWrite(GREEN, LOW);
  digitalWrite(BLUE, LOW);
  delay(100); 
  return;
  }
/*
 * Bila ada Humidity yang dilarang
 * mala led green dan blue tidak berkedip
 * contoh disini Humidity yang dilarang 50%-60%
 * Dan sekalian menunjukan bahwa alat ini bekerja
 * Bila sensor erro mala led 
 */
for (int i=0; i <= 3; i++){   
  if (h >= 60 || h <= 50){
    {
     digitalWrite (GREEN, LOW);
     digitalWrite (BLUE, LOW);
     delay(100);  
     
     digitalWrite (GREEN, HIGH);
     digitalWrite (BLUE, LOW);
     delay(100);
     
     digitalWrite (GREEN, LOW);
     digitalWrite(BLUE, HIGH);
     delay(100);}
    }}

// Bila Humidity dibawah 70% buzzer ON
  if (h<=70){
    digitalWrite (RED, LOW);
  }
     
  
  if (t >32)  //temperature check for hot, cold, optimum
    {
      digitalWrite (RED, LOW);
      }
    
  else if (t <23)
    {digitalWrite (RED, LOW);
     }
    
  else
    {
     digitalWrite (GREEN, HIGH);// Status suhu masuk katagori
     digitalWrite (BLUE, LOW);
     
     }

  delay(3000);   //period pengukuran per 3 detik
  digitalWrite (RED, HIGH); //Matikan led dan buzzer 
}
