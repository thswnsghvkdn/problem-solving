#include <string>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;


void init(vector<vector<int>>& map)
{
	vector<int> temp(60);
	for (int i = 0; i < 60; i++)
		map.push_back(temp);


}
vector<vector<int>> rotate_1(vector<vector<int>> n_key) // 시계방향으로 회전 보는 방향을 바꾸어 회전시킨다.
{
	int size = 60; // 한열의 크기
	vector<vector<int>> temp;
	init(temp);
	for (int j = 0; j < size; j++)
		for (int i = size - 1, n_i = 0; i >= 0; i--, n_i++) 
			if (n_key[i][j])
				temp[j][n_i-37] = 1;

	return temp;
}
vector<vector<int>> rotate_2(vector<vector<int>> n_key) // 시계반대방향으로 회전 보는 방향을 바꾸어 회전시킨다.
{
	int size = 60; // 한열의 크기
	vector<vector<int>> temp;
	init(temp);
	for (int j = size - 1, n_j = 0; j >= 0; j--, n_j++)
		for (int i = 0; i < size; i++) 
			if (n_key[i][j])
				temp[n_j- 37][i] = 1;


	return temp;
}
vector<vector<int>> n_move(vector<vector<int>> n_key, int n) // key 움직이기
{
	vector<vector<int>> temp ;
	init(temp);
	int cnt = 0;
	switch (n)
	{
	case 1: // 위로올리기
		for(int i = 0; i < 60 ; i++)
			for (int j = 0; j < 60; j++) 
				if (n_key[i][j]) {
					if (i - 1 < 0) {
						temp[0][0] = -1; // 범위를 벗어날경우 -1을 포함하여 리턴
						return temp;
					}
					temp[i - 1][j] = 1;
				}
		break;
	case 2: // 오른쪽
		for (int i = 0; i < 60; i++)
			for (int j = 0; j < 60; j++)
				if (n_key[i][j]) {
					if (j + 1 >= 60) {
						temp[0][0] = -1; // 범위를 벗어날경우 -1을 포함하여 리턴
						return temp;
					}
					temp[i][j + 1] = 1;
				}
		break;
	case 3: // 아래쪽
		for (int i = 0; i < 60; i++)
			for (int j = 0; j < 60; j++)
				if (n_key[i][j]) {
					if (i + 1 >= 60) {
						temp[0][0] = -1; // 범위를 벗어날경우 -1을 포함하여 리턴
						return temp;
					}
					temp[i + 1][j] = 1;
				}
		break;
	case 4: // 왼쪽
		for (int i = 0; i < 60; i++)
			for (int j = 0; j < 60; j++)
				if (n_key[i][j]) {
					if (j - 1 < 0) {
						temp[0][0] = -1; // 범위를 벗어날경우 -1을 포함하여 리턴
						return temp;
					}
					temp[i][j - 1] = 1;
				}
		break;
	case 5:
		temp = rotate_1(n_key);
		break;
	case 6:
		temp = rotate_2(n_key);
		break;
	}


			
	return temp;
}
bool unlock(vector<vector<int>> n_key, vector<vector<int>> lock)
{
	int size = lock[0].size();
	for(int i = 0 ; i < size ; i ++)
		for (int j = 0; j < size; j++)
		{
			if (n_key[i + 20][j + 20] && lock[i][j])
				return false;
			if (!n_key[i + 20][j + 20] && !lock[i][j])
				return false;

		}
	return true;
}
bool solution(vector<vector<int>>key, vector<vector<int>>lock) {
	bool answer = false;
	vector<vector<int>> n_map;
	init(n_map);
	for(int i = 0 ; i < key[0].size() ; i++)
		for (int j = 0; j < key[0].size(); j++)
			n_map[i+20][j+20] = key[i][j]; // key배열에 패딩
		
	queue<vector<vector<int>>>q;
	q.push(n_map);
	while (!q.empty()) {
		auto temp = q.front();
		q.pop();
		for (int i = 1; i <= 6; i++) {
			vector<vector<int>> n_key;
			init(n_key);
			n_key = n_move(temp,i);
			if (n_key[0][0] == -1) continue;
			if (unlock(n_key, lock)) return true;
			q.push(n_key);
		}
	}
	return answer;
}
int main()
{
	solution({ {0, 0, 0},{1, 0, 0},{ 0, 1, 1} }, { {1, 1, 1}, {1, 1, 0},{1, 0, 1} });

}
