#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define int_max(a, b) ((a > b ? a : b))

int longestIncreasingPath(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m));

    vector<pair<int, pair<int, int>>> s(n * m);

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            s[i * m + j].first = matrix[i][j];
            s[i * m + j].second.first = i;
            s[i * m + j].second.second = j;
        }
    }

    std::stable_sort(
        s.begin(), s.end(),
        [](const auto &a, const auto &b)
        {
            return a.first > b.first;
        });

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            int r = s[i * m + j].second.first;
            int c = s[i * m + j].second.second;

            if (r > 0)
            {
                if (matrix[r - 1][c] < matrix[r][c])
                {
                    dp[r - 1][c] = int_max(dp[r][c] + 1, dp[r - 1][c]);
                }
            }
            if (r < n - 1)
            {
                if (matrix[r + 1][c] < matrix[r][c])
                {
                    dp[r + 1][c] = int_max(dp[r][c] + 1, dp[r + 1][c]);
                }
            }
            if (c > 0)
            {
                if (matrix[r][c - 1] < matrix[r][c])
                {
                    dp[r][c - 1] = int_max(dp[r][c] + 1, dp[r][c - 1]);
                }
            }
            if (c < m - 1)
            {
                if (matrix[r][c + 1] < matrix[r][c])
                {
                    dp[r][c + 1] = int_max(dp[r][c] + 1, dp[r][c + 1]);
                }
            }
        }
    }

    int max_value = 0;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            max_value = int_max(max_value, dp[i][j]);
        }
    }

    return max_value + 1;
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

    int ans = longestIncreasingPath(mat);

    cout << ans << endl;

    return 0;
}
