#include <iostream>
#include <cstdio>
using namespace std;

int board_1[100000];
int board_2[100000];
int ans[100000];
int n;

void turn_on(int* board, int index)
{
	for (int i = index - 1; i <= index + 1; i++)
	{
		if (i < 0 || i > n)
			continue;
		board[i] = 1 - board[i];
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		scanf_s("%1d", &board_1[i]);
		board_2[i] = board_1[i];
	}

	for (int i = 0; i < n; i++) {
		scanf_s("%1d", &ans[i]);
	}


	turn_on(board_1, 0);
	int cnt1 = 1, cnt2 = 0;
	for (int i = 0; i < n-1; i++)
	{
		if (board_1[i] != ans[i]) {
			turn_on(board_1, i + 1);
			cnt1++;
		}
	}
	for (int i = 0; i < n - 1; i++)
	{
		if (board_2[i] != ans[i]) {
			turn_on(board_2, i + 1);
			cnt2++;
		}
	}
	int tot;
	bool same1 = true, same2 = true;
	for (int i = 0; i < n; i++)
	{
		if (board_1[i] != ans[i])
		{
			same1 = false;
			break;
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (board_2[i] != ans[i])
		{
			same2 = false;
			break;
		}
	}

	if (same2) {
		cout << cnt2;
		return 0;
	}
	if (same1) {
		cout << cnt1;
		return 0;
	}
	cout << -1;
	return 0;

}