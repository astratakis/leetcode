#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

void print_vec(vector<int> &vec)
{
    for (int i = 0; i < vec.size(); ++i)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int candy(vector<int> &ratings)
{
    int n = ratings.size();
    vector<int> candies(n);
    vector<int> carry(n);

    for (int i = 0; i < n; ++i)
    {
        candies[i] = 1;
        carry[i] = 0;
    }

    for (int i = 0; i < n - 1; ++i)
    {
        if (ratings[i + 1] > ratings[i])
        {
            candies[i + 1] = candies[i] + 1;
        }
        else if (ratings[i + 1] < ratings[i])
        {
            carry[i + 1] = 1;
        }
    }

    for (int i = n - 1; i > 0; --i)
    {
        if (carry[i])
        {
            if (candies[i - 1] < candies[i] + 1)
            {
                candies[i - 1] = candies[i] + 1;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < n; ++i)
    {
        count += candies[i];
    }

    return count;
}

int main(void)
{
    int n;
    cin >> n;

    vector<int> ratings(n);

    for (int i = 0; i < n; ++i)
    {
        cin >> ratings[i];
    }

    int ans = candy(ratings);
    cout << ans << endl;

    return 0;
}