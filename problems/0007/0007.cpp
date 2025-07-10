#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

int reverse(int x)
{
    int sign = (x < 0 ? 1 : 0);

    int limit[] = {2, 1, 4, 7, 4, 8, 3, 6, 4, 7};
    bool ok = true;

    if (sign)
    {
        limit[9]++;
    }

    vector<int> digits;

    while (x != 0)
    {
        digits.push_back((x % 10) * (sign ? -1 : 1));
        x /= 10;
    }

    if (digits.size() == 10)
    {
        for (int i = 0; i < digits.size(); ++i)
        {
            if (digits[i] < limit[i])
            {
                ok = true;
                break;
            }
            else if (digits[i] > limit[i])
            {
                ok = false;
                break;
            }
        }
    }

    if (!ok)
    {
        return 0;
    }

    int ans = 0;

    for (int i = 0; i < digits.size(); ++i)
    {
        ans *= 10;
        ans += digits[i];
    }

    if (sign)
    {
        ans *= (-1);
    }

    return ans;
}

int main(void)
{
    int n;
    cin >> n;

    int ans = reverse(n);

    cout << ans << endl;
    return 0;
}