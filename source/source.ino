#include <DHT.h>
///Cambie esta definicion si quiere cambiar el pin del sensor
#define DHTPIN 5
#define DHTTYPE DHT11
///Cambie esta definicion para que cambie la direccion, tiene que coincidir con la direccion de la configuracion en la estacion
#define direccion "0"

String inputString = ""; 
float h;
float t;



DHT dht(DHTPIN,DHTTYPE);
void setup() {
   // put your setup code here, to run once:
   Serial.begin(9600);
   dht.begin();
   inputString.reserve(10);
}

void loop() {
  delay(2000);
  h = dht.readHumidity();
  // Read temperature as Celsius
  t = dht.readTemperature();
  if (isnan(h) || isnan(t)) {
  //  Serial.println("Failed to read from DHT sensor!");
    return;
  }
  /*
  Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  Serial.print("Temperature: "); 
  Serial.print(t);
  Serial.println(" *C ");
  */
}
void serialEvent(){
  while(Serial.available()){
    char inChar=(char)Serial.read();
    if(inChar=='*'){
       if(inputString==direccion){
//         Serial.println("Correcta");
            Serial.print(t);
            Serial.print("%");
            Serial.println(h);
       }
    }
    else{
       inputString += inChar; 
    }
  }
  inputString="";
}
