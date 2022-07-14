#include<WiFi.h>
#include <FirebaseESP32.h>

#define SSID "xxx" //ingresar el nombre de la red a la desea conectarse 
#define PASS "xxx" //ingresar la contraseña de la red a la desea conectarse

#define URL "comuesp32-default-rtdb.firebaseio.com" //esta es la url de la base de datos publica, si quiere tener una privada debera cambiar la url por la url de la base privada
#define secreto "t4mDewpYzgTbUE76QJKsmBNV4Fn7kWH01rC1rEVk"//esto es un dato necesario que tiene cada base de datos, esto nos servira para establecer una comunicacion con la misma 
//en caso de querer una base privada debera tambien cambiar esto por el secret de su base de datos 

FirebaseData myFirebaseData;

int periodoWifi = 500;
String mensaje;
String entrante;

void Conexion(){
 WiFi.begin(SSID,PASS);
 Serial.print("conectando a la red");
 Seria.printnl(SSID);
 while(WiFi.status != WL_CONNECTED){
    if(millis() < periodoWifi + tiempoWifi){
        Serial.print(".");
    }
 }
 Firebase.begin(URL,secreto);
 Firebase.reconnectWiFi(true);
 Serial.print("conectado con exito");
}
void Logeo(){
    Firebase.set(myFirebaseData,"MENSAJE","usuario conectado");
}
String Recepcion(){
Firebase.get(myFirebaseData,"/MENSAJE");
return myFirebaseData.StringData();
}
void setup() {
  Serial.begin(9600);
  Conexion();
  Logeo();

}
void main(){

}
void loop() {
}

  
