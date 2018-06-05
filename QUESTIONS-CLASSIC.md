<h1 align="center">ArduExams - QUESTIONS-CLASSIC Repository</h1>

**Sample classic questions for Arduino development board**

[What It Is](#what-it-is)

[Questions](#questions)

[Copyright & Licensing](#copyright--licensing)  

[Contributing](#contributing)  

[Contact](#contact)

# What It Is

- Sample classic questions for Arduino development board

- Answers was here: x

# Questions

## 1. 
Generate a random number between 10 and 50.
If the number is odd, turn on the LED connected to the pin-15.
If the number is even, turn on the LED connected to the pin-16.

## 2. 

## 3. 

## 4. 

## 5. 

## 6. 

## 7. 

## 8. 

## 9. 

## 10. 

## 11. 
The desired temperature range for the room temperature is 22-24 degrees. In order to provide the room temperature for these temperatures, we have to write the codes that control the heater and the cooler.

The connection that triggers the heater to the pin-5.
The connection that triggers the cooler to the pin-6.
At the pin-A0 there is an LM35 value field connection.

You can represent them with leds.

## 12.
According to the light intensity of the environment, no LED will light when the ambient light is bright. As the light intensity of the environment decreases, the LEDs will start to turn on in order. When the air is dark, 3 lights will be lit.

## 13.
According to the distance, make an application that turn-on 4 LED in sequence.

If the distance;

a. If it is between 00-15cm, 4 LED,
b. If it is between 15-30cm, 3 LED,
c. If it is between 30-40cm, 2 LED,
D. If it is between 40-60cm, 1 LED,

...will lit.

## 14.
Displaying the distance on the LCD.

If the distance;

a. If it is between 00-15cm, TOO CLOSE
b. If it is between 15-30cm, CLOSE
c. If it is between 30-40cm, FAR
D. If it is between 40-60cm, TOO FAR

...make the application that writes to the screen. 

## 15.
The humidity and temperature information of the environment will be displayed on the LCD screen instantly in the LCD's first row.

If the humidity rate is;

a. Bigger than 70, the second row is "MORE MOISTURE"
b. Between 50-70, the second row is "MOISTURE"
c. Smaller than 50, it won't write any info

Similarly, if the air temperature is;

a. If it is under 25, it will write "HOT"
b. If it is under 15, it will write "COLD"

The bottom line will show both humidity and temperature warning information.

## 16.

When the program starts, "A" character will be written on the 1st row and 1st column on the screen. Use the LCD Keypad Shield arrow keys to move this "A" character to the screen. It's not going to get off the screen. 

## 17.
Will be a 2-player dice-throwing game. 
When LCD Keypad Shield's left arrow key pressed, first player will dice and displayed in line 1.
When LCD Keypad Shield's right arrow key pressed, second player will dice and displayed in line 1.
Its score will increase by 1 point, which is bigger than the other player's dice. 
In case of equality, the score will not increase.
Both dice and points will be shown on the screen.
Players will not be considered if they dice consecutively.
We write the codes that perform these operations.


## ...
SPI kütüphanesini kullanarak iletişim sağlayan pinleri tam olarak hangileridir? : 10,11,12,13 

# Copyright & Licensing

The base project code is copyrighted by Furkan 'Dentrax' Türkal and is covered by single licence.

All program code (i.e. .ino, .md) is licensed under GNU v3 License unless otherwise specified. Please see the **[LICENSE.md](https://github.com/Dentrax/ArduExams/blob/master/LICENSE)** file for more information.

**References**

While this repository is being prepared, it may have been quoted from some sources.
If there is an unspecified source, please contact with me.

# Contributing

Please check the [CONTRIBUTING.md](CONTRIBUTING.md) file for contribution instructions and naming guidelines.

# Contact

ArduExams was created by Furkan 'Dentrax' Türkal

 * <https://www.furkanturkal.com>
 
You can contact by URL:
    **[CONTACT](https://github.com/dentrax)**

<kbd>Best Regards</kbd>

