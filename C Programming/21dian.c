#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void print(float s1, float s2);

float transform(int paper);

void main() {
	char input;
	float sum1 = 0, sum2 = 0;//sum1�Ǽ��������ͣ�sum2���û������
	
	while ((input = getchar()) == 'y'|| (input = getchar()) == 'Y') {
		
		srand(time(0));
		int paper1 = rand() % 13 + 1;
		
		//srand(time(0));
		int paper2 = rand() % 13 + 1;//����1~13�������

		float num1 = transform(paper1);//����ͷ�ֵ��ת��
		float num2 = transform(paper2);

		sum1 += num1;
		sum2 += num2;

		printf("��ǰ����ͣ�%f", sum2);
		printf("�Ƿ����Ҫ�ƣ�(y/n)\n");
		getchar();
	}
	print(sum1, sum2);

	if (sum1 > 21 && sum2 > 21) {	
		printf("���ͼ���������ˣ�\n");
	}
	else if (sum1 > 21 && sum2 <= 21) {
		printf("��Ӯ�ˣ�\n");
	}
	else if (sum1 <= 21 && sum2 > 21) {
		printf("�����ˣ�\n");
	}
	else {
		if (sum1 < sum2) {
			printf("��Ӯ�ˣ�\n");
		}
		else if (sum1 > sum2) {
			printf("�����ˣ�\n");
		}
		else {
			printf("ƽ�֣�\n");
		}
	}
	
	system("pause");
}

float transform(int paper) {
	float num;
	if (paper >= 11 && paper <= 13) {
		num = 0.5;
	}
	else {
		num = (float)paper;
	}
	return num;
}

void print(float s1,float s2) {//��ӡ����
	printf("���ķ�ֵ��%f\n", s2);
	printf("������ķ�ֵ��%f\n", s1);
}