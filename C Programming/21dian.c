#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void print(float s1, float s2);

float transform(int paper);

void main() {
	char input;
	float sum1 = 0, sum2 = 0;//sum1是计算机牌面和，sum2是用户牌面和
	
	while ((input = getchar()) == 'y'|| (input = getchar()) == 'Y') {
		
		srand(time(0));
		int paper1 = rand() % 13 + 1;
		
		//srand(time(0));
		int paper2 = rand() % 13 + 1;//产生1~13的随机数

		float num1 = transform(paper1);//牌面和分值的转换
		float num2 = transform(paper2);

		sum1 += num1;
		sum2 += num2;

		printf("当前牌面和：%f", sum2);
		printf("是否继续要牌？(y/n)\n");
		getchar();
	}
	print(sum1, sum2);

	if (sum1 > 21 && sum2 > 21) {	
		printf("您和计算机都输了！\n");
	}
	else if (sum1 > 21 && sum2 <= 21) {
		printf("您赢了！\n");
	}
	else if (sum1 <= 21 && sum2 > 21) {
		printf("您输了！\n");
	}
	else {
		if (sum1 < sum2) {
			printf("您赢了！\n");
		}
		else if (sum1 > sum2) {
			printf("您输了！\n");
		}
		else {
			printf("平局！\n");
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

void print(float s1,float s2) {//打印分数
	printf("您的分值：%f\n", s2);
	printf("计算机的分值：%f\n", s1);
}