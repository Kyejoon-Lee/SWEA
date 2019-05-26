#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<list>
#include<algorithm>

using namespace std;
int N, K;
int l1[100000];
int arr[100000];
int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {

		scanf("%d %d", &N, &K);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		for (int i = 0; i < N - 1; i++) {
			l1[i] = arr[i + 1] - arr[i];
		}
		sort(l1, l1 + N - 1);

		int cnt = 0;
		for (int i = 0; i < N - K; i++) {
			cnt += l1[i];
		}

		printf("#%d %d\n", num, cnt);

	}
	return 0;
}