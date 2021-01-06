#include <iostream>
#include <algorithm>
using namespace std;

int n, k;
int winning[11][11];
int hand[3][21];

bool isOneWinner()
{
	int p1 = 0, p2 = 1, p3 = 2;
	int idx[3] = { 1 ,1 ,1 };
	int win[3] = { 0 ,0 ,0 };

	while (1)
	{
		if (p1 > p2) swap(p1, p2);
		if (p1 == 0, idx[0] > n) break;
		if (idx[p1] >= 21 || idx[p2] >= 21) break;

		if (winning[hand[p1][idx[p1]++]][hand[p2][idx[p2]++]] == 2)
		{
			if (++win[p1] == k) break;
			swap(p2, p3);
		}
		else {
			if (++win[p2] == k) break;
			swap(p1, p3);
		}
	}

	return win[0] >= k;
}


int main()
{
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> winning[i][j];
	for (int i = 1; i < 21; i++)
		cin >> hand[1][i];
	for (int i = 1; i < 21; i++)
		cin >> hand[2][i];
	for (int i = 1; i <= n; i++)
		hand[0][i] = i;

	do
	{
		if (isOneWinner()) {
			cout << 1;
			return 0;
		}
	} while (next_permutation(hand[0] + 1, hand[0] + n + 1));
	cout << 0;
}