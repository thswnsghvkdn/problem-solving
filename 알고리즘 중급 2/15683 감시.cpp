#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point // cctv�� ��ġ ���� ����ü
{
    int x; // ��
    int y; // ��
    int number; // cctv ����
};
bool isVisit[8];
int dx[] = { -1 , 0 , 1 , 0 }; // ���� 4����
int dy[] = { 0 , 1 , 0 , -1 }; // ���� 4����
int visit[10][10]; // 2���� ������ �湮ǥ��
int v[10][10]; // 2���� �迭
int row, col; // ����ڿ��� �Է¹��� 2���� ������ ũ�� 
vector<Point> cctv;
int ans = 100; // ���� �ּҰ��� �����ؾ� �ϴ� ans�� �ִ밪���� �ʱ�ȭ�Ѵ�.

int blindSpot() // �簢���븦 ��ȯ�ϴ� 
{
    int spot = 0;
    for (int i = 0; i < row; i++)
        for (int j = 0; j < col; j++)
            if (!visit[i][j]) spot++;
    return spot;
}
void drawcctv(int index, int rot, Point cctv) // cctv Ÿ��, ȸ������, cctv ���� 
{
    int cnt = cctv.number;
    if (cctv.number > 2) cnt--; // 3�� �̻��� ��� cnt�ݺ��� ������� ������ ��� cctv������ �ϼ��ȴ�.

    for (int i = 0; i < cnt; i++) {
        int nx = cctv.x;
        int ny = cctv.y;
        while (1)
        {
            // ȸ������������ ��� ����
            nx += dx[(rot + i) % 4];
            ny += dy[(rot + i) % 4];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col || visit[nx][ny] == 6)
                break;
            if (visit[nx][ny] != 0) continue;
            visit[nx][ny] = index + 6; // ���߿� ����� ���ϰ� �ϱ����� index�� ǥ���Ѵ�. 
        }
        if (cctv.number == 2) rot++; // 2�� ������ �ѹ��� ������ �ι��� �����ؾ� �Ѵ�.
    }
}

void erasecctv(int index, int rot, Point cctv) // cctv Ÿ��, ȸ������, cctv ���� 
{
    int nx = cctv.x;
    int ny = cctv.y;
    int cnt = cctv.number;
    if (cctv.number > 2) cnt--; // 3�� �̻��� ��� cnt�ݺ��� ������� ������ ��� cctv������ �ϼ��ȴ�.

    for (int i = 0; i < cnt; i++) {
        while (1)
        {
            // ȸ������������ ��� ����
            nx += dx[(rot + i) % 4];
            ny += dy[(rot + i) % 4];
            if (nx < 0 || nx >= row || ny < 0 || ny >= col || visit[nx][ny] == 6)
                break;
            if (visit[nx][ny] != index + 6) continue;
            visit[nx][ny] = 0; // index�� �����.
        }
        if (cctv.number == 2) rot++; // 2�� ������ �ѹ��� ������ �ι��� �����ؾ� �Ѵ�.
    }
}

int countcctv(Point cctv) // cctv Ÿ��, ȸ������, cctv ���� 0�� ������ ����.
{
    int rot = 0;
    int cnt = cctv.number;
    int direction;
    int max = 0;
    int temp = 0;
    int r = 4;
    if (cctv.number > 2) cnt--; // 3�� �̻��� ��� cnt�ݺ��� ������� ������ ��� cctv������ �ϼ��ȴ�.

    while (r--) {

        temp = 0;
        for (int i = 0; i < cnt; i++) {
            int nx = cctv.x;
            int ny = cctv.y;
            while (1)
            {
                // ȸ������������ ��� ����
                nx += dx[(rot + i) % 4];
                ny += dy[(rot + i) % 4];
                if (nx < 0 || nx >= row || ny < 0 || ny >= col || visit[nx][ny] == 6)
                    break;
                if (visit[nx][ny] != 0) continue;
                temp++; // ���߿� ����� ���ϰ� �ϱ����� index�� ǥ���Ѵ�. 
            }
            if (cctv.number == 2) rot++; // 2�� ������ �ѹ��� ������ �ι��� �����ؾ� �Ѵ�.
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
    if (cnt == cctv.size()) // ��� cctv ���⼳���� �����ٸ�
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
            for (int j = 0; j < 4; j++) // ȸ�� 4����
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
            if (v[i][j] != 0 && v[i][j] != 6) // cctv�� ���
                cctv.push_back({ i,j,v[i][j] }); // cctv�� ��ġ�� ���� ����
        }
    for (int i = 0; i < cctv.size(); i++)
    {
        auto temp = cctv[i];
        int dir = countcctv(temp);
        drawcctv(i + 1, dir, cctv[i]);
    }

    cout << blindSpot();
}