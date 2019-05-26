#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cmath>

using namespace std;
typedef struct {
	int pos;
	int res;
	int mul;
}Node;
int s, t, a, b;




int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d %d %d %d", &s, &t, &a, &b);
		int cnt = 1000000001;
		if (b == 1) {
			if ((t - s) % a == 0) {
				cnt = (t - s) / a;
			}
			else {
				cnt = -1;
			}
		}
		else {
			int flag = 0;
			for (int i = 29; i >= 0; i--) {
				int temp = i;
				int con = (int)t - s * pow(b, i);
				if (con == 0) {
					if (cnt > i) {
						cnt = i;
					}
					continue;
				}
				else if (con < 0) {
					continue;
				}
				else {
					if (con % a == 0) {
						int p = con / a;
						if (p >= pow(b, i + 1) && i != 0 && flag != 1) {
							temp += (int)(p / pow(b, i));
							p = p - ((int)(p / pow(b, i)) * pow(b, i));

							flag = 1;

						}
						if (p < pow(b, i + 1)) {
							for (int j = i; j >= 0; j--) {
								for (int k = b - 1; k > 0; k--) {
									if (p >= k * pow(b, j)) {
										p -= (int)k * pow(b, j);
										temp += k;
										break;
									}
								}
								if (p == 0) {
									if (cnt > temp) {
										cnt = temp;
									}
									break;
								}
							}
						}
					}
				}
			}
		}

		if (cnt == 1000000001) {
			cnt = -1;
		}
		printf("#%d %d\n", num, cnt);
	}
	return 0;
}