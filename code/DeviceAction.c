#include "DeviceAction.h"
#include "STC15W4K58S4.h"
#include "Delay.h"


sbit LED      =  P5 ^ 4;         		  // LED灯
sbit Buzzer    =  P5 ^ 5;           	// 蜂鸣器

sbit MOTORIN1 =  P1 ^ 5;          		// 控制电机方向
sbit MOTORIN2 =  P1 ^ 6;          	  // 控制电机方向

sbit RIGHT_MOTORENB =  P1 ^ 2;          		// RIGHT ENB
sbit RIGHT_MOTORIN1 =  P1 ^ 3;          		// 控制电机方向
sbit RIGHT_MOTORIN2 =  P1 ^ 4;          	  // 控制电机方向


sbit LEFT_MOTORENA =  P1 ^ 5;          		// LEFT ENA
sbit LEFT_MOTORIN1 =  P1 ^ 6;          		// 控制电机方向
sbit LEFT_MOTORIN2 =  P1 ^ 7;          	  // 控制电机方向




/////电机当前运行状态  前进1 后退2  刹车0
//unsigned char Motor_CurrentStatus(void){
//	
//	if(MOTORIN1==1 && MOTORIN2==0){//前进
//		return 1;
//	}else if(MOTORIN1==0 && MOTORIN2==1){//后退
//		return 2;
//	}else if(MOTORIN1==0 && MOTORIN2==0){//刹车
//		return 0;
//	}
//	
//}


///控制电机前后方向： 两个电机，一个电机两个引脚
//后退 0 1
//前进 1 0
//停止 0 0 

void Motor_Actions_Status(unsigned char motor1, unsigned char motor2){
		
//		RIGHT_MOTORENB = 1;//两个电机直接设置为全速
//		LEFT_MOTORENA = 1;
	
	if(motor1==1 && motor2==0 ){//前进
		
		RIGHT_MOTORIN1 = 1;
		RIGHT_MOTORIN2 = 0;
		
		LEFT_MOTORIN1 = 1;
		LEFT_MOTORIN2 = 0;
		
	}else if(motor1==0 && motor2==1){//后退
		
		RIGHT_MOTORIN1 = 0;
		RIGHT_MOTORIN2 = 1;
		
		LEFT_MOTORIN1 = 0;
		LEFT_MOTORIN2 = 1;
		
	}else {//停止
		
		RIGHT_MOTORIN1 = 0;
		RIGHT_MOTORIN2 = 0;
		
		LEFT_MOTORIN1 = 0;
		LEFT_MOTORIN2 = 0;
		
	}
	
	
}



///控制电机左右方向： 两个电机，一个电机两个引脚
//左转 0 1
//右转 1 0
//居中 0 0 

void Motor_Turn_Status(unsigned char motor1, unsigned char motor2){
		
//		RIGHT_MOTORENB = 1;//两个电机直接设置为全速
//		LEFT_MOTORENA = 1;
	
	if(motor1==1 && motor2==0 ){//左转
		
		RIGHT_MOTORIN1 = 0;
		RIGHT_MOTORIN2 = 1;
		
		LEFT_MOTORIN1 = 1;
		LEFT_MOTORIN2 = 0;
		
	}else if(motor1==0 && motor2==1){//右转
		
		RIGHT_MOTORIN1 = 1;
		RIGHT_MOTORIN2 = 0;
		
		LEFT_MOTORIN1 = 0;
		LEFT_MOTORIN2 = 1;
		
	}else {//停止
		
		RIGHT_MOTORIN1 = 0;
		RIGHT_MOTORIN2 = 0;
		
		LEFT_MOTORIN1 = 0;
		LEFT_MOTORIN2 = 0;
		
	}
	
	
}

///LED  控制开关

void Led_Actions_Status(unsigned char status){

	if(status){
		LED = 1;
	}else{
		LED = 0;
	}
	
}

///Buzzer   1关  0开 

void Buzzer_Actions_Status(unsigned char status){

	if(status){
		Buzzer = 0;
	}else{
		Buzzer = 1;
	}

}

///LED闪烁  次数  时间

void Led_Actions_NumAndMS(unsigned char  number,unsigned char ms){
	
	if(number>0 && ms>0){
	
		while(number){
				number--;
				LED = 1;
				DELAY_MS(ms);
				LED = 0;
				if(number){
				   DELAY_MS(ms);
				}
		}
	}
}

///Buzzer声音  次数  时间

void Buzzer_Actions_NumAndMS(unsigned char  number,unsigned char ms){
	
	if(number>0 && ms>0){
	
		while(number){
				number--;
				Buzzer = 0;
				DELAY_MS(ms);
				Buzzer = 1;
				if(number){
				   DELAY_MS(ms);
				}
		}
	}
}

///LED闪烁  Buzzer声音  次数  时间

void LedAndBuzzer_Actions_NumAndMS(unsigned char  number,unsigned char ms){
	
	if(number>0 && ms>0){
	
		while(number){
				number--;
				LED = 1;
				Buzzer = 0;
				DELAY_MS(ms);
				LED = 0;
				Buzzer = 1;
				if(number){
				   DELAY_MS(ms);
				}
		}
	}
}
