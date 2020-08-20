#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n_prime[9][10][10][10];
bool check[10000];

int prime[10000];


int check_prime(int i, int j, int n)  // 한자리씩 다른 숫자로 바꾸어 반환
{
	int k;
	if (i == 0)
	{
		n %= 1000;
		return n + (j * 1000);
	}
	if (i == 1)
	{
		k = n / 1000;
		n %= 100;
		return n + (k * 1000) + (j * 100);
	}
	if (i == 2)
	{
		k = n / 100;
		n %= 10;
		return n + (k * 100) + (j * 10);
	}
	else
	{
		k = n / 10;
		return k * 10 + j;
	}
}

int main()
{
	// 네자리수중 소수인거 일일이 찾기
	for (int i = 1000; i < 10000; i++)
		for (int j = 2; j < i; j++)
			if (i % j == 0)
			{
				check[i] = true;
				break;
			}
		
	int t;
	cin >> t;
	bool flag;
	while (t--)
	{
		int visit[10000] = { 0 };
		flag = false;

		queue<pair<int, int>> q;
		int start, end;
		cin >> start >> end;
		q.push(make_pair(start,0));
		visit[start] = 1;
		
		while (!q.empty()) 
		{ 
			auto temp = q.front();
			q.pop();
			if (temp.first == end)
			{
				flag = true;
				cout << temp.second << endl;
			}

			int n;
			for (int i = 0; i < 4; i++) // 한자리씩 바꾸어가면서 큐에 집어넣는다.
				for (int j = 0; j <= 9; j++)
				{
					n = check_prime(i, j, temp.first);
					if (check[n] == false && visit[n] == false && n >= 1000) {
						visit[n] = true;
						q.push(make_pair(n, temp.second + 1));
					}
				}

		}
		if (flag == false)
		cout << "Impossible!" << endl;
	}
}