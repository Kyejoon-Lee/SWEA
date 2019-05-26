#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
using namespace std;
char arr[29];

int N, K;
vector<int>v;

void cal() {
	int div = N / 4;
	for (int i = 0; i < N; i++) {
		int tcnt = 0;
		for (int j = 0; j < div; j++) {
			int temp = i + j;
			if (temp >= N) {
				temp = temp % N;
			}
			if (arr[temp] > 64) {
				tcnt += (arr[temp] - 55) * (int)pow(16, div - j - 1);
			}
			else {
				tcnt += (arr[temp] - 48) * (int)pow(16, div - j - 1);
			}
		}
		int size = v.size();
		int flag = 0;
		for (int k = 0; k < size; k++) {
			if (v[k] == tcnt) {
				flag = 1;
				break;
			}
		}
		if (flag == 0) {
			v.push_back(tcnt);
		}
	}
}
bool cmp(int a, int b) {
	return a > b;
}

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		v.clear();
		scanf("%d %d", &N, &K);
		scanf("%s", arr);
		cal();
		sort(v.begin(), v.end(), cmp);
		printf("#%d %d\n", num, v[K - 1]);
	}
	return 0;
}
