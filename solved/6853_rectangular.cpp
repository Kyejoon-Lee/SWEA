#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int lx, rx, uy, dy;
int N;
int ans1, ans2, ans3;
int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d %d %d", &lx, &uy, &rx, &dy);
		scanf("%d", &N);
		ans1 = 0;
		ans2 = 0;
		ans3 = 0;
		for (int i = 0; i < N; i++) {
			int tx, ty;
			scanf("%d %d", &tx, &ty);
			if (tx < lx || tx>rx || ty <uy || ty >dy) {
				ans3++;
			}
			else if ((tx > lx && tx < rx) && (ty > uy && ty < dy)) {
				ans1++;
			}
			else {
				ans2++;
			}
		}
		printf("#%d %d %d %d\n", num, ans1, ans2, ans3);
	}
	return 0;
}