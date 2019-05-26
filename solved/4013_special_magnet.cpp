#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<deque>
using namespace std;

typedef struct _node {
	int pos;
	int di;
}direct;
int arr1[9];
int arr2[9];
int arr3[9];
int arr4[9];
deque<int>m1;
deque<int>m2;
deque<int>m3;
deque<int>m4;
int n;
deque<direct>di;

void rotation(int r1, int l2, int r2, int l3, int r3, int l4, int check) {
	if (check == n) {

		return;
	}

	int curnum = di.front().pos;
	int curpo = di.front().di;
	di.pop_front();
	if (curnum == 1) {
		if (curpo == 1) {
			int temp1 = m1.back();
			m1.pop_back();
			m1.push_front(temp1);
			if (arr1[r1] != arr2[l2]) {
				int temp2 = m2.front();
				m2.pop_front();
				m2.push_back(temp2);
				if (arr2[r2] != arr3[l3]) {
					int temp3 = m3.back();
					m3.pop_back();
					m3.push_front(temp3);
					if (arr3[r3] != arr4[l4]) {
						l4 = (l4 + 1) % 8;
						int temp4 = m4.front();
						m4.pop_front();
						m4.push_back(temp4);
					}
					l3 = (8 + (l3 - 1)) % 8;
					r3 = (8 + (r3 - 1)) % 8;
				}
				l2 = (8 + (l2 + 1)) % 8;
				r2 = (r2 + 1) % 8;
			}
			r1 = (8 + (r1 - 1)) % 8;
		}
		else if (curpo == -1) {
			int temp1 = m1.front();
			m1.pop_front();
			m1.push_back(temp1);
			if (arr1[r1] != arr2[l2]) {
				int temp2 = m2.back();
				m2.pop_back();
				m2.push_front(temp2);
				if (arr2[r2] != arr3[l3]) {
					int temp3 = m3.front();
					m3.pop_front();
					m3.push_back(temp3);
					if (arr3[r3] != arr4[l4]) {
						l4 = (8 + (l4 - 1)) % 8;
						int temp4 = m4.back();
						m4.pop_back();
						m4.push_front(temp4);
					}
					l3 = (8 + (l3 + 1)) % 8;
					r3 = (8 + (r3 + 1)) % 8;
				}
				l2 = (8 + (l2 - 1)) % 8;
				r2 = (8 + (r2 - 1)) % 8;
			}
			r1 = (8 + (r1 + 1)) % 8;
		}
	}
	else if (curnum == 2) {
		if (curpo == -1) {
			int temp2 = m2.front();
			m2.pop_front();
			m2.push_back(temp2);
			if (arr1[r1] != arr2[l2]) {
				int temp1 = m1.back();
				m1.pop_back();
				m1.push_front(temp1);
				r1 = (8 + (r1 - 1)) % 8;
			}
			if (arr2[r2] != arr3[l3]) {
				int temp3 = m3.back();
				m3.pop_back();
				m3.push_front(temp3);
				if (arr3[r3] != arr4[l4]) {
					l4 = (l4 + 1) % 8;
					int temp4 = m4.front();
					m4.pop_front();
					m4.push_back(temp4);
				}
				l3 = (8 + (l3 - 1)) % 8;
				r3 = (8 + (r3 - 1)) % 8;
			}
			l2 = (8 + (l2 + 1)) % 8;
			r2 = (r2 + 1) % 8;
		}

		else if (curpo == 1) {
			int temp2 = m2.back();
			m2.pop_back();
			m2.push_front(temp2);
			if (arr1[r1] != arr2[l2]) {
				int temp1 = m1.front();
				m1.pop_front();
				m1.push_back(temp1);
				r1 = (8 + (r1 + 1)) % 8;
			}
			if (arr2[r2] != arr3[l3]) {
				int temp3 = m3.front();
				m3.pop_front();
				m3.push_back(temp3);
				if (arr3[r3] != arr4[l4]) {
					l4 = (8 + (l4 - 1)) % 8;
					int temp4 = m4.back();
					m4.pop_back();
					m4.push_front(temp4);
				}
				l3 = (8 + (l3 + 1)) % 8;
				r3 = (8 + (r3 + 1)) % 8;
			}
			l2 = (8 + (l2 - 1)) % 8;
			r2 = (8 + (r2 - 1)) % 8;
		}
	}
	else if (curnum == 3) {
		if (curpo == 1) {
			int temp3 = m3.back();
			m3.pop_back();
			m3.push_front(temp3);
			if (arr2[r2] != arr3[l3]) {
				int temp2 = m2.front();
				m2.pop_front();
				m2.push_back(temp2);
				if (arr1[r1] != arr2[l2]) {
					int temp1 = m1.back();
					m1.pop_back();
					m1.push_front(temp1);
					r1 = (8 + (r1 - 1)) % 8;
				}
				l2 = (8 + (l2 + 1)) % 8;
				r2 = (r2 + 1) % 8;
			}
			if (arr3[r3] != arr4[l4]) {
				l4 = (l4 + 1) % 8;
				int temp4 = m4.front();
				m4.pop_front();
				m4.push_back(temp4);
			}
			l3 = (8 + (l3 - 1)) % 8;
			r3 = (8 + (r3 - 1)) % 8;
		}

		else if (curpo == -1) {
			int temp3 = m3.front();
			m3.pop_front();
			m3.push_back(temp3);
			if (arr2[r2] != arr3[l3]) {
				int temp2 = m2.back();
				m2.pop_back();
				m2.push_front(temp2);
				if (arr1[r1] != arr2[l2]) {
					int temp1 = m1.front();
					m1.pop_front();
					m1.push_back(temp1);
					r1 = (8 + (r1 + 1)) % 8;
				}
				l2 = (8 + (l2 - 1)) % 8;
				r2 = (8 + (r2 - 1)) % 8;
			}
			if (arr3[r3] != arr4[l4]) {
				l4 = (8 + (l4 - 1)) % 8;
				int temp4 = m4.back();
				m4.pop_back();
				m4.push_front(temp4);
			}
			l3 = (8 + (l3 + 1)) % 8;
			r3 = (8 + (r3 + 1)) % 8;
		}

	}
	else if (curnum == 4) {
		if (curpo == -1) {
			int temp4 = m4.front();
			m4.pop_front();
			m4.push_back(temp4);

			if (arr3[r3] != arr4[l4]) {
				int temp3 = m3.back();
				m3.pop_back();
				m3.push_front(temp3);
				if (arr2[r2] != arr3[l3]) {
					int temp2 = m2.front();
					m2.pop_front();
					m2.push_back(temp2);
					if (arr1[r1] != arr2[l2]) {
						int temp1 = m1.back();
						m1.pop_back();
						m1.push_front(temp1);
						r1 = (8 + (r1 - 1)) % 8;
					}
					l2 = (8 + (l2 + 1)) % 8;
					r2 = (r2 + 1) % 8;
				}
				l3 = (8 + (l3 - 1)) % 8;
				r3 = (8 + (r3 - 1)) % 8;
			}
			l4 = (l4 + 1) % 8;
		}
		else if (curpo == 1) {
			int temp4 = m4.back();
			m4.pop_back();
			m4.push_front(temp4);
			if (arr3[r3] != arr4[l4]) {
				int temp3 = m3.front();
				m3.pop_front();
				m3.push_back(temp3);
				if (arr2[r2] != arr3[l3]) {
					int temp2 = m2.back();
					m2.pop_back();
					m2.push_front(temp2);
					if (arr1[r1] != arr2[l2]) {
						int temp1 = m1.front();
						m1.pop_front();
						m1.push_back(temp1);
						r1 = (8 + (r1 + 1)) % 8;
					}
					l2 = (8 + (l2 - 1)) % 8;
					r2 = (8 + (r2 - 1)) % 8;
				}

				l3 = (8 + (l3 + 1)) % 8;
				r3 = (8 + (r3 + 1)) % 8;
			}
			l4 = (8 + (l4 - 1)) % 8;

		}
	}
	rotation(r1, l2, r2, l3, r3, l4, check + 1);
}

