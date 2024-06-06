#include<stdio.h>
int check_year(int year) {
	if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0)) {
		return 1;
	}
	else {
		return 0;
	}
}

int week_f(int year) {
	if (year == 1) {
		return 1;
	}
	int sum = 0;
	int i;
	//int check_year(i);
	for (i = 1; i < year; i++) {
		if (check_year(i) == 1) {
			sum += 366;
		}
		if (check_year(i) == 0) {
				sum += 365;

		}

		}
	return(sum + 1) % 7;
}
int month_run[12]  = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int month_ping[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
void run(int week) {
	//int enter = 0;
	int i, j, k;
	int wee = week;
	for (int i = 1; i <= 12; i++) {
		int enter = 0;
		printf("------->%d月<-------\n", i);
		printf("日 一 二 三 四 五 六\n");
		for (k = 0; k < wee; k++) {
			printf("   ");
			enter++;
		}
		for (int j = 1; j <= month_run[i-1]; j++) {
			if (enter % 7 == 0) {
				printf("\n");

			}
			if (j < 10) {
				printf("%d  ", j);
				enter++;
			}
			if (j >= 10) {
				printf("%d ", j);
				enter++;
			}
		}
		wee = (wee + month_run[i]) % 7;
		//enter = enter - wee;
		printf("\n\n\n");
	}
}
void ping(int week) {
	//int enter = 0;
	int wee = week;
	int i, j, k;
	for (i = 1; i <= 12; i++) {
		int enter = 0;
		printf("-------->%d月-------<\n", i);
		printf("日 一 二 三 四 五 六\n");
		for (int k = 0; k < wee; k++) {
			printf("   ");
			enter++;

		}
		for (j = 1; j <= month_ping[i-1]; j++) {
			if (enter % 7 == 0) {
				printf("\n");
			}
			if (j < 10) {
				printf("%d  ", j);
				enter++;
			}
			if (j >= 10) {
				printf("%d ", j);
				enter++;
			}
		}
		wee = (wee + month_ping[i]) % 7;
		//enter = enter - wee;
		printf("\n\n\n");
	}
}
int main() {
	int year;
	int week = 0;
	int sum = 0;
	printf("请输入年份：");
	scanf_s("%d", &year, sizeof(int));
	week = week_f(year);
	if (check_year(year) == 1) {
		run(week);
	}
	if (check_year(year) == 0) {
		ping(week);
	}
	return 0;
}
