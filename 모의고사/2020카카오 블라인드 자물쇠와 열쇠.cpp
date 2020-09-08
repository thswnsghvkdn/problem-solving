#include <string>
#include <vector>

using namespace std;
int k_size;
bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = true;
	k_size = key[0].size();
	vector<int> row(k_size); // �� ���� ��Ʈ
	vector<int> col(k_size); // �� ���� ��Ʈ
	for (int i = 0; i < k_size; i++) {
		row[i] = 0;
		for (int j = 0; j < k_size; j++)
		{
			if (key[i][j]) row[i] += 1;
			row[i] << 1;
		}
		row[i] << 20; // �е�
	}
	for (int j = 0; j < k_size; j++) {
		col[j] = 0;
		for (int i = 0; i < k_size; i++)
		{
			if (key[i][j]) col[j] += 1;
			col[j] << 1;
		}
		col[j] << 20;
	}


	return answer;
}