
#include <SPI.h>
#include <Ethernet.h>


byte mac[] = { 
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
IPAddress ip(192,168,1,95 );


EthernetServer server(8081);

//Declaramos el sensor 
int pir = 7 ; 
boolean aux=false; 
int estado;
void setup() {
 
  Serial.begin(9600);
  Ethernet.begin(mac, ip);
  server.begin();
  
  pinMode(pir,INPUT);
  
  for(int i =0 ; i<10 ;i++){
   Serial.print(". ");
   delay(1000);
  }//Fin for     

}


void loop() {

  estado = digitalRead(pir);//Leemos el sensor 
 
  if(estado==HIGH){
   aux=true; 
  }
    
  EthernetClient client = server.available();
  if (client) {
    Serial.println("new client");
    
    boolean currentLineIsBlank = true;
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();
        Serial.write(c);
        if (c == '\n' && currentLineIsBlank) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");
          client.println("Content-Type: text/html");
          client.println();
          
          
          
          client.println("<!DOCTYPE HTML>");
          client.println("<html>");
          client.print("Estado de la habitacion : ");
          
          if(aux==true){
           client.print(" Alguien se encuentra en tu cuarto!!");
          }
          else{
            client.print(" Nada de que preocuparse :)");
          }
          client.println("</html>");
          aux=false;
          break;
        }
        if (c == '\n') {
          // you're starting a new line
          currentLineIsBlank = true;
        } 
        else if (c != '\r') {
          // you've gotten a character on the current line
          currentLineIsBlank = false;
        }
      }
    }
    // give the web browser time to receive the data
    delay(1);
    // close the connection:
    client.stop();
    Serial.println("client disconnected");
  }
}

