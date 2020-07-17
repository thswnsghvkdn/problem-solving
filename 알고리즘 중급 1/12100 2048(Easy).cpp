#include <iostream>
#include <vector>
#include <algorithm>

#define LIMIT 5
using namespace std;
pair<int, bool> board[20][20];
int n;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
int ans;

vector<int> gen(int k)
{
	vector<int> n(LIMIT);
	for (int i = 0; i < LIMIT; i++)
	{
		n[i] = (k & 3);
		k >>= 2;
	}
	return n;
}

int move(int k)
{
	int nx, ny;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
		{
			// 현재칸이 숫자인 경우에만 움직인다.
			if (board[i][j].first)
			{
				nx = i + dx[k];
				ny = j + dy[k];
				if (nx >= 0 && nx < n && ny >= 0 && ny < n)
				{
					if (board[nx][ny].first == 0)
					{
						swap(board[nx][ny], board[i][j]);
					}
					// 합쳐지지 않은 숫자를 만났을 때 
					else if (board[nx][ny].first != 0 && board[i][j].second == false && board[nx][ny].second == false)
					{
						board[nx][ny].first += board[i][j].first;
						board[i][j].first = 0;
						board[nx][ny].second = true;
					}
				}
			}
		}
	int max = 0;
	// 최댓값 검사
	for(int i = 0 ; i < n ; i++)
		for (int j = 0; j < n; j++)
		{
			if (board[i][j].first > max)
				max = board[i][j].first;
		}

	return max;
}
void check_ans(vector<int> v)
{
	int max = 0;
	for (int i = 0; i < LIMIT; i++)
	{
		max = move(v[i]);
		if (ans < max)
			ans = max;
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> board[i][j].first;
	pair<int, bool> temp[20][20];
	memcpy(temp, board, sizeof(board));

	vector<int> v(LIMIT);
	for (int k = 0; k < (1 <<11); k++)
	{
		
		v = gen(k);
		check_ans(v);
		memcpy(board, temp, sizeof(board));
		
	}
	cout << ans;

}