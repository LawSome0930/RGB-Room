#include "FastLED.h"            // 此示例程序需要使用FastLED库
 
#define NUM_LEDS 16             // LED灯珠数量
#define LED_DT 5                // Arduino输出控制信号引脚
#define LED_TYPE WS2812         // LED灯带型号
#define COLOR_ORDER GRB         // RGB灯珠中红色、绿色、蓝色LED的排列顺序
 
uint8_t max_bright = 255;       // LED亮度控制变量，可使用数值为 0 ～ 255， 数值越大则光带亮度越高
 
CRGB leds[NUM_LEDS];            // 建立光带leds

uint8_t colorIndex;
void setup()
{
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  LEDS.addLeds<LED_TYPE, LED_DT, COLOR_ORDER>(leds, NUM_LEDS);  // 初始化光带
  
  FastLED.setBrightness(max_bright);                            // 设置光带亮度
  
}

void loop()
{
  if (digitalRead(2) == 1) {

      while(1)
      {colorIndex++;
      delay(25);
  fill_rainbow(leds, NUM_LEDS, colorIndex, 9);
  FastLED.show();}
  delay(1000);
  digitalWrite(3, HIGH);
  } else {
    digitalWrite(3, LOW);
    for(int i=0;i<NUM_LEDS;i++)
    {leds[i]=CRGB(0,0,0);}
    FastLED.show();
  }
}
