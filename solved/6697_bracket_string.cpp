#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
/// 1,2,3,4 ....
/// n(n+1)/2



int main() {
	int set;
	scanf("%d", &set);
	int num;
	int n;
	for (num = 1; num <= set; num++) {
		scanf("%d", &n);
		int par = sqrt(2 * n + 0.25) - 0.5;

		int res = par * (par + 1) / 2;

		printf("#%d ", num);
		if (res == n) {
			for (int i = 0; i < 2 * par; i++) {
				if (i >= par) {
					printf("(");
				}
				else {
					printf(")");
				}
			}
		}
		else {
			for (int i = 0; i < 2 * (par + 1); i++) {
				if (i == (n - res)) {
					printf("(");
				}
				else if (i > par + 1) {
					printf("(");
				}
				else {
					printf(")");
				}
			}

		}
		printf("\n");
	}
	return 0;
}