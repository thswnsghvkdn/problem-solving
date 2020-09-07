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
vector<vector<int>> rotate_1(vector<vector<int>> n_key) // �ð�������� ȸ�� ���� ������ �ٲپ� ȸ����Ų��.
{
	int size = 60; // �ѿ��� ũ��
	vector<vector<int>> temp;
	init(temp);
	for (int j = 0; j < size; j++)
		for (int i = size - 1, n_i = 0; i >= 0; i--, n_i++) 
			if (n_key[i][j])
				temp[j][n_i-37] = 1;

	return temp;
}
vector<vector<int>> rotate_2(vector<vector<int>> n_key) // �ð�ݴ�������� ȸ�� ���� ������ �ٲپ� ȸ����Ų��.
{
	int size = 60; // �ѿ��� ũ��
	vector<vector<int>> temp;
	init(temp);
	for (int j = size - 1, n_j = 0; j >= 0; j--, n_j++)
		for (int i = 0; i < size; i++) 
			if (n_key[i][j])
				temp[n_j- 37][i] = 1;


	return temp;
}
vector<vector<int>> n_move(vector<vector<int>> n_key, int n) // key �����̱�
{
	vector<vector<int>> temp ;
	init(temp);
	int cnt = 0;
	switch (n)
	{
	case 1: // ���οø���
		for(int i = 0; i < 60 ; i++)
			for (int j = 0; j < 60; j++) 
				if (n_key[i][j]) {
					if (i - 1 < 0) {
						temp[0][0] = -1; // ������ ������ -1�� �����Ͽ� ����
						return temp;
					}
					temp[i - 1][j] = 1;
				}
		break;
	case 2: // ������
		for (int i = 0; i < 60; i++)
			for (int j = 0; j < 60; j++)
				if (n_key[i][j]) {
					if (j + 1 >= 60) {
						temp[0][0] = -1; // ������ ������ -1�� �����Ͽ� ����
						return temp;
					}
					temp[i][j + 1] = 1;
				}
		break;
	case 3: // �Ʒ���
		for (int i = 0; i < 60; i++)
			for (int j = 0; j < 60; j++)
				if (n_key[i][j]) {
					if (i + 1 >= 60) {
						temp[0][0] = -1; // ������ ������ -1�� �����Ͽ� ����
						return temp;
					}
					temp[i + 1][j] = 1;
				}
		break;
	case 4: // ����
		for (int i = 0; i < 60; i++)
			for (int j = 0; j < 60; j++)
				if (n_key[i][j]) {
					if (j - 1 < 0) {
						temp[0][0] = -1; // ������ ������ -1�� �����Ͽ� ����
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
			n_map[i+20][j+20] = key[i][j]; // key�迭�� �е�
		
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
