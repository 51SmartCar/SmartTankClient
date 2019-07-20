#include "DeviceAction.h"
#include "STC15W4K58S4.h"
#include "Delay.h"


sbit LED      =  P5 ^ 4;         		  // LED��
sbit Buzzer    =  P5 ^ 5;           	// ������

//sbit MOTORIN1 =  P1 ^ 5;          		// ���Ƶ������
//sbit MOTORIN2 =  P1 ^ 6;          	  // ���Ƶ������

sbit RIGHT_MOTORENB =  P1 ^ 2;          		// RIGHT ENB
sbit RIGHT_MOTORIN1 =  P1 ^ 3;          		// ���Ƶ������
sbit RIGHT_MOTORIN2 =  P1 ^ 4;          	  // ���Ƶ������


sbit LEFT_MOTORENA =  P1 ^ 5;          		// LEFT ENA
sbit LEFT_MOTORIN1 =  P1 ^ 6;          		// ���Ƶ������
sbit LEFT_MOTORIN2 =  P1 ^ 7;          	  // ���Ƶ������




/////�����ǰ����״̬  ǰ��1 ����2  ɲ��0
//unsigned char Motor_CurrentStatus(void){
//	
//	if(MOTORIN1==1 && MOTORIN2==0){//ǰ��
//		return 1;
//	}else if(MOTORIN1==0 && MOTORIN2==1){//����
//		return 2;
//	}else if(MOTORIN1==0 && MOTORIN2==0){//ɲ��
//		return 0;
//	}
//	
//}


///���Ƶ��ǰ���� ���������һ�������������
//���� 0 1
//ǰ�� 1 0
//ֹͣ 0 0 

void Motor_Actions_Status(unsigned char motor1, unsigned char motor2){
		
//		RIGHT_MOTORENB = 1;//�������ֱ������Ϊȫ��
//		LEFT_MOTORENA = 1;
	
	if(motor1==1 && motor2==0 ){//ǰ��
		
		RIGHT_MOTORIN1 = 1;
		RIGHT_MOTORIN2 = 0;
		
		LEFT_MOTORIN1 = 1;
		LEFT_MOTORIN2 = 0;
		
	}else if(motor1==0 && motor2==1){//����
		
		RIGHT_MOTORIN1 = 0;
		RIGHT_MOTORIN2 = 1;
		
		LEFT_MOTORIN1 = 0;
		LEFT_MOTORIN2 = 1;
		
	}else {//ֹͣ
		
		RIGHT_MOTORIN1 = 0;
		RIGHT_MOTORIN2 = 0;
		
		LEFT_MOTORIN1 = 0;
		LEFT_MOTORIN2 = 0;
		
	}
	
	
}



///���Ƶ�����ҷ��� ���������һ�������������
//��ת 0 1
//��ת 1 0
//���� 0 0 

void Motor_Turn_Status(unsigned char motor1, unsigned char motor2){
		
//		RIGHT_MOTORENB = 1;//�������ֱ������Ϊȫ��
//		LEFT_MOTORENA = 1;
	
	if(motor1==1 && motor2==0 ){//��ת
		
		RIGHT_MOTORIN1 = 0;
		RIGHT_MOTORIN2 = 1;
		
		LEFT_MOTORIN1 = 1;
		LEFT_MOTORIN2 = 0;
		
	}else if(motor1==0 && motor2==1){//��ת
		
		RIGHT_MOTORIN1 = 1;
		RIGHT_MOTORIN2 = 0;
		
		LEFT_MOTORIN1 = 0;
		LEFT_MOTORIN2 = 1;
		
	}else {//ֹͣ
		
		RIGHT_MOTORIN1 = 0;
		RIGHT_MOTORIN2 = 0;
		
		LEFT_MOTORIN1 = 0;
		LEFT_MOTORIN2 = 0;
		
	}
	
	
}

///LED  ���ƿ���

void Led_Actions_Status(unsigned char status){

	if(status){
		LED = 1;
	}else{
		LED = 0;
	}
	
}

///Buzzer   1��  0�� 

void Buzzer_Actions_Status(unsigned char status){

	if(status){
		Buzzer = 0;
	}else{
		Buzzer = 1;
	}

}

///LED��˸  ����  ʱ��

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

///Buzzer����  ����  ʱ��

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

///LED��˸  Buzzer����  ����  ʱ��

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
