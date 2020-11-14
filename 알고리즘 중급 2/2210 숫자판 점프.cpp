
1
#include <iostream>
2
#include <vector>
3
#include <algorithm>
4
using namespace std;
5
int dx[] = { -1, 0 ,1, 0 };
6
int dy[] = { 0 , 1 , 0 , -1 };
7
​
8
struct Point {
9
    int x, y;
10
};
11
​
12
int map[5][5];
13
vector<int> n_ans;
14
​
15
void dfs(int cnt, Point p, int str)
16
{
17
    if (cnt == 6)
18
    {
19
        n_ans.push_back(str);
20
       
21
        return;
22
    }
23
​
24
​
25
    for (int i = 0; i < 4; i++)
26
    {
27
        int nx = p.x + dx[i];
28
        int ny = p.y + dy[i];
29
        
30
        if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
31
​
32
        int t_str = str * 10;
33
        t_str += map[nx][ny];
34
        dfs(cnt + 1, { nx , ny }, t_str);
35
    }
36
}
37
​
38
int main()
39
{
40
    for (int i = 0; i < 5; i++)
41
        for (int j = 0; j < 5; j++)
42
            cin >> map[i][j];
43
    for (int i = 0; i < 5; i++)
44
        for (int j = 0; j < 5; j++)
45
            dfs(1, { i , j }, map[i][j]);
46
    sort(n_ans.begin(), n_ans.end());
47
    n_ans.erase(unique(n_ans.begin(), n_ans.end()), n_ans.end());
48
    cout << n_ans.size();
49
}
