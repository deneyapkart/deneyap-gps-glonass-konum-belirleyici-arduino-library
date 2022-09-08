/*
*****************************************************************************
@file         Deneyap_GPSveGLONASSkonumBelirleyici.h
@mainpage     Deneyap GPS and GLONASS Locator Arduino library header file
@version      v1.0.2
@date         September 08, 2022
@brief        This file contains all function prototypes and macros
              for Deneyap GPS and GLONASS Locator Arduino library
*****************************************************************************
*/

#ifndef __Deneyap_GPSveGLONASSkonumBelirleyici_H
#define __Deneyap_GPSveGLONASSkonumBelirleyici_H

#include <Wire.h>
#include <Arduino.h>

#define I2C_SLV_ADDR_DEFAULT (uint8_t)(0x2F)
#define I2C_SLV_ADDR_ALT1 (uint8_t)(0x54)
#define I2C_SLV_ADDR_ALT2 (uint8_t)(0x73)
#define I2C_SLV_ADDR_ALT3 (uint8_t)(0x74)

#define DATA_BUFFER_SIZE 200 // in Byte (max data size)

/* PQ Messages */
#define PQBAUD_9600 "$PQBAUD,W,9600*4B\r\n"
#define PQBAUD_57600 "$PQBAUD,W,57600*70\r\n"
#define PQBAUD_115200 "$PQBAUD,W,115200*43\r\n"

#define PQ1PPS_1ST_FIX "$PQ1PPS,W,1,100*18\r\n"
#define PQ1PPS_3D_FIX "$PQ1PPS,W,2,100*1B\r\n"
#define PQ1PPS_2D_FIX "$PQ1PPS,W,3,100*1A\r\n"
#define PQ1PPS_ALWAYS "$PQ1PPS,W,4,100*1D\r\n"
#define PQ1PPS_DISABLE "$PQ1PPS,W,0,100*19\r\n"

#define PQEPE_ENABLE "$PQEPE,W,1,1*2A\r\n"
#define PQEPE_DISABLE "$PQEPE,W,0,1*2B\r\n"

#define PQTXT_ENABLE "$PQTXT,W,1,1*22\r\n"
#define PQTXT_DISABLE "$PQTXT,W,0,1*23\r\n"

#define PQGBS_ENABLE "$PQGBS,W,1,1*2C\r\n"
#define PQGBS_DISABLE "$PQGBS,W,0,1*2D\r\n"
#define PQGBS_GET "$PQGBS,R*29\r\n"

/* PMTK Messages */
#define PMTK220_500MS "$PMTK220,500*2B\r\n"
#define PMTK220_1000MS "$PMTK220,1000*1F\r\n"
#define PMTK220_2000MS "$PMTK220,2000*1C\r\n"
#define PMTK220_5000MS "$PMTK220,5000*1B\r\n"
#define PMTK220_10000MS "$PMTK220,10000*2F\r\n"

#define PMTK605_FW_RELEASE "$PMTK605*31\r\n"

#define NMEA_TXT_ONLY "$PMTK314,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*34\r\n"
#define NMEA_GLL_ONLY "$PMTK314,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*35\r\n"
#define NMEA_RMC_ONLY "$PMTK314,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*35\r\n"
#define NMEA_VTG_ONLY "$PMTK314,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*35\r\n"
#define NMEA_GGA_ONLY "$PMTK314,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*35\r\n"
#define NMEA_GSA_ONLY "$PMTK314,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*35\r\n"
#define NMEA_GSV_ONLY "$PMTK314,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0*35\r\n"
#define NMEA_GBS_ONLY "$PMTK314,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0*35\r\n"

typedef struct { // Data packet (protocol) created by master
                // for I2C data exchange process
    uint8_t command : 3;
    uint8_t dataSize;
    uint8_t data[DATA_BUFFER_SIZE];
    char datarx[DATA_BUFFER_SIZE];
} Gps_DataPacket_TypeDef;

enum Gsm_packetCommands { // Commands in data packet (protocol)
    READ = (uint8_t)0x00,
    CONFIG,
    GPS_CHANGE_ADDR,
    GPS_REQUEST_FW_VERSION,
};

enum stdNmeaMessages { // Standard NMEA messages
    RMC = (uint8_t)0x00,
    GGA,
    GSV,
    GSA,
    VTG,
    GLL,
    TXT,
    GBS,
    DTM
};

class GPS {
public:
    /* Check device status */
    bool begin(uint8_t address = I2C_SLV_ADDR_DEFAULT, TwoWire &port = Wire);
    bool isConnected();
    uint16_t getFwVersion();
    bool setI2Caddress(uint8_t newAddress);

    /* Functions for data manipulation */
    bool readGPS(uint8_t nmeaDataType);
    uint8_t readDay();
    uint8_t readMonth();
    uint16_t readYear();
    uint8_t readHour();
    uint8_t readMinute();
    uint8_t readSecond();
    double readLocationLat();
    double readLocationLng();

    /* Config functions */
    bool sendConfigData(String str);

    uint8_t i2cData2;
    uint8_t i2cData1;

private:
    TwoWire *_i2cPort;                  // Port selection (0 or 1)
    uint8_t _i2cAddress;                // Device I2C address
    Gps_DataPacket_TypeDef _dataPacket; // Struct to transfer data over I2C interface

    /* I2C data transaction functions */
    uint8_t I2C_ReadData8bit(Gps_DataPacket_TypeDef *dataPacket);
    uint16_t I2C_ReadData16bit(Gps_DataPacket_TypeDef *dataPacket);
    uint8_t I2C_ReadData(Gps_DataPacket_TypeDef *dataPacket);
    uint16_t I2C_ReadFirmwareData16bit(Gps_DataPacket_TypeDef *dataPacket);
    bool I2C_SendDataPacket(Gps_DataPacket_TypeDef *dataPacket);
};

#endif /* __Deneyap_GPSveGLONASSkonumBelirleyici_H */
