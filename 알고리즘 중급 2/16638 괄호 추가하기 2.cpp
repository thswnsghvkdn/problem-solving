#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

string str;
int n; // ���� ����
long long sum_max; // ����� �ִ�
struct Oper{
	char ch; // ������
	int pri; // �켱���� , �켱���� 3�� ���ڸ� ��Ÿ����.
}; // ������ ����ü
stack<long long> s2; // �ǿ����� ����
stack<long long> res; // ����ǥ���� ����� ������ ����

void cal(queue<char> &post, stack<Oper> &s1)
{
	while (!s1.empty())
	{
		post.push(s1.top().ch);
		s1.pop();
	}
	long long a, b, r; //����ÿ� ����� ����
	while (!post.empty()) // ����ǥ���� ���ÿ� �����Ͱ� �����ִ°�� �ݺ�
	{
		char ch = post.front();
		if (ch >= 0 && ch <= 9) // �ǿ������� ���
		{
			res.push(ch);
		}
		else
		{
			b = res.top();
			res.pop();
			a = res.top();
			res.pop();
			switch (ch)
			{
			case '*':
				r = a * b;
				break;
			case '+':
				r = a + b;
				break;
			case '-':
				r = a - b;
				break;
			}
			res.push(r);
		}
		post.pop();
	}
	sum_max  = max(sum_max, res.top());
	res.pop();
	return;
}

void input(Oper op, queue<char> &post, stack<Oper> &s1) // �������� �켱������ ���� ���ÿ� �����Ѵ�.
{
	if (s1.empty()) // ������ ������ ��������� push
	{
		s1.push(op);
		return;
	}
	while (!s1.empty() && s1.top().pri >= op.pri) // ������ �ֻ��� �����ڰ� �켱������ ���ų� ������� ����ǥ���� ���ÿ� �����Ѵ�.
	{
		post.push(s1.top().ch);
		s1.pop();
	}
	s1.push(op);
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


void dfs(queue<char> &post, stack<Oper> &s1, int index) // �ΰ��� ���ÿ� dfs ������� ��������� �ٸ��� �Ͽ� ����
{
	queue<char> post2 = post;
	stack<Oper> s2 = s1;
	if (index + 1 == n)
	{
		post.push(str[index] - '0');
		cal(post, s1);
		return;
	}
	post2.push(str[index] - '0');
	input({ str[index + 1] , get_pri(str[index + 1]) } , post2 , s2);
	dfs(post2 , s2 ,index + 2);
	post.push(str[index] - '0');
	input({ str[index + 1], 2 } , post, s1);
	dfs(post , s1, index + 2);

}

int main()
{
	queue<char> post;
	stack<Oper> s1;

	cin >> n;
	cin >> str;
	dfs(post, s1, 0);
	cout << sum_max;

}
