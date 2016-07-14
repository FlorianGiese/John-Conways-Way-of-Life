
#include <Adafruit_NeoPixel.h>
#include <avr/power.h>
#ifdef __AVR__
#endif
#define PIN            6
#define HEIGHT         8  //Höhe des Spielfeldes 
#define WIDTH          8  //Breite des Spielfeldes 
#define NUMPIXELS      WIDTH * HEIGHT//Anzahl aller Pixel


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);
int Pixels [NUMPIXELS];
int Leben [NUMPIXELS]; 
int schritte;
int veraenderungen = 0;
int veraenderungen2;
int lastPixel = NUMPIXELS -1;
int randNumber1;
const int buttonPin = 2;
int buttonState = 0;


void setup() {

  randomSeed(analogRead(0));
  for(int r=0;r<NUMPIXELS;r++){
    Pixels[r]  = random(2);


  }


  /*
   
   Pixels[10] = 1;
   Pixels[18] = 1;
   Pixels[25] = 1;
   Pixels[26] = 1;
   Pixels[40] = 1;
   Pixels[41] = 1;
   Pixels[44] = 1;
   Pixels[45] = 1;
   Pixels[46] = 1;
   Pixels[48] = 1;
   Pixels[50] = 1;
   Pixels[52] = 1;
   Pixels[57] = 1;
   Pixels[58] = 1;
     */
  /*
   Pixels[4] = 1;
   Pixels[5] = 1;
   Pixels[6] = 1;
   Pixels[11] = 1;
   Pixels[19] = 1;
   Pixels[27] = 1;
   Pixels[15] = 1;
   Pixels[23] = 1;
   Pixels[31] = 1;
   Pixels[37] = 1;
   Pixels[38] = 1;
   Pixels[36] = 1;
   */

  /*
  Pixels[35] = 1;
   Pixels[19] = 1;
   Pixels[27] = 1;
   Pixels[26] = 1;
   Pixels[28] = 1;
   */


  /*
   Pixels[15] = 1;
   Pixels[23] = 1;
   Pixels[31] = 1;
   */
  Serial.begin(9600);
  pixels.begin();
  pinMode(buttonPin, INPUT);

};



