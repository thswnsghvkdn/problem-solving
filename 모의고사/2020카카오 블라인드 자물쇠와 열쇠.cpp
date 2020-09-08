#include <string>
#include <vector>
#include <queue>
#include  <algorithm>
using namespace std;
int k_size;
struct model {
	vector<pair<int, int>> key;
	int size;
	string route;
};
vector<string> visit;
bool find_r(string route)
{
	for (int i = 0; i < visit.size(); i++)
		if (route == visit[i]) return false;
	return true;
}
model n_move(model m, int n)
{
	model temp;
	
	int size = 0;
	switch (n)
	{
		temp.size = 0;
		int nx, ny;
			case 0: // 위로 이동
			{
				for (int i = 0; i < m.key.size(); i++)
				{

					nx = m.key[i].first - 1;
					ny = m.key[i].second;
					char a = '0' + nx;
					char b = '0' + ny;
					temp.route += a;
					temp.route += b;
					if (nx >= 0) size++;
					temp.key.push_back(make_pair(nx, ny));
				}
				temp.size = size;
				break;
			}
			case 1: // 오른쪽으로 이동
			{
				for (int i = 0; i < m.key.size(); i++)
				{
					nx = m.key[i].first;
					ny = m.key[i].second + 1;
					char a = '0' + nx;
					char b = '0' + ny;
					temp.route += a;
					temp.route += b;
					if (ny <= k_size) size++;
					temp.key.push_back(make_pair(nx, ny));
				}
				temp.size = size;
				break;
			}
			case 2: // 아래쪽으로 이동
			{
				for (int i = 0; i < m.key.size(); i++)
				{
					nx = m.key[i].first + 1;
					ny = m.key[i].second;
					char a = '0' + nx;
					char b = '0' + ny;
					temp.route += a;
					temp.route += b;
					if (nx <= k_size) size++;
					temp.key.push_back(make_pair(nx, ny));
				}
				temp.size = size;
				break;
			}
			case 3: // 왼쪽으로 이동
			{
				for (int i = 0; i < m.key.size(); i++)
				{
					nx = m.key[i].first;
					ny = m.key[i].second - 1;
					char a = '0' + nx;
					char b = '0' + ny;
					temp.route += a;
					temp.route += b;

					if (ny >= 0) size++;
					temp.key.push_back(make_pair(nx, ny));
				}
				temp.size = size;
				break;
			}
			case 4: // 시계방향 회전
			{
				temp.size = m.size;
				for (int i = 0; i < m.key.size(); i++)
				{
					nx = m.key[i].second;
					ny = abs(m.key[i].first - k_size);
					char a = '0' + nx;
					char b = '0' + ny;
					temp.route += a;
					temp.route += b;
					temp.key.push_back(make_pair(nx, ny));
				}
				break;
			}
			case 5: // 시계반대 방향 회전
			{
				temp.size = m.size;
				for (int i = 0; i < m.key.size(); i++)
				{
					nx = abs(m.key[i].second - k_size);
					ny = m.key[i].first;
					char a = '0' + nx;
					char b = '0' + ny;
					temp.route += a;
					temp.route += b;
					temp.key.push_back(make_pair(nx, ny));
				}
				break;
			}
	}
	return temp;
}
bool unlocked(model key, model lock)
{
	int cnt = 0;
	bool flag;
	for (int i = 0; i < key.key.size(); i++)
	{
		flag = false;
		if (key.key[i].first < 0 || key.key[i].first > k_size || key.key[i].second < 0 || key.key[i].second > k_size) continue;
		for (int j = 0; j < lock.key.size(); j++)
			if (key.key[i].first == lock.key[j].first && key.key[i].second == lock.key[j].second) {
				flag = true;
				cnt++;
				break;
			}
		if (!flag) return false;
	}
	return cnt == lock.size;
}
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	k_size = key[0].size()-1;
	model k, l;
	k.size = 0;
	l.size = 0;
	string route;
	for(int i = 0 ; i < key[0].size() ; i++)
		for (int j = 0; j < key[0].size(); j++)
		{
			if (key[i][j]) // key는 1위치를 저장
			{
				k.key.push_back(make_pair(i, j));
				char a = '0' + i;
				char b = '0' + j;
				route += a;
				route += b;

				k.size++;
			}
			if (!lock[i][j]) // lock는 0위치를 저장
			{
				l.key.push_back(make_pair(i, j));
				l.size++;
			}
		}
	visit.push_back(route);
	if (unlocked(k, l)) return true;
	queue<model> q;
	q.push(k);
	while (!q.empty())
	{
		auto temp = q.front();
		q.pop();
		for (int i = 0; i < 6; i++)
		{
			model n_key = n_move(temp, i);
			if (n_key.size && find_r(n_key.route))
			{
				visit.push_back(n_key.route);
				if (unlocked(n_key, l)) return true;
				q.push(n_key);
			}
		}
	}

	return answer;
}
int main()
{
	solution({ {0, 0, 0},{1, 0, 0},{0, 1, 1} }, { {1, 1, 1},{1, 1, 0},{1, 0, 1 } });
}