/************************************************
*                这是电话本管理程序的主程序文件。
* 
*
************************************************/

#include  <stdio.h>
#include <Windows.h>
#include "flight.h"       

//显示程序信息
void displaymenu( );

int main()
{
	int  option = 0;	

	//从文件中读出数据并插入链表中
	ReadDataFromFile("flight.dat");

	do
	{
		//提示用户选择操作
		displaymenu();
		
		scanf("%d", &option);
        getchar();

		//根据用户选择调用相关函数完成指定的操作
		switch(option )
		{
		//打印所有记录信息
		case 1:   
			displayall();
			break;
			
		//查询航班
		case 2:
			search();
	   		break;
        
		//预定航班
		case 3:
			bookticket();
			break;
	
		default: 			
			break;
		}
	}while(option != 0 );	
	

}

//显示程序信息
void displaymenu( )
{
	system("CLS");
	puts(" ");
	puts("********************************************************************" );
	puts("                     欢迎使用非常小航班系统V1.0" );
	puts("********************************************************************\n" );
	puts(" ");
	puts("请选择操作：\n" );
	puts("0：退出系统\n" );
	puts("1：显示所有航班信息\n") ;
	puts("2：查询航班信息\n") ;	
	puts("3：购票\n" );
//	system("pause");
}

