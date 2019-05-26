#include <iostream>

#include <algorithm>

#include <string>

#include <memory.h>

using namespace std;



int arr[500005], check[500005], a, b;

long long ans;



long long cal(int num, int m, long long aa) {

	for (int i = m - 1; i <= num; i += (m - 1)) {

		if (check[i] == -1 && i != num) {

			aa += (arr[i + 2] + 1); i += 2;

		}

		else if (check[i] >= 0) {

			aa += (arr[check[i]] + 1); i = check[i];

		}

		else if (check[i] == -2) {

			aa += (arr[i + 1] + 1); i += 1;

		}

	}

	return aa * m;

}



int main(void) {



	int T; cin >> T; cin.ignore();

	for (int tc = 1; tc <= T; tc++) {

		ans = 0;

		string s; int cnt = 0;

		do {

			cin >> s; int len = s.length();

			for (int qq = cnt; qq < cnt + len; qq++) {

				arr[qq] = len; check[qq] = cnt;

			}

			cnt += len;

			check[cnt - 1] = -1;

			arr[cnt] = -1; check[cnt] = -2; cnt++;

		} while (getc(stdin) == ' ');

		cin >> a >> b;



		for (int i = a; i <= b; i++) {

			if (i == 1) ans += cnt - 1;

			else ans += cal(cnt - 2, i, arr[0]);

		}



		cout << "#" << tc << " " << ans << endl;

	}



	return 0;

}