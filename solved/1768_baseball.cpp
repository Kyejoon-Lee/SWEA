#define N          4

typedef struct {
	int strike;
	int ball;
} Result;

// API
extern Result query(int guess[]);

Result compare(int key, int obj)
{
	int count[10] = { 0 };
	Result result = { 0, 0 };

	for (int i = 0; i < N; ++i) {
		++count[key % 10];
		++count[obj % 10];
		if (key % 10 == obj % 10) ++result.strike;
		key = key / 10;
		obj = obj / 10;
	}

	for (int i = 0; i < 10; ++i) {
		if (count[i] == 2) ++result.ball;
	}

	result.ball -= result.strike;

	return result;
}

int A[6000];
int V[10000];
int Count_guess;
int flag_init = 0;

void init(void)
{
	int i, j, k, l;

	if (flag_init == 0) {
		flag_init = 1;
		Count_guess = 0;
		for (i = 0; i < 10; ++i) {
			for (j = 0; j < 10; ++j) {
				if (j == i) continue;
				for (k = 0; k < 10; ++k) {
					if (k == i || k == j) continue;
					for (l = 0; l < 10; ++l) {
						if (l == i || l == j || l == k) continue;
						A[Count_guess++] = 1000 * i + 100 * j + 10 * k + l;
					}
				}
			}
		}
	}

	for (register int i = 0; i < Count_guess; ++i) V[A[i]] = 0;
}

void doUserImplementation(int guess[])
{
	Result result;
	Result hub;
	int key;

	init();

	while (1) {
		for (register int i = 0; i < Count_guess; ++i) {
			if (V[A[i]] == 0) {
				key = A[i];
				guess[3] = A[i] % 10;
				guess[2] = (A[i] / 10) % 10;
				guess[1] = (A[i] / 100) % 10;
				guess[0] = A[i] / 1000;
				result = query(guess);
				break;
			}
		}

		if (result.strike == 4) break;

		for (register int i = 0; i < Count_guess; ++i) {
			if (V[A[i]] == 0) {
				hub = compare(key, A[i]);
				if (hub.ball == result.ball && hub.strike == result.strike) continue;
				V[A[i]] = 1;
			}
		}
	}
}
