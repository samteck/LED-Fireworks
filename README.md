# LED-Fireworks
Firework effect with WS2812b LED and a MCU

<p align="center">
<img src="https://github.com/samteck/LED-Fireworks/blob/main/media/2.jpeg" width="500">
</p>

This project uses [FastLED](http://fastled.io/ "FastLED Homepage") library to control the LED strip.

[WS2812b](https://cdn-shop.adafruit.com/datasheets/WS2812B.pdf "WS2812b Datasheet") IC is embedded into each LED, each LED has 4 pins
1. VCC
2. GND
3. Data In (to input byte stream)
4. Data Out (to output byte stream)

Each LED trims out the first 3 bytes of data (RGB values) from the byte stream and sends the rest of stream to next LED.

<p align="center">
<img src="https://github.com/samteck/LED-Fireworks/blob/main/media/WS2812B-RGB-LED-Strip.jpg" width="500">
</p>

## Power Requirements
The WS2812b LEDs runs on 5V and require max 60mA of current (20mA, 20mA, 20mA each for Red, Green and Blue)
This light can be Powered directly via Arduino running on 5V with a 330ohm resitor on data PIN. And can be controlled via Raspberry Pi, ESPs or any other 3.3V device with help of logic level shifter.

### Setup
The Led Strip is isolated in 2 sections. First is **flare** and second is **spark**
Physically the flare is made up of 1 row of 90 LEDs and the spark is made up of 6 rows of 30 LED each.

Logically flare is an array of 90 LEDs and spark is an Array of 30 LEDs (duplicated over 6 rows) and Tail of the flare and spark runs few LEDs in back with decresed intensity

<img src="https://github.com/samteck/LED-Fireworks/blob/main/media/LAYOUT-LED-PARALLEL.png" width="500">

<img src="https://github.com/samteck/LED-Fireworks/blob/main/media/1.jpeg" width="500">
