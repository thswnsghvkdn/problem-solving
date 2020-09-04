#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// �μ��� ���� ������ ���Ͽ� ����
int strtok(string s, int n)
{
	int size = 0;
	int ans = 1010;
	// ù��° �ݺ��������� ���ۺκ��� ���Ѵ�.
	for (int t = 0; t < s.size(); t += n) {
		size = t; // �������� ���ڿ��� ���Ͽ� ����� �ʱ�ȭ �Ѵ�.
		for (int i = t; i < s.size(); )
		{
			string temp; // ������ �Ǵ� ���ڿ�
			if (i + n > s.size())
				temp = s.substr(i); // ���ڿ��� ���� ����� �ȵɰ�� ������ ���ڿ��� ���Ѵ�.
			else temp = s.substr(i, n);

			int s_word = 1; // ���� ���ڿ��� ����
			int j = i + n;
			for (; j < s.size(); j += n) // ���ιݺ��������� �ش� ���ڿ��� ���� ���ڿ��� �˻��Ѵ�.
			{
				if (j + n > s.size()) break;
				string next = s.substr(j, n);
				if (temp == next)
					s_word++;
				else
					break; // �ٸ� ���ڿ��� ���ð�� �ݺ����� �����Ͽ� �ش� ���ڿ��� ���� ���ڿ��� �ǵ��� �غ��Ѵ�.
			}
			i = j;
			if (s_word > 1) // ���� ���ڿ��� ������ ���� ���ڿ��� �ۼ��Ѵ�.
			{
				size += 1;
				if (s_word >= 10)
					size += 1;
				if (s_word >= 100)
					size += 1;
				if (s_word >= 1000)
					size += 1;
			}
			size += temp.size(); // �ش� ���ڿ��� ���̸� ����� ���Ѵ�.
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
	for (int n = 1; n <= size; n++) // ���ڿ��� ���� ������ �ٲپ� ���鼭 ������ �����Ѵ�.
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