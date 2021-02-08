#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int dx[4] = { 1, -1,0 ,0 };
int dy[4] = { 0 , 0, 1, -1 };

map< pair<string ,string > , int> mp;
int sToI(char c)
{
	switch (c)
	{
	case 'U': return 0;
	case 'D': return 1;
	case 'R': return 2;
	case 'L': return 3;
	}
}
int solution(string dirs) {
	string f = "00", e = "00";
	int answer = 0;
	int x = 0, y = 0;
	f[0] = x, f[1] = y;


	for (int i = 0; i < dirs.length() ; i++)
	{
		char t = dirs[i];
		int nx = x + dx[sToI(t)];
		int ny = y + dy[sToI(t)];
		if (nx < -5 || nx > 5 || ny < -5 || ny > 5) continue;
		e[0] = nx; e[1] = ny;
		if (!mp[{f,e}]) {
			answer++;
			mp[{f, e}]++;
			mp[{e, f}]++;
		}
		x = nx;
		y = ny;
		f[0] = x; f[1] = y;
	}
	return answer;
}

int main() {
 cout << solution("ULURRDLLU");
 cout << solution("LULLLLLLU");
}