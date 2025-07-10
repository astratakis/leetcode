#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define INTEGER 1
#define DECIMAL 2
#define EXPONENT 3

bool isNumber(string s)
{
    bool sign_allowed = true;
    bool dot_allowed = true;
    bool exp_allowed = false;
    bool already_exp = false;
    bool already_dot = false;
    bool invalid_finish = true;
    int ascii = 0;
    bool ok = true;

    for (int i = 0; i < s.length(); ++i)
    {
        ascii = s[i];

        if (!sign_allowed && (ascii == '-' || ascii == '+'))
        {
            ok = false;
            break;
        }

        if (sign_allowed && (ascii == '-' || ascii == '+'))
        {
            sign_allowed = false;
            dot_allowed = true;
            invalid_finish = true;
            continue;
        }

        if (!dot_allowed && ascii == '.')
        {
            ok = false;
            break;
        }

        if (dot_allowed && ascii == '.')
        {
            dot_allowed = false;
            already_dot = true;
            sign_allowed = false;
            continue;
        }

        if (!exp_allowed && (ascii == 'E' || ascii == 'e'))
        {
            ok = false;
            break;
        }

        if (exp_allowed && (ascii == 'E' || ascii == 'e'))
        {
            exp_allowed = false;
            already_exp = true;
            invalid_finish = true;
            sign_allowed = true;
            already_dot = true;
            dot_allowed = false;
            continue;
        }

        if (ascii < 0x30 || ascii > 0x39)
        {
            ok = false;
            break;
        }
        else
        {
            invalid_finish = false;
            sign_allowed = false;
        }

        if (!already_dot && ascii <= 0x39 && ascii >= 0x30)
        {
            dot_allowed = true;
        }

        if (!already_exp && ascii <= 0x39 && ascii >= 0x30)
        {
            exp_allowed = true;
        }
    }
    return ok && (!invalid_finish);
}

int main(void)
{
    std::ios_base::sync_with_stdio(false);
    int t;
    cin >> t;

    for (int tt = 0; tt < t; ++tt)
    {
        string s;
        cin >> s;

        bool ans = isNumber(s);
        cout << ans << endl;
    }

    return 0;
}