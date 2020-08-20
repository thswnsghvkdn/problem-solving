#include <iostream>
#include <queue>
#include <algorithm>
#include <memory.h>
using namespace std;

int n_prime[9][10][10][10];
bool check[10000];

int prime[10000];


int check_prime(int i, int j, int n)  // ���ڸ��� �ٸ� ���ڷ� �ٲپ� ��ȯ
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
	// ���ڸ����� �Ҽ��ΰ� ������ ã��
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
			for (int i = 0; i < 4; i++) // ���ڸ��� �ٲپ�鼭 ť�� ����ִ´�.
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