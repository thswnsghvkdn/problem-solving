#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num; // 수열의 개수
vector<int> v; // 등차수열 
vector<int> v2;
int ans = -1;

int main()
{
	int temp;
	cin >> num;
	for (int i = 0; i < num; i++)
	{
		cin >> temp;
		v.push_back(temp);
		v2.push_back(temp);
	}
	int temp_ans = 0;
	if (num == 1)
	{
		cout << 0;
		return 0;
	}
	for (int i = -1; i < 2; i++) {
		for (int j = -1; j < 2; j++)
		{
			temp_ans = 0;
			int ans_flag = true;
			v2[0] = v[0] + i;
			v2[1] = v[1] + j;
			int diff = v2[0] - v2[1];
			if (i != 0) temp_ans++;
			if (j != 0) temp_ans++;
			for (int k = 2; k < num; k++)
			{
				int new_diff = v2[k - 1] - v[k];
				int flag = false;

				for (int l = -1; l < 2; l++)
				{
					if (new_diff + l == diff)
					{
						flag = true;
						v2[k] = v[k] - l;
						if (l != 0) temp_ans++;
						break;
					}
				}
				v2[k - 1] = v[k - 1];
				if (!flag)
				{
					ans_flag = false; 
					break;
				}
			}
			if (ans_flag)
			{
				if (ans == -1 || ans > temp_ans)
					ans = temp_ans;
			}

			v2[0] = v[0];
			v2[1] = v[1];
		}
	}
	cout << ans;
}