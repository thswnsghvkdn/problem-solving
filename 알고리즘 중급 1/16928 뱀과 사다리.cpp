#include <iostream> 
#include <queue>
using namespace std;

int u, v;
bool check[100];
int board[105];


int main()
{
	cin >> u >> v;

	int t1, t2;

	queue<pair<int, int>> q;

	for (int i = 0; i < u; i++)
	{
		cin >> t1 >> t2;
		board[t1] = t2;
	}
	for (int i = 0; i < v; i++)
	{
		cin >> t1 >> t2;
		board[t1] = t2;
	}

	q.push(make_pair(1, 0));
	while (!q.empty())
	{
		auto temp = q.front();
		check[temp.first] = true;
		q.pop();

		for (int i = 1; i <= 6; i++) {
			if ((temp.first + i) == 100) {
				cout << temp.second + 1;
				return 0;
			}
			if ((temp.first + i) > 100)
				continue;
			if (board[temp.first + i] != 0 && check[board[temp.first + i]] == false) {
				q.push(make_pair(board[temp.first + i], temp.second + 1));
			}
			else if(board[temp.first + i] == 0 && check[temp.first + i] == false  )
			{
				q.push(make_pair(temp.first + i, temp.second + 1));
			}
		}
	}
}
