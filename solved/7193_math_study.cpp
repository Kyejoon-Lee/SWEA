#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>
#include<cstring>

using namespace std;
char target[10000001];

int N;

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		scanf("%s", target);
		long long res = 0;

		for (int i = strlen(target) - 1; i >= 0; i--) {
			res += target[i] - 48;
			target[i] = 0;
		}
		res = res % (N - 1);
		printf("#%d %lld\n", num, res);
	}
	return 0;
}