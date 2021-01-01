#include <iostream>
#include <queue>
using namespace std;

struct Player {
	int hand[20];
	int win; // 이긴횟수
	int round; // 플레이할 라운드
};

// 두 명의 플레이어가 낼 손
int hand1[20];
int hand2[20];

int n, k;
int rule[10][10]; // 가위바위보 족보

int who_win(int p1, int p2) // 앞 사람과 뒤사람중 이긴 사람반환
{
	if (rule[p1][p2] == 2) // p1이 이긴경우
	{
		return 1;
	}
	else
	{
		return 2;
	}
}

int dfs(Player p[3], int p1, int p2) // 이긴 횟수와 각자 손을 낼 차례. 플레이할 두명
{
	for(int i = 0 ; i < 3 ; i++)
		if (p[i].win == k)
		{
			if (i == 0) {
				cout << 1;
				return 1;
			}// 지우가 이긴경우
			else return 0;
		}

	if (p1 == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == p[0].hand[p[0].round]) continue;
			p[0].hand[++p[0].round] = i;
			if (who_win(i, p[p2].hand[p[p2].round++]) == 1) {
				p[0].win++;
				if( dfs(p, 0, 3 - p2) == 1 ) return 1;
				p[0].win--;
			}
			else
			{
				p[p2].win++;
				if(dfs(p, p2, 3 - p2) == 1 ) return 1;
				p[p2].win--;
			}
			p[0].round--;
			p[p2].round--;
		}
	}
	else if (p2 == 0)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == p[0].hand[p[0].round]) continue;
			p[0].hand[++p[0].round] = i;

			if (who_win(p[p1].hand[p[p1].round++], i) == 1) 
			{
				p[p1].win++;
				if( dfs(p, p1, 3 - p1) == 1 ) return 1;
				p[p1].win--;
			}
			else
			{
				p[0].win++;
				if( dfs(p, 0, 3 - p1) ) return 1;
				p[0].win--;
			}
			p[0].round--;
			p[p1].round--;
		}
	}
	else
	{
		if (who_win(p[p1].hand[p[p1].round++], p[p2].hand[p[p2].round++]) == 1)
			return dfs(p, p1, 0);
		else
			return dfs(p, p2, 0);
	}


}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cin >> rule[i][j];

	Player p[3];

	for (int i = 0; i < 3; i++)
		p[i].round = p[i].win = 0;

	for (int i = 0; i < 20; i++)
		cin >> p[1].hand[i];
	for (int i = 0; i < 20; i++)
		cin >> p[2].hand[i];

	for (int i = 0; i < n; i++)
	{
		p[0].hand[0] = i;
		if (dfs(p, 0 ,1) == 1 ) return 0;
		for (int j = 0; j < 3; j++)
			p[j].round = p[j].win = 0;
	}
}