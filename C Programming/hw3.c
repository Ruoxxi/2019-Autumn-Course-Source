/*4.5
(a)for�����������Ӧ�÷ֺŷָ�
(b)����case�����������break
(c)scanf��ɨ��������ַ�ֱ�����ֿո��س�����˻���ַ�Ҳɨ���ȥ��Ӧ����һ��char���������������ַ����ٰ����һ���ַ��������ַ��ָ�����
(d)ѭ������ӦΪx<=0.001,���򲻽���forѭ��
(e)Ӧ��Ϊx-=2
(f)while����ӦΪcounter<=100;����100�������
(g)for����֮�����һ���ֺţ��﷨����
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
	printf("������Ա����ţ�");
	scanf_s("%d", &type);
	while (type == 1 || type == 2 || type == 3 || type == 4) {
		switch (type) {
		case 1:
			printf("���뾭�����н��");
			double salary1;
			scanf_s("%lf", &salary1);
			printf("�������нΪ��%lf\n", salary1);
			break;
		case 2:
			printf("�������ʱ��������Сʱ��");
			double hour, salary2;
			scanf_s("%lf", &hour);
			printf("�������ʱ��ÿСʱ�Ĺ��ʣ�");
			double hosa;
			scanf_s("%lf", &hosa);
			if (hour <= 40) {
				salary2 = hour * hosa;
			}
			else {
				salary2 = 40 * hosa + (hour - 40)*1.5*hosa;
			}
			printf("��ʱ���Ĺ���Ϊ��%lf\n", salary2);
			break;
		case 3:
			printf("��������������ܶ");
			double num;
			scanf_s("%lf", &num);
			double salary3;
			salary3 = 250 + 0.05*num;
			printf("���칤����нΪ��%lf\n", salary3);
			break;
		case 4:
			printf("������ÿ����Ʒ�ı��꣺");
			int num4;
			double presa;
			scanf_s("%lf", &presa);
			printf("������Ƽ���������Ʒ��������");
			scanf_s("%d", &num4);
			double salary4;
			salary4 = num4 * presa;
			printf("�Ƽ�����нΪ��%lf\n", salary4);
			break;
		}
		printf("������Ա����ţ�");
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
	printf("������һ����������");
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