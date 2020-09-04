#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 인수로 들어온 정수에 대하여 압축
int strtok(string s, int n)
{
	int size = 0;
	int ans = 1010;
	// 첫번째 반복문에서는 시작부분을 정한다.
	for (int t = 0; t < s.size(); t += n) {
		size = t; // 시작전에 문자열을 더하여 사이즈를 초기화 한다.
		for (int i = t; i < s.size(); )
		{
			string temp; // 기준이 되는 문자열
			if (i + n > s.size())
				temp = s.substr(i); // 문자열을 만들 사이즈가 안될경우 나머지 문자열을 더한다.
			else temp = s.substr(i, n);

			int s_word = 1; // 같은 문자열의 개수
			int j = i + n;
			for (; j < s.size(); j += n) // 내부반복문에서는 해당 문자열과 같은 문자열을 검사한다.
			{
				if (j + n > s.size()) break;
				string next = s.substr(j, n);
				if (temp == next)
					s_word++;
				else
					break; // 다른 문자열이 나올경우 반복문을 종료하여 해당 문자열이 다음 문자열이 되도록 준비한다.
			}
			i = j;
			if (s_word > 1) // 같은 문자열의 개수를 압축 문자열로 작성한다.
			{
				size += 1;
				if (s_word >= 10)
					size += 1;
				if (s_word >= 100)
					size += 1;
				if (s_word >= 1000)
					size += 1;
			}
			size += temp.size(); // 해당 문자열의 길이를 사이즈에 더한다.
		}
		if (size < ans)
			ans = size;
	}
	return ans;
}

int solution(string s) {
	if (s.size() == 1)
		return 1;
	int tot;
	int answer = 1010;
	int size = s.size() / 2;
	for (int n = 1; n <= size; n++) // 문자열을 만들 변수를 바꾸어 가면서 정답을 갱신한다.
	{
		tot = strtok(s, n);
		answer = min(tot, answer);
	}
	return answer;
}
int main()
{
	solution("a");
}