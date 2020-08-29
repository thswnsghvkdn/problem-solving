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

		// 10�������� ũ�� �������� 10 �̻��� ���
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
	int index = 1; // ���ΰ� ����
	int num = 0;
	string s_num; // ������ȯ
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