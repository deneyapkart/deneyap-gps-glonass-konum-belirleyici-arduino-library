/*
*****************************************************************************
@file         Deneyap_GPSveGLONASSkonumBelirleyici.cpp
@mainpage     Deneyap GPS and GLONASS Locator Arduino library source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.0
@date         July 18, 2022
@brief        Includes functions to control Deneyap GPS and GLONASS Locator 
              Arduino library

Library includes:
--> Configuration functions
--> Data manipulation functions
--> I2C communication functions
*****************************************************************************
*/

#include "Deneyap_GPSveGLONASSkonumBelirleyici.h"
#include "TinyGPS/TinyGPSPlus.h"

/* Device Status Functions ---------------------------------------------------*/

/**
 * @brief  Configures I2C connection with user defined address and port
 * @param  address: I2C address of the device, port: I2C port number (0 or 1)
 * @retval connection status (1 --> connected, 0 --> not connected)
 *
 */
uint8_t rxCounter = 0;
char received_data;
TinyGPSPlus gps;

bool GPS::begin(uint8_t address, TwoWire &port) {
    Wire.begin();
#if defined(ARDUINO_DYM)
    Wire.setClock(100000);
#else
    Wire.setClock(50000);
#endif
    _i2cAddress = address;
    _i2cPort = &port;
    _dataPacket = {0};

    return isConnected();
}

/**
 * @brief  Checks whether I2C connection established
 * @param  None
 * @retval connection status (1 --> connected, 0 --> not connected)
 */
bool GPS::isConnected() {
    _i2cPort->beginTransmission(_i2cAddress);

    if (_i2cPort->endTransmission() == 0)
        return true;
    return false;
}
/**
 * @brief  Requests firmware version of the device
 * @param  None
 * @retval Device firmware version
 */
uint16_t GPS::getFwVersion() {
    _dataPacket.command = GPS_REQUEST_FW_VERSION;
    _dataPacket.dataSize = 0;
    return I2C_ReadFirmwareData16bit(&_dataPacket);
}
/**
 * @brief  Sets (changes) I2C address of the device
 * @param  address: I2C address to be set
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */

bool GPS::setI2Caddress(uint8_t newAddress) {
    _dataPacket.command = GPS_CHANGE_ADDR;
    _dataPacket.dataSize = 1;
    _dataPacket.data[0] = newAddress;

    bool status = I2C_SendDataPacket(&_dataPacket);

    if (status == true)
    {
        _i2cAddress = newAddress;
        return true;
    }
    else
    {
        return false;
    }
}

/* I2C Data Manipulation Functions -------------------------------------------*/

/*
uint8_t GPS::Read(String configMessage)
{
  static uint8_t config = 0;
  if(config == 0)
  {
    sendConfigData(configMessage);
    delay(200);
    if(configMessage == NMEA_TXT_ONLY)
      sendConfigData(PQTXT_ENABLE);
    else if(configMessage == NMEA_GBS_ONLY)
    {
      sendConfigData(PQTXT_DISABLE);
      delay(200);
      sendConfigData(PQGBS_ENABLE);
    }
    else
    {
      sendConfigData(PQTXT_DISABLE);
      delay(200);
      sendConfigData(PQGBS_DISABLE);
    }
    delay(200);
    config++;
  }

  _dataPacket.command = (uint8_t)READ;
  _dataPacket.dataSize = 1;

  return I2C_ReadData(&_dataPacket);
}
*/

/**
 * @brief
 * @param
 * @retval
 */
bool GPS::Read(uint8_t nmeaDataType) {
    _dataPacket.command = (uint8_t)READ;
    _dataPacket.dataSize = 1;
    _dataPacket.data[0] = nmeaDataType;

    return I2C_ReadData(&_dataPacket);
}

/* Configuration Funstions ---------------------------------------------------*/
/**
 * @brief
 * @param
 * @retval
 */
bool GPS::sendConfigData(String str) {
    char pqtxt[str.length()];
    str.toCharArray(pqtxt, str.length() + 1);

    _dataPacket.command = (uint8_t)CONFIG;
    _dataPacket.dataSize = str.length();

    for (uint8_t txCounter = 0; txCounter < _dataPacket.dataSize; txCounter++) {
        _dataPacket.data[txCounter] = pqtxt[txCounter];
    }

    return I2C_ReadData(&_dataPacket);
}

