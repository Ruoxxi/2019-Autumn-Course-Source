/*4.5
(a)for语句中括号内应用分号分隔
(b)两条case语句中遗忘了break
(c)scanf会扫描输入的字符直到出现空格或回车，因此会把字符也扫描进去。应定义一个char型数组存入输入的字符，再把最后一个字符和其他字符分隔开。
(d)循环条件应为x<=0.001,否则不进入for循环
(e)应改为x-=2
(f)while条件应为counter<=100;否则100不会输出
(g)for括号之后多了一个分号，语法错误
*/

/*
#include <stdio.h>

int main() {
	int i, t;
	printf("A");
	for (i = 1; i <= 10; i++) {
		for (t = 1; t < i; t++) {
			printf("%s", "*");
		}
		printf("%s\n", "*");
	}
	printf("\n\nB\n");
	for (i = 10; i >=1; i--) {
		for (t = 1; t < i; t++) {
			printf("%s", "*");
		}
		printf("%s\n", "*");
	}
	printf("\n\nC\n");
	int s;
	for (i = 10; i >= 1; i--) {
		for (s = 10; s > i; s--) {
			printf(" ");
		}
		for (t = 1; t < i; t++) {
			printf("%s", "*");
		}
		printf("%s\n", "*");
	}
	printf("\n\nD\n");
	for (i = 10; i >= 1; i--) {
		for (t = 1; t < i; t++) {
			printf(" ");
		}
		for (s = 10; s > i; s--) {
			printf("%s","*");
		}

		printf("%s\n", "*");
	}
	system("pause");
}*/
/*4.28
#include <stdio.h>

int main() {
	int type;
	printf("请输入员工编号：");
	scanf_s("%d", &type);
	while (type == 1 || type == 2 || type == 3 || type == 4) {
		switch (type) {
		case 1:
			printf("输入经理的周薪：");
			double salary1;
			scanf_s("%lf", &salary1);
			printf("经理的周薪为：%lf\n", salary1);
			break;
		case 2:
			printf("请输入计时工工作的小时：");
			double hour, salary2;
			scanf_s("%lf", &hour);
			printf("请输入计时工每小时的工资：");
			double hosa;
			scanf_s("%lf", &hosa);
			if (hour <= 40) {
				salary2 = hour * hosa;
			}
			else {
				salary2 = 40 * hosa + (hour - 40)*1.5*hosa;
			}
			printf("计时工的工资为：%lf\n", salary2);
			break;
		case 3:
			printf("请输入该周销量总额：");
			double num;
			scanf_s("%lf", &num);
			double salary3;
			salary3 = 250 + 0.05*num;
			printf("代办工的周薪为：%lf\n", salary3);
			break;
		case 4:
			printf("请输入每件产品的报酬：");
			int num4;
			double presa;
			scanf_s("%lf", &presa);
			printf("请输入计件工生产产品的数量：");
			scanf_s("%d", &num4);
			double salary4;
			salary4 = num4 * presa;
			printf("计件工周薪为：%lf\n", salary4);
			break;
		}
		printf("请输入员工编号：");
		scanf_s("%d", &type);
	}5
}*/

/*a
#include <stdio.h>

#define max 10000
void out(char str[max], int i);
int main() {
	char str[max];
	int i = 0;
	while ((str[i] = getchar())!='\n') {
		i++;
	}
	i--;
	out(str, i);
	system("pause");
}
void out(char str[max],int i) {
	int len = i;
	int temp;
	for (; i > 0; i -= 2) {
		temp = str[i];
		str[i] = str[i - 1];
		str[i - 1] = temp;
	}
	for (i = 0; i <= len; i++) {
		printf("%c", str[i]);
	}
	
}*/

#include <stdio.h>

int main() {
	printf("请输入一个浮点数：");
	float input;
	scanf_s("%f", &input);

	int in = (int)input;
	int size=1;
	while (in/10!=0) {
		size++;
		in /= 10;
	}
	float output;
	int dec1, dec2;
	dec1 = ((int)(input * 10) )% 10;
	dec2 = ((int)(input * 100)) % 10;
	int integer = (int)input;
	
	float temp=1.0;
	while (size) {
		temp *= 10;
		size--;
	}
	
	output = dec1 * 10 + dec2 + (float)(integer/temp);
	printf("%f", output);
	system("pause");
}