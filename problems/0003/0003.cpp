#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int lengthOfLongestSubstring(string s)
{
    int n = s.length();

    if (n == 0)
    {
        return 0;
    }

    vector<int> ch(128, -1);

    vector<int> dp(n);
    int prev;

    ch[s[0]] = 0;
    dp[0] = 1;

    for (int i = 1; i < n; ++i)
    {
        prev = ch[s[i]];
        dp[i] = min(i - prev, dp[i - 1] + 1);
        ch[s[i]] = i;
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        count = (dp[i] > count ? dp[i] : count);
    }
    return count;
}

int main(void)
{
    string s;
    cin >> s;

    int ans = lengthOfLongestSubstring(s);
    cout << ans << endl;
    return 0;
}
