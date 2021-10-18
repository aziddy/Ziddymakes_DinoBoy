# Ziddymakes_DinoBoy

<br>

## Component List

* SMD Toggle Switch
* Arduino Nano Clone (328p)
* 2 Tactile Switches
* PCB
* 9v Battery Holder
* OLED Display 128x64 Pixel I2C, 0.96 inch, SSD1306 

<p align="center" style="vertical-align: top; position: relative" >
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/parts/1988_d9ab1bc4-37ee-4b47-8687-ac5aa7976e0a2.jpg?raw=true" width="300"/>
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/parts/6-6-6-H-4legs-tact-switch.jpg_350x350.jpg?raw=true" width="226"/>
<img align="top" style="vertical-align:top" src="https://github.com/aziddy/Mini-OLED-Retro-Handheld/blob/master/media/parts/c3422_large_miniature_pcb_mount_slide_switch.jpg?raw=true" width="300"/>
</p>

<br>


## Programming

Instructions to install **SSD1306** and **GFX** libraries to your Arduino IDE https://learn.adafruit.com/monochrome-oled-breakouts/arduino-library-and-examples

Writing most of the code and installing the libraries was pretty straight foward. But when it comes to rendering images, ohhh boy thats abit of a hassle

You first have to convert your image to only have **two colors** *(OLED only deals with 2)* with a high enough contrast between them

Then you have to transform your image into a format that can be stored in your Arduino's flash memory easily. This site https://javl.github.io/image2cpp/ makes that process easy. You can fiddle around with the **threshold** and **image size** here

When your done messing with the image settings make sure to set the **Code output format** to ***Arduino Code***. Then copy and paste the output code to your code

The output code with the array we get has the PROGMEM keyword because we want the image array to be stored in the Arduino's Flash memory where your program resides instead of RAM, because of how little RAM most microcontrollers have

Read more about PROGMEM https://www.arduino.cc/reference/tr/language/variables/utilities/progmem/


