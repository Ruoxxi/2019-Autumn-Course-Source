/************************************************
*                ���ǵ绰�����������������ļ���
* 
*
************************************************/

#include  <stdio.h>
#include <Windows.h>
#include "flight.h"       

//��ʾ������Ϣ
void displaymenu( );

int main()
{
	int  option = 0;	

	//���ļ��ж������ݲ�����������
	ReadDataFromFile("flight.dat");

	do
	{
		//��ʾ�û�ѡ�����
		displaymenu();
		
		scanf("%d", &option);
        getchar();

		//�����û�ѡ�������غ������ָ���Ĳ���
		switch(option )
		{
		//��ӡ���м�¼��Ϣ
		case 1:   
			displayall();
			break;
			
		//��ѯ����
		case 2:
			search();
	   		break;
        
		//Ԥ������
		case 3:
			bookticket();
			break;
	
		default: 			
			break;
		}
	}while(option != 0 );	
	

}

//��ʾ������Ϣ
void displaymenu( )
{
	system("CLS");
	puts(" ");
	puts("********************************************************************" );
	puts("                     ��ӭʹ�÷ǳ�С����ϵͳV1.0" );
	puts("********************************************************************\n" );
	puts(" ");
	puts("��ѡ�������\n" );
	puts("0���˳�ϵͳ\n" );
	puts("1����ʾ���к�����Ϣ\n") ;
	puts("2����ѯ������Ϣ\n") ;	
	puts("3����Ʊ\n" );
//	system("pause");
}

