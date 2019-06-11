#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>

using namespace std;
deque<int>dq;
long long  arr[10001];
int N, M;
int cnt;

void count() {
	while (!dq.empty()) {
		int pos = dq.front();
		dq.pop_front();
		long long price = 0;
		for (; pos < N; pos++) {
			price += arr[pos];
			if (price > M) {
				break;
			}
			else if (price == M) {
				cnt++;
				break;
			}
		}
	}
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		cnt = 0;
		dq.clear();
		scanf("%d %d", &N, &M);
		for (int i = 0; i < N; i++) {
			scanf("%lld", &arr[i]);
			if (arr[i] <= M) {
				dq.push_back(i);
			}
		}
		count();
		printf("#%d %d\n", num, cnt);
	}
	return 0;
}