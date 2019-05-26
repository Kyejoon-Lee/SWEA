#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

typedef struct {
	int sx;
	int sy;
	int ex;
	int ey;
	int ssum;
	int esum;
	long long path;
}Node;
int N, M, K;
long long  cnt;
vector<Node>v;


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

bool cmp(Node a, Node b) {
	return a.ssum < b.ssum;
}

void go() {
	int check = 0;
	while (1) {
		if (check == K) {
			return;
		}
		Node temp = v[check];
		int sx = temp.sx;
		int sy = temp.sy;
		int ey = temp.ey;
		int ex = temp.ex;
		long long path = combination(sx - 1, sy - 1);
		int flag = 0;
		long long tpath = 0;
		for (int i = 0; i < check; i++) {

			Node node = v[i];
			if (node.sx < sx && node.sy < sy) {
				if (node.ex < sx && node.ey < sy) {
					path -= mod(node.path * combination(sx - node.sx, sy - node.sy), 1000000007);
					path += mod(node.path * combination(sx - node.ex, sy - node.ey), 1000000007);
					path = mod(path, 1000000007);
				}
				else if (node.ex == sx && node.ey == sy) {
					path -= mod(node.path * combination(sx - node.sx, sy - node.sy), 1000000007);
					tpath += v[i].path;
					tpath = mod(tpath, 1000000007);
					v[i].ex = ex;
					v[i].ey = ey;
				}
				else {
					path -= mod((node.path * combination(sx - node.sx, sy - node.sy)), 1000000007);
					path = mod(path, 1000000007);

				}
			}

		}
		v[check].path = path;
		path += mod(tpath, 1000000007);
		cnt -= mod(path * (combination(N - sy, M - sx)), 1000000007);
		cnt += mod(path * combination(N - ey, M - ex), 1000000007);
		cnt = mod(cnt, 1000000007);

		check++;
	}

}

int main() {
	//freopen("input.txt", "r", stdin);
	int set, num;
	scanf("%d", &set);
	fact[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		fact[i] = 1LL * fact[i - 1] * i % Mod;
	}
	ifact[0] = 1;
	for (int i = 1; i < Maxn; i++) {
		ifact[i] = 1LL * ifact[i - 1] * inverse(i, Mod) % Mod;
	}
	for (num = 1; num <= set; num++) {
		scanf("%d %d %d", &N, &M, &K);
		int sx, sy, ex, ey;
		Node temp;
		v.clear();
		cnt = 0;
		cnt = combination(N - 1, M - 1);
		for (int i = 0; i < K; i++) {
			scanf("%d %d %d %d", &sy, &sx, &ey, &ex);
			temp.sy = sy;
			temp.sx = sx;
			temp.ex = ex;
			temp.ey = ey;
			temp.ssum = sy + sx;
			temp.esum = ey + ex;
			temp.path = 0;
			v.push_back(temp);
		}

		sort(v.begin(), v.end(), cmp);

		go();
		printf("#%d %lld\n", num, cnt);
	}
	return 0;
}