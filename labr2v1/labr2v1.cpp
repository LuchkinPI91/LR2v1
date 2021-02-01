#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#define Z 20
#define N 30

struct 
{
	char fio[Z];
	int groupnumber;
	float exam1;
	float exam2;


}people[N],people1;

void input(int n) {

	for (int i = 0;i < n;i++) {
		printf("Введите Фамилия:");
		scanf("%s", &people[i].fio);

		while ((getchar()) != '\n');

		printf("Введите номер группы:");
		scanf("%d", &people[i].groupnumber);

		while ((getchar()) != '\n');

		printf("Введите оценку за 1 экзамен:");
		scanf("%f", &people[i].exam1);

		while ((getchar()) != '\n');

		printf("Введите оценку за 2 экзамен:");
		scanf("%f", &people[i].exam2);
	
	}
	


}

void sort(int n) {
	int gn;
	for (int i = 0;i < n-1;i++) {
		for (int j = n - 1;j > i;j--) {
		
			if (people[j - 1].groupnumber < people[j].groupnumber) {
				
				people1 = people[j-1];
				people[j - 1] = people[j];
				people[j] = people1;
			

			}
		
		}
	
	
	}

}

void output(int n) {


	for (int i=0;i < n;i++) {
	
		printf("Фамилия:%s Номер Группы: %d Оценка за 1 экзамен: %f Оценка за 2 экзамен: %f\n", people[i].fio, people[i].groupnumber, people[i].exam1, people[i].exam2);
	
	}

}

void exam(int n) {
	printf("Студенты, у которых оценка за 2 экзамен ниже, чем за первый\n");
	for (int i = 0;i < n;i++) {
	
		if (people[i].exam1 > people[i].exam2) {
		
			printf("%s\n",people[i].fio);
		
		}
	
	
	}


}
void sum(int n) {
	float sum1 = 0;
	float sum2 = 0;
	for (int i = 0;i < n;i++) {
	
		sum1 += people[i].exam1;
		sum2 += people[i].exam2;
	
	
	}

	printf("Сумма оценок за 1 экзамен:%f", sum1);
	printf("Сумма оценок за 2 экзамен:%f", sum2);

}

int main() {

	int n;

	system("chcp 1251");
	system("cls");

	printf("Введите кол-во студентов:");
	scanf("%d", &n);
	input(n);
	output(n);
	sort(n);
	output(n);
	exam(n);
	sum(n);
}