int Nachbar(int n){
  int Nachbar = 0;
  if (n == NUMPIXELS - WIDTH ){ //öffnet if Ecke links unten
    if (Pixels[n - 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. oben. ");
    }//schließt if 
    if (Pixels[n - 7] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. rechts oben. ");
    }//schließt if 
    if (Pixels[n + 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. Rechts. ");
    }//schließt if  
    return Nachbar;
  }//schließt Ecke links unten



  if (n == lastPixel){ //öffnet if Ecke rechts unten
    if (Pixels[n - 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. oben. ");
    }//schließt if 
    if (Pixels[n - 9] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. links oben. ");
    }//schließt if 
    if (Pixels[n - 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. links. ");
    }//schließt if  
    return Nachbar;
  }//schließt Ecke rechts unten





  if (n == 0 + WIDTH  - 1){ //öffnet if Ecke rechts oben
    if (Pixels[n + 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. unten. ");
    }//schließt if 
    if (Pixels[n +7 ] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. links unten. ");
    }//schließt if 
    if (Pixels[n - 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. links. ");
    }//schließt if  
    return Nachbar;
  }//schließt Ecke rechts oben






  if (n == 0){ //öffnet if Ecke links oben
    if (Pixels[n + 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. unten. ");
    }//schließt if 
    if (Pixels[n + 9] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. rechts unten. ");
    }//schließt if 
    if (Pixels[n + 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. rechts. ");
    }//schließt if  
    return Nachbar;
  }//schließt Ecke links oben






  //if ((32<n)&&(n<39)){ //öffnet if untere Reihe  
  if ((NUMPIXELS - WIDTH <n)&&(n<lastPixel)){
    if (Pixels[n + 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. Rechts. ");
    }//schließt if  
    if (Pixels[n - 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. Links. ");
    }//schließt else
    if (Pixels[n - 7] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. rechts oben. ");
    }//schließt if 
    if (Pixels[n - 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. oben. ");
    }//schließt if 
    if (Pixels[n - 9] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. links oben. ");
    }//schließt if 
    return Nachbar;
  }//schließt if untere Reihe






  if ((0<n)&&(n<0+WIDTH -1)){ //öffnet if obere Reihe 
    if (Pixels[n + 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. Rechts. ");
    }//schließt if  
    if (Pixels[n - 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. Links. ");
    }//schließt else
    if (Pixels[n + 7] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. links unten. ");
    }//schließt if 
    if (Pixels[n + 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. unten. ");
    }//schließt if 
    if (Pixels[n + 9] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. rechts unten. ");
    }//schließt if 
    return Nachbar;
  }//schließt if obere Reihe






  if (n % 8 == 0){ //öffnet if links
    //if ((n== 8)||(n==16)||(n==24)){
    if (Pixels[n + 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. Rechts. ");
    }//schließt if  
    if (Pixels[n - 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. oben. ");
    }//schließt else
    if (Pixels[n - 7] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. rechts oben. ");
    }//schließt if 
    if (Pixels[n + 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. unten. ");
    }//schließt if 
    if (Pixels[n + 9] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. rechts unten. ");
    }//schließt if 
    return Nachbar; 
  }//schließt if links







  if (n % 8 == 7){ //öffnet if rechts
    //if ((n==15)||(n==23)||(n==31)){
    if (Pixels[n - 1] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. links. ");
    }//schließt if  
    if (Pixels[n + 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. unten. ");
    }//schließt else
    if (Pixels[n + 7] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. links unten. ");
    }//schließt if 
    if (Pixels[n - 8] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. oben. ");
    }//schließt if 
    if (Pixels[n - 9] == 1){
      Nachbar = Nachbar + 1;
      //Serial.print(n);
      //Serial.println(". Zelle. links oben. ");
    }//schließt if 
    return Nachbar; 
  }//schließt if rechts







  if (Pixels[n + 1] == 1){
    Nachbar = Nachbar + 1;
    //Serial.print(n);
    //Serial.println(". Zelle. Rechts. ");
  }//schließt if  
  if (Pixels[n - 1] == 1){
    Nachbar = Nachbar + 1;
    //Serial.print(n);
    //Serial.println(". Zelle. Links. ");
  }//schließt else
  if (Pixels[n + 7] == 1){
    Nachbar = Nachbar + 1;
    //Serial.print(n);
    //Serial.println(". Zelle. links unten. ");
  }//schließt if 
  if (Pixels[n + 8] == 1){
    Nachbar = Nachbar + 1;
    //Serial.print(n);
    //Serial.println(". Zelle. unten. ");
  }//schließt if 
  if (Pixels[n + 9] == 1){
    Nachbar = Nachbar + 1;
    //Serial.print(n);
    //Serial.println(". Zelle. rechts unten. ");
  }//schließt if 
  if (Pixels[n - 7] == 1){
    Nachbar = Nachbar + 1;
    //Serial.print(n);
    //Serial.println(". Zelle. rechts oben. ");
  }//schließt if 
  if (Pixels[n - 8] == 1){
    Nachbar = Nachbar + 1;
    //Serial.print(n);
    //Serial.println(". Zelle. oben. ");
  }//schließt if 
  if (Pixels[n - 9] == 1){
    Nachbar = Nachbar + 1;
    //Serial.print(n);
    //Serial.println(". Zelle. links oben. ");
  }//schließt if 
  /*Serial.print(n);
   Serial.print(". Zelle. Nachbarn am Leben: ");
   Serial.println(Nachbar);
   */
  return Nachbar;
}//schließt int Nachbar






/*

 int veraenderungen (int i){
 int veraenderungen =  veraenderungen;
 if (Pixels[i] == Leben[i]){
 
 
 } 
 if (Pixels[i] != Leben[i]){
 
 veraenderungen++; 
 } 
 
 return veraenderungen;
 }
 
/*
 
 int veraenderungen2 (int i){
 int veraenderungen2 = veraenderungen2;        
 if (Pixels[i] == Leben[i]){
 
 veraenderungen2 = 0;
 } 
 else{
 
 veraenderungen2++;        
 } 
 
 
 
 return veraenderungen2;
 }
 
 
 */



void loop() {
  /*  buttonState = digitalRead(buttonPin);
   if (buttonState == HIGH){
   delay (1000);
   software_Reset();
   }
   else{
   
   }
   */

  int lebendePixel =  0;



  for(int i=0;i<NUMPIXELS;i++){

    if (Pixels[i] == 0){ 
      pixels.setPixelColor(i, pixels.Color(10,3,0));
      // Muster[i] = 0; 
    }//schließt if 
    if (Pixels[i] == 1 ){
      lebendePixel = lebendePixel + 1;     
      //Muster[i]++;
      pixels.setPixelColor(i, pixels.Color(0,0,15)); 
    }//schließt if

    int anzahlLebenderPixel; 
    anzahlLebenderPixel = Nachbar(i);


    if ((anzahlLebenderPixel < 2)|| (anzahlLebenderPixel > 3)){



      //Pixels[i] = 0;
      Leben[i] = 0; 

    }//schließt if 


    if (anzahlLebenderPixel == 3){
      //Pixels[i] = 1;
      Leben[i] = 1; 

    }//schließt if 
   if (anzahlLebenderPixel == 2){
      //Pixels[i] = 1;
      Leben[i] = 2;
    }//schließt if


  }//schließt for(int


  for(int i=0;i<NUMPIXELS;i++){
   if (Leben[i] == 2){
      Leben[i] = Pixels[i];
    }
    
    if (Leben[i] != Pixels[i]){
 //     Serial.print(Leben[i]);
  //    Serial.print(" : ");
   //   Serial.println(Pixels[i]);
      veraenderungen++;
    }
  }


  for(int i=0;i<NUMPIXELS;i++){
    if (Leben[i] == 0){
      Pixels[i] = 0; 
    }
    if (Leben[i] == 1){
      Pixels[i] = 1;

    } 
  if (Leben[i] == 2){
      Leben[i] = Pixels[i];

    }

  }



  pixels.show();
  delay (100);

  if (lebendePixel == 0){
    delay (1000);
    software_Reset();
  }


  //Serial.println(veraenderungen);


  if (veraenderungen == veraenderungen2){
    schritte++; 
  }
  // Serial.println(schritte);
  //     Serial.print(veraenderungen);                                         

  veraenderungen2 = veraenderungen;


  if (schritte == 50){
    software_Reset();
  }   

}//schließt den loop



void software_Reset() 
{
  asm volatile ("  jmp 0");  
}  


