/* I2C Data Transaction Funstions --------------------------------------------*/

/**
 * @brief  Reads 8bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 8bit data
 */
uint8_t GPS::I2C_ReadData(Gps_DataPacket_TypeDef *dataPacket) {
    uint8_t dataSize = 0;

    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->write(dataPacket->dataSize);

    if (dataPacket->dataSize > 0) {
        for (uint8_t i = 0; i < _dataPacket.dataSize; i++)
            _i2cPort->write(_dataPacket.data[i]);
    }

    _i2cPort->endTransmission();

    _i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(1));
    while (_i2cPort->available())
        dataSize = _i2cPort->read();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(dataSize + 1)) != 0) {
        _i2cPort->read();

        for (uint8_t i = 0; i < dataSize; i++) {
            Serial.print((char)_i2cPort->read());

            //      if(gps.encode((char)_i2cPort->read()))
            //        displayInfo();
        }
    }

    return 1;
}

/**
 * @brief
 * @param
 * @retval
 */
void GPS::displayInfo() {
    Serial.print(F("Location: "));
    if (gps.location.isValid()) {
        Serial.print(gps.location.lat(), 6);
        Serial.print(F(","));
        Serial.print(gps.location.lng(), 6);
    }
    else {
        Serial.print(F("INVALID"));
    }

    Serial.print(F("  Date/Time: "));
    if (gps.date.isValid()) {
        Serial.print(gps.date.month());
        Serial.print(F("/"));
        Serial.print(gps.date.day());
        Serial.print(F("/"));
        Serial.print(gps.date.year());
    }
    else {
        Serial.print(F("INVALID"));
    }

    Serial.print(F(" "));
    if (gps.time.isValid()) {
        if (gps.time.hour() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.hour());
        Serial.print(F(":"));
        if (gps.time.minute() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.minute());
        Serial.print(F(":"));
        if (gps.time.second() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.second());
        Serial.print(F("."));
        if (gps.time.centisecond() < 10)
            Serial.print(F("0"));
        Serial.print(gps.time.centisecond());
    }
    else {
        Serial.print(F("INVALID"));
    }

    Serial.println();
}

/* I2C Data Transaction Funstions --------------------------------------------*/

/**
 * @brief
 * @param
 * @retval
 */
uint8_t GPS::I2C_ReadData8bit(Gps_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(1)) != 0)
        return _i2cPort->read();
    return 0;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t GPS::I2C_ReadData16bit(Gps_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 0) {
        uint16_t i2cData = _i2cPort->read();
        i2cData |= (_i2cPort->read() << 8);
        return i2cData;
    }
    return 0;
}

/**
 * @brief  Reads 16bit data from I2C interface
 * @param  dataPacket: includes protocol to request data
 * @retval I2C 16bit data
 */
uint16_t GPS::I2C_ReadFirmwareData16bit(Gps_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->endTransmission();

    if (_i2cPort->requestFrom(_i2cAddress, static_cast<uint8_t>(2)) != 0) {
        i2cData2 = _i2cPort->read();
        i2cData1 = _i2cPort->read();
        Serial.print("v");
        Serial.print(i2cData1);
        Serial.print(".");
        Serial.print(i2cData2);
    }
    return 0;
}

/**
 * @brief  Sends data packet based on a custom defined protocol
 * @param  dataPacket: includes all related data
 * @retval Transmission status (1 --> No error, Otherwise --> Transmission error)
 */
bool GPS::I2C_SendDataPacket(Gps_DataPacket_TypeDef *dataPacket) {
    _i2cPort->beginTransmission(_i2cAddress);
    _i2cPort->write(dataPacket->command);
    _i2cPort->write(dataPacket->dataSize);

    for (uint8_t i = 0; i < _dataPacket.dataSize; i++)
        _i2cPort->write(_dataPacket.data[i]);

    if (_i2cPort->endTransmission() == 0)
        return true;
    return false;
}