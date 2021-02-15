#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int mp[52][52];
int v[52];

int getSmall(int N)
{
    int m_value = 500001;
    int index = 0;
    for (int i = 1; i <= N; i++)
    {
        if (!v[i] && mp[1][i] < m_value)
        {
            m_value = mp[1][i];
            index = i;
        }
    }
    v[index] = true;
    return index;
}

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    for (int i = 0; i < 52; i++)
        for (int j = 0; j < 52; j++) {
            if (i == j) mp[i][j] = 0;
            else
             mp[i][j] = 500001;
        }

    for (int i = 0; i < road.size(); i++)
    {
        int x, y, z;
        x = road[i][0];
        y = road[i][1];
        z = min( road[i][2], mp[x][y]);
        mp[x][y] = mp[y][x] = z;
    }
    v[1] = true;

    for (int i = 1; i <= N; i++)
    {
        int current = getSmall(N);
        for (int j = 1; j <= N; j++) 
            mp[1][j] = min(mp[1][j], mp[1][current] + mp[current][j]);
    }

    for (int i = 1; i <= N; i++)
        if (mp[1][i] <= K) answer++;

    return answer;
}

int main()
{
    cout << solution(5, { {1, 2, 1} ,{1, 3, 2}, {2, 3, 2},{3, 4, 3}, {3, 5, 2},{3, 5, 3},{5, 6, 1} }, 4);

}