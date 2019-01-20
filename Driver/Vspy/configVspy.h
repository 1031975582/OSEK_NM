//���ݲ�ͬ��ƽ̨�������ã����ú������ֲ����ͬƽ̨
#ifndef CONFIGH_H
#define CONFIGH_H

#define VSPY  //��ʹ��Vspy�ͽ���ע�͵�
#include"../../OsekNM_core/OsekNM.h"

/*ƽ̨�޹صĶ���*/
typedef unsigned char TimerOutFlag_t;

//����ʱ�����ͣ�δ��ʼ��(δ����InitDirectNMParams)��Щ�����������涨���
//��������ĵ�ID
#define NMID 0x18ffA019

//���ýڵ�Դ��ַ,�ڵ��ַ����Ϊ0
#define ADDR_SELF 0x19

#define NM_TIMETYPE_TTYP     100
#define NM_TIMETYPE_TMAX     260
#define NM_TIMETYPE_TERROR   1000
#define NM_TIMETYPE_TWBS     5000
//���嶨ʱ������
#define NM_TIMER_TTYP    0
#define NM_TIMER_TMAX    1
#define NM_TIMER_TERROR  2
#define NM_TIMER_TWBS    3
//����ֵ����
#define E_OK     0
#define E_ERROR -1
//ƽ̨��صĶ���
//#define OSEKOS //��Ҫʹ��OSEKOS

//#define PRINT

#include"../../../vspy.h"
#pragma comment(lib, "Winmm.lib")
//#include <stdio.h>
#include <Windows.h>
#include <Mmsystem.h>
char SetToFIFO(GenericMessage* msg);
char GetFromFIFO(NMPDU_t* msg);
void ClearFIFO(void);
void InitPlatform();
void InitNMPDU();
NMTypeU8_t TX_CAN_Transmit(NMPDU_t* NMPDU);
TimerOutFlag_t GetTimerIsOut(NMTimerType_t TimerType);
void ClcTimerOutFlag(NMTimerType_t TimerType);


//��ʹ��OS�Ļ���ʹ���Զ���Ķ�ʱ������
#ifndef OSEKOS
int SetAlarm(NMTimerType_t timer);
void CancelAlarm(NMTimerType_t timer);
#endif

//FIFO��С
#define FIFOMAX 20

//���ܱ���FIFO
typedef struct {
	GenericMessage MSGs[FIFOMAX];//FIFO������
	char Total;//FIFO�еı�������
	char Head;//ָ�����ͷ
	char Tail;//ָ���β
	char FullFlag;//��������
	char EmptyFlag;//��������
	char(*GetMsg) (NMPDU_t* msg); //�ӻ�������ȡ����
	char(*SetMsg) (GenericMessage* smsg); //���뱨�ĵ�������
	void(*ClearBuff)(void);//���FIFO
}RecvFIFO_t;
#endif

