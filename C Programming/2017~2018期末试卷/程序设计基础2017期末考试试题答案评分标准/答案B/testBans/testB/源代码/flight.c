#include  <stdio.h>
#include  <Windows.h>
#include <time.h>
#include <stdlib.h>
#include "flight.h"

#define SIZE 50


int g_num = 0; //ȫ�ֱ��������������Ч��Ƭ��
FLIGHT  flightary[SIZE] ;//ȫ�ֱ�������Ƭ����


/*�Դ��ļ�����������к�����Ϣ����������������ʾ*/
/*
����: �� ʹ��ȫ������flightary
����:��
�������Ƿ���Ҫ�޸ģ���
 */ 
void displayall()
{
	int i;
	//��������������������
	bubblesortflight() ;
	
	puts("No  �����  ��������   �������   ���ʱ��   ����ʱ��\t\t��Ʊ��   ����\n");
	for(i=0;i<g_num;i++)
	{
		displaysingle(i);
	}
	system("pause");
}


/*��ʾĳһ��������Ϣ*/
/*
����: n����ʾ�ǽṹ�������еĵڼ�����Ϣ�����±�)
����:��
�������Ƿ���Ҫ�޸ģ���
 */ 
void displaysingle(int n)
{
	int temphour=0;
	printf("%2d   %2d  \t%c\t  %c\t  %2d\t\t",n,flightary[n].fltno,flightary[n].cityfrom,flightary[n].cityto,flightary[n].depttime);
	temphour=flightary[n].depttime+flightary[n].flttime;
	if(temphour>24)
		printf("%2d+1day\t\t",temphour%24);
	else
		printf("%2d\t\t",temphour);

	printf("%2d\t   %2d\n",flightary[n].tcktnum,flightary[n].price);
}

/*��ɺ�����Ϣ����������*/
/*
����Ҫ��˵����������������ĸ��С��������������������ĸ������һ�������������ĸ��С��������
�������͵�����ж�������һ�����������ʱ����С�������򣬺������ʱ�����������ٽ������⴦��
������ʹ�����������㷨��������ʹ�ÿ⺯����������
�粻���������˵����۲���Ŀ�������ѯ�ʼ࿼��ʦ
����: �ޣ�ʹ��ȫ������flightary
����: ��
��������Ҫ���б�д������displayall��ʼִ�д������ã�����ָ���Ѿ�д��
 */ 
 void bubblesortflight() 
  {
	   unsigned int pass;
	   unsigned int i;
	   for (pass = 1; pass < g_num; ++pass) {                   
	                                                             
	      // loop to control number of comparisons per pass   
	      for (i = 0; i < g_num - 1; ++i) {                     
	                                                             
	         // compare adjacent elements and swap them if first 
	         // element is greater than second element           
			  if (flightary[i].cityfrom > flightary[i + 1].cityfrom ) {                        
	            FLIGHT hold = flightary[i];                                   
	            flightary[i] = flightary[i + 1];                             
	            flightary[i + 1] = hold;                               
	         }    

			  if (flightary[i].cityfrom == flightary[i + 1].cityfrom && flightary[i].cityto > flightary[i + 1].cityto ) {                        
	            FLIGHT hold = flightary[i];                                   
	            flightary[i] = flightary[i + 1];                             
	            flightary[i + 1] = hold;                                
	         }  

			  if (flightary[i].cityfrom == flightary[i + 1].cityfrom && flightary[i].cityto == flightary[i + 1].cityto && flightary[i].depttime > flightary[i + 1].depttime ) {                        
	            FLIGHT hold = flightary[i];                                   
	            flightary[i] = flightary[i + 1];                             
	            flightary[i + 1] = hold;                                
	         }  
	      }                                   
	   }
  }

/*���ڸ��ݳ������к͵�����в�ѯ����Щ����*/
/*
Ҫ���û��������������ĸ�͵��������ĸ��Ȼ����������������Ϣȫ��������˴�����Ҫ�������򣬽����ݶ����������˳����н����ʾ��������Ʊ���Ƿ�Ϊ0
��ʾ��ʽ��	puts("No  �����  ��������   �������   ���ʱ��   ����ʱ��\t\t��Ʊ��   ����\n"); 
����: �ޣ�ʹ��ȫ������flightary
����: ��
��������Ҫ���б�д��ע��������
 */ 
