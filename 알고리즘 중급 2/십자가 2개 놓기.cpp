#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

char mp[16][16];
int n, m;

bool check_range(int r, int c, int k) // 0 과 n,m 사이인지 범위를 검사한다.
{
	for (int i = -1; i <= 1; i += 2) // 양방향을 검사한다.
	{
		if (r + k * i < 0 || r + k * i >= n || c + k * i < 0 || c + k * i >= m)
			return false;
	}
	return true;
}

int second_star(int r, int c) // 두 번째 별의 최대 크기를 반환하는 함수
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

