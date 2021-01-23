#include <iostream>
#include <climits>
#include <algorithm>
using namespace std;

int n, m;
int A[1001][1001];
int B[1001][1001];
pair<int, int> maxRow = { INT_MIN , 0 }, maxCol = { INT_MIN , 0 };
pair<int, int> minRow = { INT_MAX , 0 }, minCol = { INT_MAX, 0 };
int row_first, row_last, col_first, col_last;
void swap_line(char c, int index1, int index2)
{
	int t;
	if (c == 'c')
	{
		for (int i = 0; i < n; i++)
		{
			t = A[i][index2];
			A[i][index2] = A[i][index1];
			A[i][index1] = t;
		}
		return;
	}
	else
	{
		for (int j = 0; j < m; j++)
		{
			t = A[index2][j];
			A[index2][j] = A[index1][j];
			A[index1][j] = t;
		}
		return;
	}
}

int ret_tot(int A[1001][1001])
{
	int ans = 0;
	for (int i = 0; i < n - 1; i++)
		for (int j = 0; j < m - 1; j++)
			ans += A[i][j] + A[i + 1][j] + A[i][j + 1] + A[i + 1][j + 1];
	return ans;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> A[i][j];
			B[i][j] = A[i][j];
		}

	for (int i = 0; i < n; i++) {
		int t = 0;
		for (int j = 0; j < m; j++)
			t += A[i][j];
		if (i == 0)
			row_first = t;
		if (i == n - 1)
			row_last = t;
		if (i != 0 && i != n - 1 && minRow.first > ( t * 4 - 2 * (A[i][0] + A[i][m-1]) ))
			minRow = { t * 4 - 2 * (A[i][0] + A[i][m - 1]) , i };
	}
	for (int j = 0; j < m; j++) {
		int t = 0;
		for (int i = 0; i < n; i++)
			t += A[i][j];
		if (j == 0)
			col_first = t;
		if (j == m - 1)
			col_last = t;
		if (j != 0 && j != m - 1 && minCol.first > ( t * 4 - 2 * (A[0][j] + A[n-1][j]) ))
			minCol = { t * 4 - 2 * (A[0][j] + A[n - 1][j]) , j };
	}

	int ans[5];
	ans[0] = ret_tot(A); // 기본 배열의 최댓값

	swap_line('c', minCol.second, 0);
	ans[1] = ret_tot(A);


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = B[i][j];
	swap_line('c', minCol.second, m - 1);
	ans[2] = ret_tot(A);



	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = B[i][j];
	swap_line('r', minRow.second, 0);
	ans[3] = ret_tot(A);



	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			A[i][j] = B[i][j];

	swap_line('r', minRow.second, n - 1);
	ans[4] = ret_tot(A);


	int n_ans = INT_MIN;
	for (int i = 0; i < 5; i++)
		if (n_ans < ans[i])
			n_ans = ans[i];
	cout << n_ans;
}