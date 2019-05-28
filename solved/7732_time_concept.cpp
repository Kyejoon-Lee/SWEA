#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		char cmp1[10];
		char cmp2[10];
		scanf("%s", cmp1);
		scanf("%s", cmp2);
		int hour1 = (cmp1[0] - '0') * 10 + cmp1[1] - '0';
		int hour2 = (cmp2[0] - '0') * 10 + cmp2[1] - '0';
		int min1 = (cmp1[3] - '0') * 10 + cmp1[4] - '0';
		int min2 = (cmp2[3] - '0') * 10 + cmp2[4] - '0';
		int sec1 = (cmp1[6] - '0') * 10 + cmp1[7] - '0';
		int sec2 = (cmp2[6] - '0') * 10 + cmp2[7] - '0';
		int ch, cm, cs;
		if (hour1 <= hour2) {
			ch = hour2 - hour1;
			if (min1 <= min2) {
				cm = min2 - min1;
				if (sec1 <= sec2) {
					cs = sec2 - sec1;
				}
				else {
					cm--;
					if (cm < 0) {
						cm = 60 + cm;
						ch--;
						if (ch < 0) {
							ch = 24 + ch;
						}
					}
					cs = 60 - sec1 + sec2;
				}
			}
			else {
				cm = 60 - min1 + min2;
				ch--;
				if (ch < 0) {
					ch = 24 + ch;
				}
				if (sec1 <= sec2) {
					cs = sec2 - sec1;
				}
				else {
					cm--;
					if (cm < 0) {
						cm = 60 + cm;
						ch--;
						if (ch < 0) {
							ch = 24 + ch;
						}
					}
					cs = 60 - sec1 + sec2;
				}

			}
		}
		else {
			ch = 24 - hour1 + hour2;
			if (min1 <= min2) {
				cm = min2 - min1;
				if (sec1 <= sec2) {
					cs = sec2 - sec1;
				}
				else {
					cm--;
					if (cm < 0) {
						cm = 60 + cm;
						ch--;
						if (ch < 0) {
							ch = 24 + ch;
						}
					}
					cs = 60 - sec1 + sec2;
				}
			}
			else {
				cm = 60 - min1 + min2;
				ch--;
				if (ch < 0) {
					ch = 24 + ch;
				}
				if (sec1 <= sec2) {
					cs = sec2 - sec1;
				}
				else {
					cm--;
					if (cm < 0) {
						cm = 60 + cm;
						ch--;
						if (ch < 0) {
							ch = 24 + ch;
						}
					}
					cs = 60 - sec1 + sec2;
				}

			}
		}
		char result[9];
		result[0] = '0' + ch / 10;
		result[1] = '0' + ch % 10;
		result[2] = ':';
		result[3] = '0' + cm / 10;
		result[4] = '0' + cm % 10;
		result[5] = ':';
		result[6] = '0' + cs / 10;
		result[7] = '0' + cs % 10;
		printf("#%d ", num);
		for (int i = 0; i < 8; i++) {
			printf("%c", result[i]);
		}
		printf("\n");
	}
	return 0;
}