#include <iostream> 
using namespace std;

int u, v;

int board[105];

int n_min = -1;

void go(int cnt, int next)

{

	if (next == 100)

	{

		if (n_min == -1 || n_min > cnt)

			n_min = cnt;

		return;

	}

	if (next > 100)

		return;

	if (cnt > 25)

		return;





	for (int i = 1; i <= 6; i++)

	{

		if (board[next + i])

			go(cnt + 1, board[next + i]);

		else

			go(cnt + 1, next + i);

	}

}





int main()

{

	cin >> u >> v;

	int t1, t2;

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

	go(0, 1);

	cout << n_min;



}
