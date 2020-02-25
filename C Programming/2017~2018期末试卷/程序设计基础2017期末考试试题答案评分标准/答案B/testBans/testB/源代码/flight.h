#ifndef _FLIGHT_H_
#define _FLIGHT_H_

typedef  struct 
{	 
	char  cityfrom;      //出发城市
	char  cityto;      //到达城市
	int   depttime;      //出发时间24小时制
	int   flttime;     //飞行时长不超过12小时
	int   tcktnum;        //剩余票额
	int   price;		//价格
	int   fltno;     //航班编号

}FLIGHT;


void displayall();
void displaysingle(int n);
void search();
int bookticket();
void bubblesortflight() ;
int  ReadDataFromFile( const char *filename );

#endif