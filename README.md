# Deneyap GPS and GLONASS Locator Arduino Library
[FOR TURKISH VERSION](docs/README_tr.md) ![trflag](https://github.com/deneyapkart/deneyapkart-arduino-core/blob/master/docs/tr.png)

***** Add photo ****

Arduino library for Deneyap GPS and GLONASS Locator

## :mag_right:Specifications 
- `Product ID` **M45**, **mpv1.0**
- `MCU` STM8S003F3, Quectel L86
- `Battery Housing`  CR1220
- `Weight` 
- `Module Dimension` 25,4 mm x 38,1 mm
- `I2C address` 0x2F, 0x54, 0x73, 0x74

| Address |  | 
| :---      | :---     |
| 0x2F| default address |
| 0x54| address when ADR1 pad is shorted |
| 0x73| address when ADR2 pad is shorted |
| 0x74| address when ADR1 and ADR2 pads are shorted |

## :closed_book:Documentation
[Deneyap GPS and GLONASS Locator](https://docs.deneyapkart.org/en/content/contentDetail/deneyap-module-deneyap-gnss-m45)

[Deneyap GPS and GLONASS Locator Schematic](https://cdn.deneyapkart.org/media/upload/userFormUpload/GEc26oFEFkPIzMT9PunlPEBJIslaoo2c.pdf)

[Deneyap GPS and GLONASS Locator Mechanical Drawing](https://cdn.deneyapkart.org/media/upload/userFormUpload/Tyb470HrWmP4LJhrUGRGxiijpXCzBPN6.pdf)

[Quectel L86 - datasheet](https://www.quectel.com/wp-content/uploads/pdfupload/Quectel_L86_GNSS_Specification_V1.3.pdf)

[How to install a Arduino Library](https://docs.arduino.cc/software/ide-v1/tutorials/installing-libraries)

## :pushpin:Deneyap GPS and GLONASS Locator
This Arduino library allows you to use Deneyap GPS and GLONASS Locator with I2C peripheral. You can use this library in your projects with any Arduino compatible board with I2C peripheral.

## :globe_with_meridians:Repository Contents
- `/docs ` README_tr.md and product photos
- `/examples ` Examples with .ino extension sketches
- `/src ` Source files (.cpp .h)
- `keywords.txt ` Keywords from this library that will be highlighted in the Arduino IDE
- `library.properties ` General library properties for the Arduino package manager

## Version History
1.0.2 - add new functions

1.0.1 - bug fix

1.0.0 - initial release

## :rocket:Hardware Connections
- Deneyap GPS and GLONASS Locator and Board can be connected with I2C cable
- or 3V3, GND, SDA and SCL pins can be connected with jumper cables

|GPS and GLONASS Locator| Function | Board pins | 
|:--- |   :---  | :---|
|3.3V | Power   |3.3V |      
|GND  | Ground  | GND | 
|SDA  | I2C Data  | SDA pin |
|SCL  | I2C Clock | SCL pin |
|SWIM | Debug | no connection |
|RES  | Debug | no connection |
|TX| Transmit pin | |
|RX|  Receive pin | |
|ADDET_N		||
|RES_N			||
|FORCE			||
|1PPS			||

## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-gps-glonass-konum-belirleyici-arduino-library/blob/master/LICENSE) file for license information.
