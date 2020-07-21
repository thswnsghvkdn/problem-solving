#include <iostream>
#include <queue>
using namespace std;

int check[1505][1505];

int main()
{
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	if (sum % 3 != 0) {
		cout << 0;
		return 0;
	}
	if (a == b && a == c)
	{
		cout << 1;
		return 0;
	}
	queue<pair<int, int>> q;
	
	int ar[] = { a, b, c };
	for(int i = 0 ; i < 3 ;i++)
		for (int j = 0; j < 3; j++)
		{
			if (ar[i] < ar[j]) {
				q.push(make_pair(ar[i], ar[j]));
				check[ar[i]][ar[j]] = true;
			}
		}

	int t1, t2;
	while (!q.empty())
	{
		t1 = q.front().first;
		t2 = q.front().second;
		q.pop();
		t2 -= t1;
		t1 *= 2;
		int br[] = { t1, t2, sum - t1 - t2 };
		
		if (t1 == t2 && t1 == (sum - t1 -t2))
		{
			cout << 1;
			return 0;
		}
		check[t1][t2] = true;

		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				if (br[i] < br[j] && check[br[i]][br[j]] == false) {
					check[br[i]][br[j]] = true;
					q.push(make_pair(br[i], br[j]));
				}
			}
	}
	cout << 0;
}