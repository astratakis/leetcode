#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_mat(vector<vector<int>> &mat)
{
    cout << endl;

    for (int i = 0; i < mat.size(); ++i)
    {
        for (int j = 0; j < mat[i].size(); ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
}

int minimumTotal(vector<vector<int>> &triangle)
{
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));

    int n = triangle.size();

    dp[0][0] = triangle[0][0];

    for (int i = 1; i < n; ++i)
    {
        dp[i][0] = dp[i - 1][0] + triangle[i][0];
        dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
    }

    for (int i = 2; i < n; ++i)
    {
        for (int j = 1; j < i; j++)
        {
            dp[i][j] = triangle[i][j] + min(dp[i - 1][j - 1], dp[i - 1][j]);
        }
    }

    int ans = dp[n - 1][0];

    for (int i = 0; i < n; ++i)
    {
        if (dp[n - 1][i] < ans)
        {
            ans = dp[n - 1][i];
        }
    }

    return ans;
}

int main(void)
{
    int n;
    cin >> n;

    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j <= i; ++j)
        {
            cin >> a[i][j];
        }
    }

    int ans = minimumTotal(a);
    cout << ans << endl;

    return 0;
}