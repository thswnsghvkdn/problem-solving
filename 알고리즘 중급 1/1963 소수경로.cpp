#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n_prime[9][10][10][10];
bool check[10000];

void check_prime(int j)
{
	int a, b, c, d;
	a = j / 1000;
	j %= 1000;
	b = j / 100;
	j %= 100;
	c = j / 10;
	d = j % 10;
	n_prime[a][b][c][d] = true;
}

int main()
{
	// 네자리수중 소수인거 일일이 찾기
	for (int i = 1000; i < 10000; i++)
	{
		for (int j = 2; j < 10000; j++)
		{
			if (i > 2000 )
				cout << "";



			if (j == i) break;
			if (i % j == 0)
			{
				check_prime(i); 
				break;
			}
		}
	}

	int t;
	cin >> t;
	bool flag;
	while (t--)
	{
		flag = false;
		int visit[10000] = { 0 };
		memset(visit, -1, sizeof(visit));

		queue<int> q;
		int start, end;
		cin >> start >> end;
		q.push(start);
		visit[start] = 0;
		
		while (!q.empty()) 
		{ 
			if (flag == true) break;
			int num = q.front();
			int temp = num;
			q.pop();
			int a, b, c, d;
			a = temp / 1000;
			temp %= 1000;
			b = temp / 100;
			temp %= 100;
			c = temp / 10;
			d = temp % 10;
			
			int n_num;
			for (int i = 1; i < 10; i++) // 한자리씩 바꾸어가면서 큐에 집어넣는다.
			{
				if (n_prime[i][b][c][d] == false)
				{
					if (a == i) continue;
					n_num = i * 1000 + b * 100 + c * 10 + d;
					if (visit[n_num] == -1 || visit[n_num] > visit[num] + 1)
					{
						if (n_num == end) flag = true;
						visit[n_num] = visit[num] + 1;
						q.push(n_num);
					}
				}
			}
			for (int i = 0; i < 10; i++)
			{
				if (b == i) continue;
				if (n_prime[a][i][c][d] == false)
				{
					n_num = a * 1000 + i * 100 + c * 10 + d;
					if (visit[n_num] == -1 || visit[n_num] > visit[num] + 1)
					{
						if (n_num == end) flag = true;
						visit[n_num] = visit[num] + 1;
						q.push(n_num);
					}
				}
			}			
			for (int i = 0; i < 10; i++)
			{
				if (c == i) continue;
				if (n_prime[a][b][i][d] == false)
				{
					n_num = a * 1000 + b * 100 + i * 10 + d;
					if (visit[n_num] == -1 || visit[n_num] > visit[num] + 1)
					{
						if (n_num == end) flag = true;
						visit[n_num] = visit[num] + 1;
						q.push(n_num);
					}
				}
			}			
			for (int i = 0; i < 10; i++)
			{
				if (d == i) continue;
				if (n_prime[a][b][c][i] == false)
				{
					n_num = a * 1000 + b * 100 + c * 10 + i;
					if (visit[n_num] == -1 || visit[n_num] > visit[num] + 1)
					{
						if (n_num == end) flag = true;
						visit[n_num] = visit[num] + 1;
						q.push(n_num);
					}
				}
			}


		}

		cout << visit[end] << endl;
	}
}