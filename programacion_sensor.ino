  #include "Adafruit_TCS34725.h"
  
  Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X);

  void setup() {
  Serial.begin(9600);
  }
  void loop() {
  float red, green, blue;
  
  tcs.getRGB(&red, &green, &blue);
  
  uint32_t sum = (red+green+blue)/3;
  
  float r = red; r /= sum;
  int rojo = r*100;
  float g = green; g /= sum;
  int verde = g*100;
  float b = blue; b /= sum;
  int azul = b*100;
  
  Serial.print("R:\t"); Serial.print(rojo); 
  Serial.print("\tG:\t"); Serial.print(verde); 
  Serial.print("\tB:\t"); Serial.print(azul);
  Serial.println("");
  }
