#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstring>
char arr[11];
char tarr[11];
int check[11];
int N;

int main() {
	int set, num;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		int flag = 0;
		scanf("%s", arr);
		scanf("%s", tarr);
		if (strlen(arr) != strlen(tarr)) {
			flag = 1;
		}
		else {
			for (int i = 0; i < strlen(arr); i++) {
				char t = arr[i];
				check[i] = 0;
				if (t == 'A' || t == 'D' || t == 'O' || t == 'P' || t == 'Q' || t == 'R') {
					check[i] = 1;
				}
				else if (t == 'B') {
					check[i] = 2;
				}

			}
			for (int i = 0; i < strlen(arr); i++) {
				char t = tarr[i];
				if (t == 'A' || t == 'D' || t == 'O' || t == 'P' || t == 'Q' || t == 'R') {
					if (check[i] != 1) {
						flag = 1;
						break;
					}
				}
				else if (t == 'B') {
					if (check[i] != 2) {
						flag = 1;
						break;
					}
				}
				else {
					if (check[i] != 0) {
						flag = 1;
						break;
					}
				}
			}
		}
		if (flag == 0) {
			printf("#%d SAME\n", num);
		}
		else {
			printf("#%d DIFF\n", num);
		}
	}
	return 0;
}