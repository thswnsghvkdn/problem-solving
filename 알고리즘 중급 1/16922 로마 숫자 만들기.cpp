#include <iostream>
using namespace std;

bool visit[1000]; // 정답의 중복을 체크
int number[] = { 1, 5, 10 ,50 }; // 4개의 숫자
int depth; // 목표 깊이
int ans;
void dfs(int stage , int sum , int index) // 현재 스테이지 , 현재까지 합 , 이전 인덱스
{
	if (stage == depth) // 목표깊이에 도달했다면
	{
		if (!visit[sum]) // 해당합이 나온적 없다면
		{
			visit[sum] = true;
			ans++;
		}
		return;
	}

	for (int i = index; i < 4; i++) // 이전 인덱스부터 시작해야 중복을 피할 수 있다. ex ) ( 1 + 2 ) == ( 2 + 1 )
		dfs(stage + 1, sum + number[i], i);

}

int main()
{
	cin >>depth; 
	dfs(0, 0, 0);
	cout << ans;
}