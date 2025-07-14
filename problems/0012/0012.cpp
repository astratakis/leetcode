#include <iostream>
#include <bits/stdc++.h>

using namespace std;

string intToRoman(int num)
{
    string ans = "";

    string low = "I";
    string high = "X";
    string mid = "V";

    for (int i = 0; i < 4; ++i)
    {
        int digit = num % 10;
        num /= 10;

        if (i == 0)
        {
            low = "I";
            high = "X";
            mid = "V";
        }
        else if (i == 1)
        {
            low = "X";
            mid = "L";
            high = "C";
        }
        else if (i == 2)
        {
            low = "C";
            mid = "D";
            high = "M";
        }
        else if (i == 3)
        {
            low = "M";
        }

        if (digit <= 3 && digit >= 1)
        {
            for (int k = 0; k < digit; ++k)
            {
                ans = low + ans;
            }
        }
        else if (digit == 4)
        {
            ans = low + mid + ans;
        }
        else if (digit == 5)
        {
            ans = mid + ans;
        }
        else if (digit >= 6 && digit <= 8)
        {
            string prefix = mid;

            for (int k = 0; k < digit - 5; ++k)
            {
                prefix += low;
            }

            ans = prefix + ans;
        }
        else if (digit == 9)
        {
            ans = low + high + ans;
        }
    }
    return ans;
}

int main(void)
{
    int num;
    cin >> num;

    string ans = intToRoman(num);
    cout << ans << endl;
    return 0;
}
