#include <iostream>
using namespace std;

bool visit[1000]; // ������ �ߺ��� üũ
int number[] = { 1, 5, 10 ,50 }; // 4���� ����
int depth; // ��ǥ ����
int ans;
void dfs(int stage , int sum , int index) // ���� �������� , ������� �� , ���� �ε���
{
	if (stage == depth) // ��ǥ���̿� �����ߴٸ�
	{
		if (!visit[sum]) // �ش����� ������ ���ٸ�
		{
			visit[sum] = true;
			ans++;
		}
		return;
	}

	for (int i = index; i < 4; i++) // ���� �ε������� �����ؾ� �ߺ��� ���� �� �ִ�. ex ) ( 1 + 2 ) == ( 2 + 1 )
		dfs(stage + 1, sum + number[i], i);

}

int main()
{
	cin >>depth; 
	dfs(0, 0, 0);
	cout << ans;
}