#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int N, M;
int arr[20][20];


int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &N, &M);
		int max = 0;
		int temp = 0;
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			temp = 0;
			for (int j = 0; j < M; j++) {
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1) {
					temp++;
				}
			}
			if (temp > max) {
				max = temp;
				cnt = 1;
			}
			else if (temp == max) {
				cnt++;
			}
		}
		printf("#%d %d %d\n", num, cnt, max);
	}
	return 0;
}