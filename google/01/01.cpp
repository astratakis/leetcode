#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void print_mat(vector<vector<int>> &mat)
{
    cout << endl;

    int n = mat.size();
    int m = mat[0].size();

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

int min_int(int a, int b)
{
    return a < b ? a : b;
}

int solve(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        dp[i][0] = mat[i][0];
    }
    for (int j = 0; j < m; ++j)
    {
        dp[0][j] = mat[0][j];
    }

    for (int i = 1; i < n; ++i)
    {
        for (int j = 1; j < m; ++j)
        {
            if (mat[i][j] == 0)
            {
                dp[i][j] = 0;
            }
            else
            {
                dp[i][j] = 1 + min_int(min_int(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
            }
        }
    }

    int max_land = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            if (dp[i][j] > max_land)
            {
                max_land = dp[i][j];
            }
        }
    }

    print_mat(dp);

    return max_land;
}

int main(void)
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> mat(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> mat[i][j];
        }
    }

    int ans = solve(mat);

    cout << ans << endl;

    return 0;
}