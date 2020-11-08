#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point // cctv의 위치 정보 구조체
{
    int x; // 행
    int y; // 열
    int number; // cctv 종류
};
bool isVisit[8];
int dx[] = { -1 , 0 , 1 , 0 }; // 행의 4방향
int dy[] = { 0 , 1 , 0 , -1 }; // 열의 4방향
int visit[10][10]; // 2차원 벡터의 방문표시
int v[10][10]; // 2차원 배열
int row, col; // 사용자에게 입력받을 2차원 벡터의 크기 
vector<Point> cctv;
int ans = 100; // 가장 최소값을 저장해야 하는 ans는 최대값으로 초기화한다.

int blindSpot() // 사각지대를 반환하는 
{
    int spot = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!visit[i][j]) spot++;
    return spot;
}
void drawcctv(int index, int rot, Point cctv) // cctv 타입, 회전방향, cctv 정보 
{
    int cnt = cctv.number;
    if (cctv.number > 2) cnt--; // 3번 이상인 경우 cnt반복을 순차대로 진행할 경우 cctv방향이 완성된다.

    for (int i = 0; i < cnt; i++) {
        int nx = cctv.x;
        int ny = cctv.y;
        while (1)
        {
            // 회전방향쪽으로 계속 진행
            nx += dx[(rot + i) % 4];
            ny += dy[(rot + i) % 4];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col || visit[nx][ny] == 6)
                break;
            if (visit[nx][ny] != 0) continue;
            visit[nx][ny] = index + 6; // 나중에 지우기 편하게 하기위해 index로 표시한다. 
        }
        if (cctv.number == 2) rot++; // 2번 방향은 한번에 방향이 두번씩 증가해야 한다.
    }
}

void erasecctv(int index, int rot, Point cctv) // cctv 타입, 회전방향, cctv 정보 
{
    int nx = cctv.x;
    int ny = cctv.y;
    int cnt = cctv.number;
    if (cctv.number > 2) cnt--; // 3번 이상인 경우 cnt반복을 순차대로 진행할 경우 cctv방향이 완성된다.

    for (int i = 0; i < cnt; i++) {
        while (1)
        {
            // 회전방향쪽으로 계속 진행
            nx += dx[(rot + i) % 4];
            ny += dy[(rot + i) % 4];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col || visit[nx][ny] == 6)
                break;
            if (visit[nx][ny] != index + 6) continue;
            visit[nx][ny] = 0; // index를 지운다.
        }
        if (cctv.number == 2) rot++; // 2번 방향은 한번에 방향이 두번씩 증가해야 한다.
    }
}

int countcctv(Point cctv) // cctv 타입, 회전방향, cctv 정보 0의 갯수를 센다.
{
    int rot = 0;
    int cnt = cctv.number;
    int direction;
    int max = 0;
    int temp = 0;
    int r = 4;
    if (cctv.number > 2) cnt--; // 3번 이상인 경우 cnt반복을 순차대로 진행할 경우 cctv방향이 완성된다.

    while (r--) {

        temp = 0;
        for (int i = 0; i < cnt; i++) {
            int nx = cctv.x;
            int ny = cctv.y;
            while (1)
            {
                // 회전방향쪽으로 계속 진행
                nx += dx[(rot + i) % 4];
                ny += dy[(rot + i) % 4];
                if (nx < 0 || nx >= row || ny < 0 || ny >= col || visit[nx][ny] == 6)
                    break;
                if (visit[nx][ny] != 0) continue;
                temp++; // 나중에 지우기 편하게 하기위해 index로 표시한다. 
            }
            if (cctv.number == 2) rot++; // 2번 방향은 한번에 방향이 두번씩 증가해야 한다.
        }
        if (temp >= max) {
            direction = rot;
            max = temp;
        }
        rot++;
        if (cctv.number == 2) rot++;
    }
    return direction;
}
void dfs(int cnt)
{
    if (cnt == cctv.size()) // 모든 cctv 방향설정이 끝났다면
    {
        ans = min(ans, blindSpot());
        return;
    }
    for (int i = 0; i < cctv.size(); i++)
    {
        if (isVisit[i] == true) continue;
        else {
            isVisit[i] = true;
            auto temp = cctv[i];
            for (int j = 0; j < 4; j++) // 회전 4방향
            {
                drawcctv(i + 1, j, temp);
                dfs(cnt + 1);
                erasecctv(i + 1, j, temp);
            }
            isVisit[i] = false;
        }

    }
}

int main()
{
    cin >> row >> col;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++) {
            cin >> v[i][j];
            visit[i][j] = v[i][j];
            if (v[i][j] != 0 && v[i][j] != 6) // cctv인 경우
                cctv.push_back({ i,j,v[i][j] }); // cctv의 위치와 종류 저장
        }
    for (int i = 0; i < cctv.size(); i++)
    {
        auto temp = cctv[i];
        int dir = countcctv(temp);
        drawcctv(i + 1, dir, cctv[i]);
    }

    cout << blindSpot();
}