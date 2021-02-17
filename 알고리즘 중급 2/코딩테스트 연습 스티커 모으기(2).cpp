#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[100001];
int dp2[100001];
int solution(vector<int> sticker)
{
    int answer = 0;

    dp[1] = dp[0] = sticker[0];
    dp2[0] = 0;
    dp2[1] = sticker[1];
  
    for (int i = 2; i < sticker.size() - 1; i++)
    {
        dp[i] = max(dp[i - 1], dp[i - 2] + sticker[i]);
        dp2[i] = max(dp2[i - 1], dp2[i - 2] + sticker[i]);
    }
    dp2[sticker.size() - 1] = max(dp2[sticker.size() - 2], dp2[sticker.size() - 3] + sticker[sticker.size() - 1]);
    answer = max(dp[sticker.size() - 2], dp2[sticker.size() - 1] );
    return answer;
}

int main() {
    cout << solution({ 14, 6, 5, 11, 3, 9, 2, 10 });
}