/*
  Rui Santos
  Complete project details at Complete project details at https://RandomNerdTutorials.com/esp8266-nodemcu-http-get-post-arduino/

  Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files.
  The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

  Code compatible with ESP8266 Boards Version 3.0.0 or above
  (see in Tools > Boards > Boards Manager > ESP8266)
*/

#include <ESP8266WiFi.h>
#include <ESP8266HTTPClient.h>
#include <WiFiClient.h>


//PROTOTIPOS
void atualizaLista(char nome1, char nome2, char nome3, char nome4);

const char* ssid = "Corsi";
const char* password = "corsiEmarco";

//Your Domain name with URL path or IP address with path
String serverName = "http://192.168.50.83:1880/name";

// the following variables are unsigned longs because the time, measured in
// milliseconds, will quickly become a bigger number than can be stored in an int.
unsigned long lastTime = 0;
// Timer set to 10 minutes (600000)
//unsigned long timerDelay = 600000;
// Set timer to 5 seconds (5000)
unsigned long timerDelay = 1000;
unsigned long contName = 0;
String listNameAll;
String listNameVector;
String listNamesPane[10];

void setup() {
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

  Serial.println("Timer set to 5 seconds (timerDelay variable), it will take 5 seconds before publishing the first reading.");



  deleteListName();

}

void loop() {
  // Send an HTTP POST request depending on timerDelay
  if ((millis() - lastTime) > timerDelay) {
    //Check WiFi connection status

    //----TESTE1  --Input Name
    //testInputNameCont();

    //----TESTE1  --Input GetList
    //if(contName%13 == 0) getListName();


    //----TESTE1  --Input DeleteList
    //if(contName%40 == 0) deleteListName();


    getListName();
    deleteListName();
    if( listNameAll.length() == 0 )
    {
      Serial.println("Lista Vazia");
    }

    else
    {
      
      Serial.println(listNameAll);
      char listNameAllChar[200];
      listNameAll.toCharArray(listNameAllChar, 200);

      int nomeValido = 0;
      
      int contPosLetra = 0;
      int contPosLetraValido = 0;
      int contCharInvalido=0;

      char name1[16];
      for (int i = 0; i<=15 ; i++) name1[i] = ' ';
      while(listNameAllChar[contPosLetra] != ':')
      {
        if(listNameAllChar[contPosLetra] != '{' && listNameAllChar[contPosLetra] != '\"' && listNameAllChar[contPosLetra] != '}')
        {
          name1[contPosLetraValido] = listNameAllChar[contPosLetra];
          contPosLetraValido=contPosLetraValido+1;
        }
        contPosLetra=contPosLetra+1;
      }
      for (int i = 0; i<=15 ; i++) Serial.print(name1[i]);


      char name2[16];
      contPosLetraValido=0;
      for (int i = 0; i<=15 ; i++) name2[i] = ' ';
      contPosLetra=contPosLetra+1;
      if(listNameAllChar[contPosLetra+4] == '{')
      {
      while(listNameAllChar[contPosLetra] != ':')
      {
        if(listNameAllChar[contPosLetra] != '{' && listNameAllChar[contPosLetra] != '\"' && listNameAllChar[contPosLetra] != '}')
        {
          name2[contPosLetraValido] = listNameAllChar[contPosLetra];
          contPosLetraValido=contPosLetraValido+1;
        }
        contPosLetra=contPosLetra+1;
      }
      for (int i = 0; i<=15 ; i++) Serial.print(name2[i]);
      }


      char name3[16];
      contPosLetraValido=0;
      for (int i = 0; i<=15 ; i++) name3[i] = ' ';
      contPosLetra=contPosLetra+1;
      if(listNameAllChar[contPosLetra+4] == '{')
      {
      while(listNameAllChar[contPosLetra] != ':')
      {
        if(listNameAllChar[contPosLetra] != '{' && listNameAllChar[contPosLetra] != '\"' && listNameAllChar[contPosLetra] != '}')
        {
          name3[contPosLetraValido] = listNameAllChar[contPosLetra];
          contPosLetraValido=contPosLetraValido+1;
        }
        contPosLetra=contPosLetra+1;
      }
      for (int i = 0; i<=15 ; i++) Serial.print(name3[i]);
      }


      char name4[16];
      contPosLetraValido=0;
      for (int i = 0; i<=15 ; i++) name4[i] = ' ';
      contPosLetra=contPosLetra+1;
      if(listNameAllChar[contPosLetra+4] == '{')
      {
      while(listNameAllChar[contPosLetra] != ':')
      {
        if(listNameAllChar[contPosLetra] != '{' && listNameAllChar[contPosLetra] != '\"' && listNameAllChar[contPosLetra] != '}')
        {
          name4[contPosLetraValido] = listNameAllChar[contPosLetra];
          contPosLetraValido=contPosLetraValido+1;
        }
        contPosLetra=contPosLetra+1;
      }
      for (int i = 0; i<=15 ; i++) Serial.print(name4[i]);
      }



      atualizaLista(name1,name2,name3,name4);

      
      
    }

  }
}



void atualizaLista(char *name1, char *name2, char *name3, char *name4)
{
  int deuMatch = 0;
  for(int i = 0 ; i<= 9; i++)
  {
    if(listNamesPanel[i] == name1);
    {
      deuMatch = 1;
    }
  }
}

void testInputNameCont()
{
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    contName++;
    String serverPath = serverName + "?MarcoMello" + contName;

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverPath.c_str());

    // Send HTTP GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  lastTime = millis();
}

void getListName()
{
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    //contName++;
    String serverPath = "http://192.168.50.83:1880/nameList";

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverPath.c_str());

    // Send HTTP GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      listNameAll = payload;
      //Serial.println(payload);
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  lastTime = millis();
}

void deleteListName()
{
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;

    //contName++;
    String serverPath = "http://192.168.50.83:1880/deleteNameList";

    // Your Domain name with URL path or IP address with path
    http.begin(client, serverPath.c_str());

    // Send HTTP GET request
    int httpResponseCode = http.GET();

    if (httpResponseCode > 0) {
      Serial.println("");
      Serial.println("");
      Serial.println("");
      Serial.println("-----LISTA-----");
      Serial.println("");
      Serial.print("HTTP Response code: ");
      Serial.println(httpResponseCode);
      String payload = http.getString();
      Serial.println(payload);
      Serial.println("");
      Serial.println("");
      Serial.println("");
      Serial.println("---------------");
    }
    else {
      Serial.print("Error code: ");
      Serial.println(httpResponseCode);
    }
    // Free resources
    http.end();
  }
  else {
    Serial.println("WiFi Disconnected");
  }
  lastTime = millis();
}
