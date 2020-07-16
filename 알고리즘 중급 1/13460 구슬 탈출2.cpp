#include <iostream>
#include <vector>
#include <string>
using namespace std;
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };
const int LIMIT = 10;

//  10개의 이동칸에 4가지의 방법을 채워넣는다.
vector<int> gen(int k) {
	vector<int> a(LIMIT); // 10개의 방법이 있다.

	// 각 방법마다 4가지의 이동경로가 있다.
	for (int i = 0; i < LIMIT; i++) {
		a[i] = (k & 3); // 4가지의 이동경로 중 하나를 한 방법에 채워놓기 (끝 2자리를 11과 &연산을 통해 4진법으로 전환한다.)
		k >>= 2; // 다음 끝 2자리를 전환하기 위해 2칸 비트이동한다.
	}
	return a;
}

// 구슬을 움직이는 시뮬레이션
pair<bool, bool> simulate(vector<string>& a, int k, int& x, int& y) 
{
	// 구슬이 구멍에 빠진 경우를 나타내는 . 이라면 false를 반환한다. 다음 구슬이 또 빠질 수 도 있기 때문
	if (a[x][y] == '.') return make_pair(false, false);

	// 구슬에 움직임 파악
	bool moved = false;

	while (true) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		// 구슬 혹은 벽을 만난 상태는 움직임과 false를 반환한다.
		if (a[nx][ny] == '#') {
			return make_pair(moved, false);
		}
		else if (a[nx][ny] == 'R' || a[nx][ny] == 'B') {
			return make_pair(moved, false);
		}

		else if (a[nx][ny] == '.') {
			// 구슬의 위치인 R ,B를 변경한다.
			swap(a[nx][ny], a[x][y]);
			x = nx;
			y = ny;
			// 움직인 경우라면 움직임을 true로 반환한다. 다른 구슬움직임에 따라 다시 움직일 수도 있기 때문에
			moved = true;
		}
		// 구멍에 빠진경우 true와 true를 반환. 
		else if (a[nx][ny] == 'O') {
			a[x][y] = '.';
			moved = true;
			return make_pair(moved, true);
		}
	}
	
}
int check(vector<string> a, vector<int>& dir) {
	int n = a.size();
	int m = a[0].size();
	int hx, hy, rx, ry, bx, by;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'O') {
				hx = i; hy = j;
			}
			else if (a[i][j] == 'R') {
				rx = i; ry = j;
			}
			else if (a[i][j] == 'B') {
				bx = i; by = j;
			}
		}
	}
	int cnt = 0;
	for (int k : dir) {
		cnt += 1;
		bool hole1 = false, hole2 = false;
		while (true) {
			auto p1 = simulate(a, k, rx, ry);
			auto p2 = simulate(a, k, bx, by);
			// 구슬이 두개다 움직일 수 없는 상태가 되면 반복문을 빠져나간다. 
			if (p1.first == false && p2.first == false) {
				// 구슬이 두개가 따로 움직이게 구현하였으므로 한개가 움직이고 다른 구슬이 다시 움직일 수 있다.
				break;
			}

			// 구멍에 빠졌는지를 체크
			if (p1.second) hole1 = true;
			if (p2.second) hole2 = true;
		}
		if (hole2) return -1;
		if (hole1) return cnt;
	}
	return -1;
}

// 유효한 움직임을 계산한다.
bool valid(vector<int>& dir) {
	int l = dir.size();

	// 10개의 움직임 가운데 똑같은 방향으로 두번가거나 왔던방향으로 바로 다음에 가는경우는 유효한 방법이 아니다.
	for (int i = 0; i + 1 < l; i++) {
		if (dir[i] == 0 && dir[i + 1] == 1) return false;
		if (dir[i] == 1 && dir[i + 1] == 0) return false;
		if (dir[i] == 2 && dir[i + 1] == 3) return false;
		if (dir[i] == 3 && dir[i + 1] == 2) return false;
		if (dir[i] == dir[i + 1]) return false;
	}
	return true;
}
int main() {
	int n, m;
	cin >> n >> m;
	vector<string> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int ans = -1;
	for (int k = 0; k < (1 << (LIMIT * 2)); k++) {
		vector<int> dir = gen(k);
		if (!valid(dir)) continue;
		int cur = check(a, dir);
		if (cur == -1) continue;
		if (ans == -1 || ans > cur) ans = cur;
	}
	cout << ans << '\n';
	return 0;
}