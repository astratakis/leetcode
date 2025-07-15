#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string convert(string s, int numRows)
{
    if (numRows == 1)
    {
        return s;
    }
    vector<string> list(numRows, "");

    int r = 0;
    bool increasing = true;

    for (int i = 0; i < s.length(); ++i)
    {
        list[r] += s[i];

        r += (increasing ? 1 : -1);

        if (!increasing && r == 0)
        {
            increasing = true;
        }
        if (increasing && r == numRows - 1)
        {
            increasing = false;
        }
    }

    string ans = "";
    for (int i = 0; i < list.size(); ++i)
    {
        ans += list[i];
    }

    return ans;
}

int main(void)
{
    string s;
    int n;
    cin >> s >> n;

    string ans = convert(s, n);
    cout << ans << endl;
    return 0;
}