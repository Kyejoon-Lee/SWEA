#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string.h>
#include<cmath>

char list1[100001];
char list2[100001];
int lista1[100001];

int main() {
	int set;
	int N;
	scanf("%d", &set);
	for (int N = 1; N <= set; N++) {
		scanf("%s", list1);
		scanf("%s", list2);
		long long res = 0;
		int len = strlen(list1);
		int check = 0;
		for (int i = 0; i < len; i++) {
			if (list1[i] == 'a') {
				lista1[check++] = i;
			}
		}
		check = 0;
		for (int i = 0; i < len; i++) {
			if (list2[i] == 'a') {
				int temp = lista1[check++] - i;
				if (temp < 0) {
					res -= temp;
				}
				else {
					res += temp;
				}
			}
		}
		printf("#%d %lld\n", N, res);
	}
	return 0;
}