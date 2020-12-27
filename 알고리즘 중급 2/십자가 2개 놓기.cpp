#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char mp[16][16];
int n, m;

bool check_range(int r, int c, int k) // 0 �� n,m �������� ������ �˻��Ѵ�.
{
	for (int i = -1; i <= 1; i += 2) // ������� �˻��Ѵ�.
	{
		if (r + k * i < 0 || r + k * i >= n || c + k * i < 0 || c + k * i >= m)
			return false;
	}
	return true;
}

int second_star(int r, int c) // �� ��° ���� �ִ� ũ�⸦ ��ȯ�ϴ� �Լ�
{
	int k;
	int max_size = 1;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
		{
			if (mp[i][j] != '#') continue;
			k = 1;
			while (check_range(i, j, k) && mp[i + k][j] == '#' && mp[i - k][j] == '#' && mp[i][j + k] == '#' && mp[i][j - k] == '#')
			{
				k++;
			}
			max_size = max(max_size, --k * 4 + 1);
		}

	return max_size;
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			cin >> mp[i][j];

	int first_size, second_size, k, tot_size = 0;
	
	for(int i = 0 ; i < n ; i++)
		for (int j = 0; j < m; j++)
		{
			if (mp[i][j] != '#') continue;
			k = 0;
			while (check_range(i, j, k) && mp[i + k][j] == '#' && mp[i - k][j] == '#' && mp[i][j + k] == '#' && mp[i][j - k] == '#')
			{
				mp[i + k][j] = mp[i - k][j] = mp[i][j + k] = mp[i][j - k] = '.';
				first_size = k * 4 + 1;
				second_size = second_star(i, j);
				tot_size = max(tot_size, first_size * second_size);
				k++;
			}
			
			for(int l = 0; l < k ; l++)
				mp[i + l][j] = mp[i - l][j] = mp[i][j + l] = mp[i][j - l] = '#';
		}

	cout << tot_size;
}

