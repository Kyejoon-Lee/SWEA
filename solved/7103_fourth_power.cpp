#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<math.h>

int N;
int cnt;

void counting(int flag, int cnum, int pre) {
	if (flag == 4) {
		return;
	}
	int temp = (int)sqrt(cnum);
	for (int i = temp; i >= 1; i--) {
		if (pow(i, 2) * (4 - flag) < cnum) {
			break;
		}
		int res = cnum - (int)pow(i, 2);
		if (res == 0 && i <= pre) {
			cnt++;
		}
		else if (i <= pre) {
			counting(flag + 1, res, i);
		}
	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		cnt = 0;
		counting(0, N, N);
		printf("#%d %d\n", num, cnt);
	}
	return 0;
}