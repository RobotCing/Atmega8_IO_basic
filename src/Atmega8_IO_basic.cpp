/*
Created by RobotCing Team
*/


//--------------------------------------------
//            Library import
//--------------------------------------------
#include "Arduino.h"
#include "Atmega8_IO_basic.h"
//--------------------------------------------
Cing::Cing(){}
//--------------------------------------------
//              Motors
//--------------------------------------------
void Cing::RunMotor(String motor,int speed,String mode)
	{
		#define motorA 12
		#define motorB 11
		 #define INA1 10
		 #define INA2 9
		 #define INB1 8
		 #define INB2 7
		 pinMode(motorA,OUTPUT);
		 pinMode(motorB,OUTPUT);
		 //---------------------
		 pinMode(INA1,OUTPUT);
		 pinMode(INA2,OUTPUT);
		 pinMode(INB1,OUTPUT);
		 pinMode(INB2,OUTPUT);
		 if(mode=="digital")
			{
				int speed_set;
				if (speed == 1 || speed == -1)
					{
						speed_set = HIGH;
					}
				else if (speed == 0)
					{
						speed_set = LOW;
					}
        //--------------------------
        //           A
        //--------------------------
				if(motor=="A")
					{
						if (speed == 1)
							{
								digitalWrite(INA1,HIGH);
								digitalWrite(INA2,LOW);
								digitalWrite(motorA,speed_set);
							}
						else if (speed == -1)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,HIGH);
								digitalWrite(motorA,speed_set);
							}
						else if (speed == 0)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,LOW);
								digitalWrite(motorA,LOW);
							}
					}
				//--------------------------
				//            B
				//--------------------------
				else if(motor=="B")
					{
						if (speed == 1)
							{
								digitalWrite(INB1,HIGH);
								digitalWrite(INB2,LOW);
								digitalWrite(motorB,speed_set);
							}
						else if (speed == -1)
							{
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,HIGH);
								digitalWrite(motorB,speed_set);
							}
						else if (speed == 0)
							{
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,LOW);
								digitalWrite(motorB,LOW);
							}
					}
				//--------------------------
				//            AB
				//--------------------------
				else if(motor=="AB")
					{
						if (speed == 1)
							{
								digitalWrite(INA1,HIGH);
								digitalWrite(INA2,LOW);
								digitalWrite(INB1,HIGH);
								digitalWrite(INB2,LOW);
								digitalWrite(motorA,speed_set);
								digitalWrite(motorB,speed_set);
							}
						else if (speed == -1)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,HIGH);
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,HIGH);
								digitalWrite(motorA,speed_set);
								digitalWrite(motorB,speed_set);
							}
						else if (speed == 0)
							{
								digitalWrite(INA1,LOW);
								digitalWrite(INA2,LOW);
								digitalWrite(INB1,LOW);
								digitalWrite(INB2,LOW);
								digitalWrite(motorA,LOW);
								digitalWrite(motorB,LOW);
							}
					}
				else
					{
						digitalWrite(motorA,LOW);
						digitalWrite(motorB,LOW);
					}
			}
  }
//--------------------------------------------
//                  Sensors
//--------------------------------------------

//--------------------------------------------
//                  LightSensor
//--------------------------------------------

int Cing::ReadLightSensor(int sensor,String mode)
	{
		#define LightSensor1 A2
		#define LightSensor2 A3
		pinMode(LightSensor1,INPUT);//1
		pinMode(LightSensor2,INPUT);//2
		if (mode=="analog")
			{
				if (sensor == 1)
					{
						int value;
						value = map(analogRead(LightSensor1),0,1023,100,0);
						return value;
					}
				else if (sensor == 2)
					{
						int value;
						value = map(analogRead(LightSensor2),0,1023,100,0);
						return value;
					}
			}
			else if(mode=="digital")
			{
				if (sensor == 1)
					{
						int value;
						value = map(digitalRead(LightSensor1),0,1,1,0);
						return value;
					}
				else if (sensor == 2)
					{
						int value;
						value = map(digitalRead(LightSensor2),0,1,1,0);
						return value;
					}
				else
					{
						int value;
						value = map(digitalRead(LightSensor1),0,1,1,0);
						return value;
					}
			}
	}
//--------------------------------------------
//             ShineSensors
//--------------------------------------------
int Cing::ReadShineSensor(){
	#define ShineSensor 13
	pinMode(ShineSensor,INPUT);
	int shine_value = map(digitalRead(ShineSensor),0,1,100,0);
	return shine_value;
}
//--------------------------------------------
//               Button
//--------------------------------------------
bool Cing::ReadButton()
	{
		#define Button A6
		bool button_value;
		if(analogRead(Button)>1000){
			button_value = 1;
		}
		else{
			button_value = 0;
		}
		return button_value;
	}
//--------------------------------------------
//          ButtonExternal
//--------------------------------------------
bool Cing::ReadButtonExternal()
  {
		#define button_external 13
		pinMode(button_external,INPUT);
		bool button_external_value = digitalRead(button_external);
		return button_external_value;
  }
//--------------------------------------------
//          Potentiometer
//--------------------------------------------
int Cing::ReadPotentiometer(){
		#define potentiometer A1
		int potentiometer_value = map(analogRead(potentiometer),0,1023,0,100);
		return potentiometer_value;
}
//--------------------------------------------
//                  Shine Array
//--------------------------------------------
int Cing::ReadShineArray(int sensor){
	int value1 = map(analogRead(A0),0,1023,100,0);
	int value2 = map(analogRead(A7),0,1023,100,0);
	if(sensor == 1){
		return value1;
	}
	else{
		return value2;
	}
}
//--------------------------------------------
//           UltrasonicSensor
//--------------------------------------------
bool Cing::ReadUltrasonicSensor()
  {
    #define UltrasonicSensor 13
    pinMode(UltrasonicSensor,INPUT);
    return digitalRead(UltrasonicSensor);
  }