int main() {
	int i, j, num, set;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &n);
		m1.clear();
		m2.clear();
		m3.clear();
		m4.clear();
		di.clear();
		for (i = 0; i < 4; i++) {
			if (i == 0) {
				for (j = 0; j < 8; j++) {
					scanf("%d", &arr1[j]);
					m1.push_back(arr1[j]);
				}
			}
			else if (i == 1) {
				for (j = 0; j < 8; j++) {
					scanf("%d", &arr2[j]);
					m2.push_back(arr2[j]);
				}
			}
			else if (i == 2) {
				for (j = 0; j < 8; j++) {
					scanf("%d", &arr3[j]);
					m3.push_back(arr3[j]);
				}
			}
			else {
				for (j = 0; j < 8; j++) {
					scanf("%d", &arr4[j]);
					m4.push_back(arr4[j]);
				}
			}
		}
		for (i = 0; i < n; i++) {
			int po;
			int d;
			scanf("%d %d", &po, &d);
			direct dtemp;
			dtemp.pos = po;
			dtemp.di = d;
			di.push_back(dtemp);
		}
		rotation(2, 6, 2, 6, 2, 6, 0);
		int sum = 0;
		if (m1.front() == 1) {
			sum = sum + 1;
		}
		if (m2.front() == 1) {
			sum = sum + 2;
		}
		if (m3.front() == 1) {
			sum = sum + 4;
		}
		if (m4.front() == 1) {
			sum = sum + 8;
		}
		printf("#%d %d\n", num, sum);
	}
}