void search()
{
	int i,j;
	char from,to;
	do{
		puts("�������������<C for Chendu  B for Beijing  X for Xian>: ");
		scanf("%c",&from);
		getchar();
	}while(from != 'C'&& from !='B'&& from !='X');
	
	
	do{
		puts("�����뵽�����<C for Chendu  B for Beijing  X for Xian>: ");
		scanf("%c",&to);
		getchar();
	}while(to != 'C' && to !='B'&& to !='X');

	
	printf("\n");
	puts("No  �����  ��������   �������   ���ʱ��   ����ʱ��\t\t��Ʊ��   ����\n");
	for(i=0;i<g_num;i++)
	{
		if(flightary[i].cityfrom==from && flightary[i].cityto==to)
		{
			displaysingle(i);
		}
	}

	system("pause");
}


/*Ԥ����Ʊ*/
/*
Ҫ���û����뺽���2λ��ţ�ע�ⲻ��NO����ʾ�ú������Ʊ��
����Ҫ���û��������蹺Ʊ��Ŀ��
�����Ʊ��������Ʊ������ʾ����Ʊ��������Ʊ����Ʊʧ�ܡ�
�����Ʊ��С�ڵ�����Ʊ����������Ʊ��������ɳ��е�������У����ʱ���Ӧ���Ĺ�Ʊ�ܽ��
���δ��ѯ������ţ����δ�ҵ�����ţ�����-1 
����: �ޣ�ʹ��ȫ������flightary
����: ���ͣ��ɹ����ع�Ʊ����ʧ�ܷ���-1
��������Ҫ���б�д��ע��������
 */ 
int bookticket()
{
	int i=0,flightno=0;
	int booknum = 0;
	
	do{
		printf("�����뺽����: ");
		scanf("%d",&flightno);
	}while(flightno <10 || flightno > 99);

	for(i=0;i<g_num;i++)
	{
		if(flightno == flightary[i].fltno && flightary[i].tcktnum > 0)
		{
			printf("Ŀǰ��Ʊ%d�������빺Ʊ��<x x>: ",flightary[i].tcktnum);
			scanf("%d",&booknum);
			if(booknum > flightary[i].tcktnum)
			{
				printf("��Ʊ��Ŀ���������ι�Ʊʧ��\n");
				system("pause");
				return -1;
			}
			else
			{
				printf("���ѳɹ���Ʊ%d�ţ�%c��%c�����ʱ��%d��Ӧ���ܽ��%d\n",booknum,flightary[i].cityfrom,flightary[i].cityto,flightary[i].depttime,booknum*flightary[i].price);
				flightary[i].tcktnum -= booknum;
				system("pause");
				return booknum;
			}
		}
	}
	
	printf("δ���ҵ��ú���ţ�\n");
	system("pause");
	return -1;
}

/*���ļ��ж�ȡ������Ϣ*/
/*
�Խṹ��Ԫ��Ϊ��λ��ָ���ļ���ȡ������Ϣ
����: �����ļ��������ļ��Ѿ��ʹ��������һ��
����: ���ͣ��ɹ�����1��ʧ�ܷ���0
����������Ҫ����һ�д��룬�����while�еı��ʽ
 */ 
int  ReadDataFromFile( const char *filename )
{
	//�������
	memset(flightary,0,sizeof(FLIGHT)*SIZE);
	g_num=0;

	FILE   *pfile;         //�ļ�ָ��
	//�򿪱�����Ϣ�������ļ�
	pfile = fopen(filename, "rb" );
	if(pfile == NULL)
	{
		printf("�ļ���ʧ��!\n" );
		return 0;
	}

	// ���ļ��ж�ȡһ����Ա����Ϣ���ŵ�����β��
	while(fread(&flightary[g_num], sizeof(FLIGHT), 1, pfile) == 1 )
	{
		g_num++;  
		if(g_num >= SIZE)
		{
			printf("Reach max storage capability! Stop reading from file!\n");
			break;
		}
	}

	fclose(pfile );	
	return 1;

}
