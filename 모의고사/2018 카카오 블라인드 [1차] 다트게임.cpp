#include <string>
#include <iostream>

#define T(a) ((a) * (a) *(a))
#define D(a) ((a) * (a))

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int tot[3];
	for (int i = 0, j = 0; i < dartResult.size(); i++)
	{
		if (dartResult[i] >= '0' && dartResult[i] <= '9')
		{
			if (dartResult[i] == '1' && dartResult[i + 1] == '0') {
				tot[j++] = 10;
				i++;
			}
			else
				tot[j++] = dartResult[i] - '0';
		}
		else {
			switch (dartResult[i])
			{
			case 'D' :
				tot[j - 1] = D(tot[j - 1]);
				break;

			case 'T':
				tot[j - 1] = T(tot[j - 1]);
				break;

			case '*':
				if(j == 1)
				tot[j - 1] *= 2;
				else
				{
					tot[j - 2] *= 2;
					tot[j - 1] *= 2;
				}
				break;
			case '#' :
				tot[j - 1] *= -1;
				break;
			}
		}
	}
	for (int i = 0; i < 3; i++)
		answer += tot[i];
	return answer;
}
int main()
{
	cout << solution("1S*2T*3S") << endl;
	cout << solution("1D#2S*3S") << endl;
	cout << solution("1T2D3D#") << endl;
	cout << solution("1D2S3T*") << endl;
}