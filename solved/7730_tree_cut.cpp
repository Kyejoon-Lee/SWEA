#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>

using namespace std;

int arr[1000001];

bool cmp(int a, int b) {
	return a > b;
}
int N, M;
int res;
void cal() {
	int pre = arr[0];
	int cnt = 1;
	int sum = 0;
	while (1) {
		if (cnt == N + 1) {
			return;
		}
		if (pre == arr[cnt]) {
			cnt++;
			continue;
		}
		else if (cnt * (pre - arr[cnt]) + sum < M) {
			sum += cnt * (pre - arr[cnt]);
			pre = arr[cnt++];
		}
		else if (cnt * (pre - arr[cnt]) + sum == M) {
			res = arr[cnt];
			return;
		}
		else {
			if ((M - sum) % cnt == 0) {
				res = pre - ((M - sum) / cnt);
			}
			else {
				res = pre - ((M - sum) / cnt + 1);
			}
			return;
		}
	}
}


int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%d", &arr[i]);
		}
		sort(arr, arr + N, cmp);
		arr[N] = 0;
		if (N == 1) {
			res = arr[0] - M;
		}
		else {
			cal();
		}
		printf("#%d %d\n", num, res);
	}
	return 0;
}