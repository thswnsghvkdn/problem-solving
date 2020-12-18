#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

string str;
int n; // ���� ����
long long sum_max; // ����� �ִ�
struct Oper{
	char ch; // ������
	int pri; // �켱����
}; // ������ ����ü
stack<Oper> s1; // ������ ����
stack<long long> s2; // �ǿ����� ����

long long cal(long long a, long long b, char ch)
{
	switch (ch)
	{
	case '*' :
		return a * b;
	case '+' :
		return a + b;
	case '-' :
		return a - b;
	}
}

void input(Oper op) // ���� �����ڸ� ����ϴ� �Լ�
{
	if (s1.empty() || op.pri > s1.top().pri)
	{
		s1.push(op);
		return;
	}
	else if (op.pri <= s1.top().pri) // ���� ���� �����ڰ� �켱������ �� ���ų� ���� ��� ���
	{
		while (!s1.empty()) {
			long long b = s2.top();
			s2.pop();
			long long a = s2.top();
			s2.pop();
			char ch = s1.top().ch;
			s1.pop();
			s2.push(cal(a, b, ch)); // s2�� ����� �����Ѵ�. 
		}
		s1.push(op);
		return;
	}
	

}
int get_pri(char ch) // �������� �켱����
{
	switch (ch)
	{
	case '+' : case '-' :
		return 0;
	case '*' :
		return 1;
	}
}
void dfs(int index) // �ΰ��� ���ÿ� dfs ������� ��������� �ٸ��� �Ͽ� ����
{
	if (index + 1 == n)
	{
		s2.push(str[index] - '0');
		while (!s1.empty()) {
			long long b = s2.top();
			s2.pop();
			long long a = s2.top();
			s2.pop();
			char ch = s1.top().ch;
			s1.pop();
			s2.push(cal(a, b, ch)); // s2�� ����� �����Ѵ�. 
		}
		long long res = s2.top();
		s2.pop();
		sum_max = max(sum_max, res);
		return;
	}
	s2.push(str[index] - '0');
	input({ str[index + 1] , get_pri(str[index + 1]) });
	dfs(index + 2);
	s2.push(str[index] - '0');
	input({ str[index + 1], 2 });
	dfs(index + 2);


}

int main()
{
	cin >> n;
	cin >> str;
	dfs(0);
	cout << sum_max;

}
