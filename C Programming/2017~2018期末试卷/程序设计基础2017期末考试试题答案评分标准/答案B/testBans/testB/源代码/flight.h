#ifndef _FLIGHT_H_
#define _FLIGHT_H_

typedef  struct 
{	 
	char  cityfrom;      //��������
	char  cityto;      //�������
	int   depttime;      //����ʱ��24Сʱ��
	int   flttime;     //����ʱ��������12Сʱ
	int   tcktnum;        //ʣ��Ʊ��
	int   price;		//�۸�
	int   fltno;     //������

}FLIGHT;


void displayall();
void displaysingle(int n);
void search();
int bookticket();
void bubblesortflight() ;
int  ReadDataFromFile( const char *filename );

#endif