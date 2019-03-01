/*
Created by RobotCing Team
*/
#ifndef Atmega8_IO_basic
#define Atmega8_IO_basic
#include "Arduino.h"
//--------------------------------------------
//              Creating Class
//--------------------------------------------
class Cing
{
// public variables
  public:
//constructor
    Cing();
    void RunMotor(String motor,int speed= 100,String mode = "digital");
    int ReadLightSensor(int sensor = 1,String mode = "digital");
    int ReadUltrasonicSensor();
    int ReadShineSensor();
    bool ReadButton();
    bool ReadButtonExternal();
    int ReadPotentiometer();
    int ReadShineArray(int sensor=1);
// local variables
  private:
};
#endif
