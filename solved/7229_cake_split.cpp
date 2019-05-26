#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

int N, M;
double cake[50];
double check[50];
double mini;
double maxi;
double dif;
bool cmp(double a, double b) {
	return a > b;
}

void go() {
	maxi = cake[0];
	mini = cake[N - 1];
	dif = maxi - mini;
	int count = 0;
	while (1) {
		int flag = 0;
		for (int i = 0; i < N; i++) {
			if (cake[i] / check[i] > mini) {
				double temp = cake[i] / (check[i] + 1);
				check[i]++;
				if (temp < mini) {
					mini = temp;
				}
				count++;
				maxi = 0;
				for (int j = 0; j < N; j++) {
					if (cake[j] / check[j] > maxi) {
						maxi = cake[j] / check[j];
					}
				}
				if (dif > maxi - mini) {
					dif = maxi - mini;
				}
				flag = 1;
			}
			if (count >= M || dif == 0) {
				return;
			}
		}
		if (flag == 0) {
			return;
		}
	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%lf", &cake[i]);
			check[i] = 1;
		}

		scanf("%d", &M);
		sort(cake, cake + N, cmp);
		go();
		printf("#%d %.9f\n", num, dif);
	}
	return 0;
}