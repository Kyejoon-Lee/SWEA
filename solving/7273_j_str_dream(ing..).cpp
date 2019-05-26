#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>

int N, K;
int carr[27];
char arr[27];
int sres, bres, flag;
int count;
const int Maxn = 2 * 1e5 + 1, Mod = 1e9 + 7;

long long inv[Maxn];
long long fact[Maxn];
long long ifact[Maxn];

template<typename T, typename T1>
T mod(T x, T1 p) {
	x %= p;
	if (x < 0)
		x += p;
	//x %= p;
	return x;
}

// x must be relatively prime to p
template<typename T>
T inverse(T x, T p) {
	x = mod(x, p);
	if (x == 1)
		return x;
	return mod(1LL * (-p / x) * (inverse(p % x, p)), p);
}

long long combination(long long x, long long r) {
	long long n = x + r;
	long long ret = (1LL * ifact[n - r] * ifact[r]) % Mod;
	ret = (1LL * ret * fact[n]) % Mod;
	return ret;
}


void dfs(int pos, int res, int cnt) {
	if (pos <res || cnt>K) {
		return;
	}
	if (res == 0) {
		if (cnt + strlen(arr) == K) {
			flag = 1;
			count++;
		}
		return;
	}
	if (carr[pos] > 0) {
		dfs(pos - 1, res, cnt);
	}
	else if (carr[pos] == 0) {
		if (res > 0) {
			carr[pos] = 1;
			dfs(pos - 1, res - 1, cnt + pos);
			carr[pos] = 0;
		}
		dfs(pos - 1, res, cnt);
	}
}

void init() {
	for (int i = 0; i <= N; i++) {
		carr[i] = 0;
	}
}

int main() {
	fact[0] = 1;
	for (int i = 1; i < 27; i++) {
		fact[i] = 1LL * fact[i - 1] * i % Mod;
	}
	ifact[0] = 1;
	for (int i = 1; i < 27; i++) {
		ifact[i] = 1LL * ifact[i - 1] * inverse(i, Mod) % Mod;
	}
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d", &N, &K);
		scanf("%s", arr);
		sres = arr[0] - 96 - 1;
		bres = N - sres - 1;
		flag = 0;
		count = 0;
		int tarr[27];
		for (int i = 0; i < strlen(arr); i++) {
			if (arr[i] < arr[0]) {
				tarr[i] = 1;
				sres--;
			}
			else {
				tarr[i] = 2;
			}
		}

		for (int i = N; i >= strlen(arr); i--) {
			int temp = 0;
			init();
			for (int j = 0; j < strlen(arr); j++) {

				carr[i - j] = tarr[j];
				if (carr[i - j] == 1) {
					temp += i - j;
				}
			}
			dfs(N, sres, temp);
		}
		if (flag == 1) {
			long long int cct;
			cct = fact[sres] * count % Mod;
			cct = cct * fact[bres] % Mod;
			printf("#%d %lld\n", num, cct);
		}
		else {
			printf("#%d 0\n", num);
		}
	}
	return 0;
}