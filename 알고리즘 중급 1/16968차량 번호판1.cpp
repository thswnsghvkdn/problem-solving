#include <iostream>
using namespace std;
int main()
{
	string s;
	cin >> s;
	long long ans;
	s[0] == 'd' ? ans = 10 : ans = 26;
	for (int i = 1; i < s.length(); i++)
	{
		s[i] == 'd' ?  s[i - 1] == 'd' ? ans *= 9 : ans *= 10  :  s[i - 1] == 'd' ? ans *= 26 : ans *= 25; 
//		if (s[i] == 'd') 
//			s[i - 1] == 'd' ? ans *= 9 : ans *= 10;
//		else 
//			s[i - 1] == 'd' ? ans *= 26 : ans *= 25;
	}
	cout << ans;
}