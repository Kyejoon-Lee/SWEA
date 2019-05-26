#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
int N, M;

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &N, &M);
		printf("#%d", num);
		for (int i = 1; i <= abs(N - M) + 1; i++) {
			if (N <= M) {
				printf(" %d", N + i);
			}
			else {
				printf(" %d", M + i);
			}
		}
		printf("\n");
	}
	return 0;
}