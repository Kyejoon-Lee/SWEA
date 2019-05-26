#define _CRT_SECURE_NO_WARNINGS
#include<iostream>

typedef struct _node {
	int x;
	int y;
	int z;
}Box[20];

Box box;
int check[1 << 21][20][3];
int N;
int max;
int visit;

void stacking(int x, int y, int height, int shape, int index) {
	check[visit][index][shape] = height;
	if (height > max) {
		max = height;
	}
	for (int i = 0; i < N; i++) {
		if (visit & (1 << i)) {
			continue;
		}
		visit |= (1 << i);
		if ((box[i].x <= x && box[i].y <= y) || (box[i].y <= x && box[i].x <= y)) {
			if (check[visit][i][0] < height + box[i].z) {
				stacking(box[i].x, box[i].y, height + box[i].z, 0, i);
			}
		}
		if ((box[i].x <= x && box[i].z <= y) || (box[i].z <= x && box[i].x <= y)) {
			if (check[visit][i][1] < height + box[i].y) {
				stacking(box[i].x, box[i].z, height + box[i].y, 1, i);
			}
		}
		if ((box[i].y <= x && box[i].z <= y) || (box[i].z <= x && box[i].y <= y)) {
			if (check[visit][i][2] < height + box[i].x) {
				stacking(box[i].y, box[i].z, height + box[i].x, 2, i);
			}
		}
		visit -= (1 << i);
	}
}

int main() {
	int num, set, x, y, z;
	scanf("%d", &set);
	for (num = 1; num <= set; num++) {
		scanf("%d", &N);
		for (int i = 0; i < N; i++) {
			scanf("%d %d %d", &x, &y, &z);
			box[i].x = x;
			box[i].y = y;
			box[i].z = z;
		}
		max = 0;
		visit = 0;
		for (int j = 0; j < N; j++) {
			visit += (1 << j);
			stacking(box[j].x, box[j].y, box[j].z, 0, j);
			stacking(box[j].x, box[j].z, box[j].y, 1, j);
			stacking(box[j].z, box[j].y, box[j].x, 2, j);
			visit -= (1 << j);
		}
		printf("#%d %d\n", num, max);
		if (num != set) {
			for (int i = 0; i < (1 << (N + 1)); i++) {
				for (int j = 0; j < N; j++) {
					for (int k = 0; k < 3; k++) {
						check[i][j][k] = 0;
					}
				}
			}
		}
	}
	return 0;
}