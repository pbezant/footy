/*
   -- New project --
   
   This source code of graphical user interface 
   has been generated automatically by RemoteXY editor.
   To compile this code using RemoteXY library 3.1.13 or later version 
   download by link http://remotexy.com/en/library/
   To connect using RemoteXY mobile app by link http://remotexy.com/en/download/                   
     - for ANDROID 4.15.01 or later version;
     - for iOS 1.12.1 or later version;
    
   This source code is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.    
*/

//////////////////////////////////////////////
//        RemoteXY include library          //
//////////////////////////////////////////////


// you can enable debug logging to Serial at 115200
// #define REMOTEXY__DEBUGLOG    
// #define REMOTEXY_DEBUGLOG_SPEED 115200

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__ESP32CORE_BLE

#include <BLEDevice.h>

// RemoteXY connection settings 
#define REMOTEXY_BLUETOOTH_NAME "Footy"

#include <RemoteXY.h> 


// RemoteXY GUI configuration  
#pragma pack(push, 1)  
uint8_t RemoteXY_CONF[] =   // 103 bytes
  { 255,2,0,0,0,96,0,19,0,0,0,0,31,2,106,200,200,84,1,1,
  5,0,4,41,46,20,92,23,16,12,68,64,2,26,4,1,171,104,16,112,
  35,89,14,176,2,26,129,40,151,26,8,145,23,26,8,64,17,82,117,100,
  100,101,114,0,129,34,32,35,9,13,5,40,8,64,17,77,97,105,110,32,
  83,104,101,101,116,0,129,36,6,30,12,85,3,30,12,64,17,70,111,111,
  116,121,0 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t mainSheet; // from 0 to 100
  int8_t rudder; // from -100 to 100

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0

} RemoteXY;   
#pragma pack(pop)
 
/////////////////////////////////////////////
//           END RemoteXY include          //
/////////////////////////////////////////////

#include <ESP32Servo.h>

#define PIN_RUDDER 6
#define PIN_MAINSHEET 7

Servo rudder;
Servo mainSheet;

int rudderPosition = 0;
void setup() 
{
  RemoteXY_Init (); 
  
  rudder.setPeriodHertz(50);
  rudder.attach(PIN_RUDDER, 500, 2400);

  mainSheet.setPeriodHertz(50);
  mainSheet.attach(PIN_MAINSHEET, 500, 2400);
  
  // RemoteXY.rudder = rudderPosition;
}

void loop() 
{ 
  RemoteXY_Handler ();
  // TODO you loop code
  // use the RemoteXY structure for data transfer
  // do not call delay(), use instead RemoteXY_delay() 


    rudder.write(-0.54*RemoteXY.rudder+90);
    mainSheet.write(((100-RemoteXY.mainSheet)*.01)*90); //reverse value converts to decimal of range
}