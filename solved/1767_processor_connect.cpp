#include <stdio.h>
#include <algorithm>
#include <vector>
#define P pair<int,int>
using namespace std;

int map[12][12];
int t, n, res, pnum;

//0동,1남,2서,3북
//라인 놓을 수 있는지 체크
bool isLine(int x, int y, int dir) {
	if (dir == 0) {
		for (int i = y + 1; i < n; i++) {
			if (map[x][i] != 0)return false;
		}
	}
	else if (dir == 1) {
		for (int i = x + 1; i < n; i++) {
			if (map[i][y] != 0)return false;
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < y; i++) {
			if (map[x][i] != 0)return false;
		}
	}
	else {
		for (int i = 0; i < x; i++) {
			if (map[i][y] != 0) return false;
		}
	}
	return true;
}

int drawLine(int x, int y, int dir, int flag) {
	int ans = 0;
	if (dir == 0) {
		for (int i = y + 1; i < n; i++) {
			map[x][i] = (flag == 0) ? 2 : 0;
			ans++;
		}
	}
	else if (dir == 1) {
		for (int i = x + 1; i < n; i++) {
			map[i][y] = (flag == 0) ? 2 : 0;
			ans++;
		}
	}
	else if (dir == 2) {
		for (int i = 0; i < y; i++) {
			map[x][i] = (flag == 0) ? 2 : 0;
			ans++;
		}
	}
	else {
		for (int i = 0; i < x; i++) {
			map[i][y] = (flag == 0) ? 2 : 0;
			ans++;
		}
	}
	return ans;
}

//라인 그리거나 삭제하고 라인 수 반환
void dfs(vector<P> & v, int idx, int num, int line) {
	if (idx == v.size()) {
		// 최대프로세서 갯수가 갱신되는 경우
		if (pnum < num) {
			res = line;
			pnum = num;
		}
		// 최대프로세서 갯수가 같은 경우
		else if (pnum == num) {
			if (res > line) res = line;
		}
	}
	else {
		// 4방향에대해 라인놓기 시도 + 라인 놓지않고 다음 프로세서로 넘어가는 경우
		// 총 5가지에 대해 탐색
		for (int i = 0; i < 4; i++) {
			if (isLine(v[idx].first, v[idx].second, i)) {
				dfs(v, idx + 1, num + 1, line + drawLine(v[idx].first, v[idx].second, i, 0));
				drawLine(v[idx].first, v[idx].second, i, 1);
			}
		}
		dfs(v, idx + 1, num, line);
	}
}

int main() {
	scanf("%d", &t);
	for (int tc = 1; tc <= t; tc++) {
		vector<P> v;
		scanf("%d", &n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &map[i][j]);
				if (i == 0 || j == 0 || i == n - 1 || j == n - 1) continue;
				//프로세서 벡터에 추가하기
				if (map[i][j] == 1) {
					v.push_back(P(i, j));
				}
			}
		}

		res = 987654321;
		pnum = 0;
		dfs(v, 0, 0, 0);
		printf("#%d %d\n", tc, res);
	}
}
