#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

using namespace std;


int arr[101];

int N, M;

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &N, &M);
		int cnt = 0;
		int temp = 1;
		for (int i = 1; i <= N; i++) {
			arr[i] = 0;
		}
		for (int i = 0; i < M; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			/*
			printf("%d %d\n", cnt, temp);
			for (int k = 1; k <= N; k++) {
				printf("%d ", arr[k]);
			}
			printf("\n");
			*/
			if (arr[a] == 0 && arr[b] == 0) {
				arr[a] = temp;
				arr[b] = temp++;
				cnt++;
			}
			else {
				if (arr[a] != 0 && arr[b] != 0 && arr[a] != arr[b]) {
					int tt = arr[b];
					for (int j = 1; j <= N; j++) {
						if (arr[j] == tt) {
							arr[j] = arr[a];

						}
					}
					cnt--;
				}
				else if (arr[a] == 0 && arr[b] != 0) {
					arr[a] = arr[b];
				}
				else if (arr[a] != 0 && arr[b] == 0) {
					arr[b] = arr[a];
				}
			}
		}
		for (int i = 1; i <= N; i++) {
			if (arr[i] == 0) {
				cnt++;
			}
		}
		printf("#%d %d\n", num, cnt);
	}
	return 0;
}
