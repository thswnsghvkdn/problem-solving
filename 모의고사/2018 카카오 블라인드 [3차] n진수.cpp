#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

string convertion(int num, int notation) {
	string res = "";
	int mok = num;
	int nmg = 0;

	while (mok >= notation) {
		nmg = mok % notation;
		mok /= notation;

		// 10진법보다 크고 나머지가 10 이상인 경우
		if (notation > 10 && nmg >= 10) {
			res = (char)(nmg + 55) + res;
		}
		else {
			res = to_string(nmg) + res;
		}
	}

	if (notation > 10 && mok >= 10) {
		res = (char)(mok + 55) + res;
	}
	else {
		res = to_string(mok) + res;
	}

	return res;
}

string solution(int n, int t, int m, int p) {
	string answer = "";
	int index = 1; // 주인공 순서
	int num = 0;
	string s_num; // 진법변환
	while (1)
	{
		s_num = convertion(num++, n);
		for (int i = 0; i < s_num.size(); i++)
		{
			if (index == p) {
				answer += s_num[i];
				t--;
				if (t == 0)
					return answer;
			}
			if (index == m) index = 1;
			else index++;
		}
	}
	return answer;
}