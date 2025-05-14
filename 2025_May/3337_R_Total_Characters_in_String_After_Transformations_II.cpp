// 2025 May 14
// ...

class Solution {
public:

    using Matrix = vector<vector<int>>;
    const int N = 26;
    const int MOD = 1e9 + 7;

    Matrix mul(Matrix& A, Matrix& B)
    {
        Matrix C(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                for (int k = 0; k < N; k++)
                {
                    C[i][j] = (C[i][j] + 1LL * A[i][k] * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix pow(Matrix A, int p)
    {
        Matrix res(N, vector<int>(N, 0));
        for (int i = 0; i < N; i++)
        {
            res[i][i] = 1;
        }
        while (p > 0)
        {
            if (p & 1) res = mul(res, A);
            A = mul(A, A);
            p = p / 2;
        }
        return res;
    }

    int lengthAfterTransformations(string s, int t, vector<int>& nums) 
    {
        int n = s.length();
        Matrix M(N, vector<int>(N, 0));

        for (int i = 0; i < 26; i++)
        {
            for (int j = 1; j <= nums[i]; j++)
            {
                M[(i + j) % 26][i] = (M[(i + j) % 26][i] + 1) % MOD;
            }
        }

        Matrix T = pow(M, t);
        vector<int> freq(N, 0);

        for (char i : s)
        {
            freq[i - 'a']++;
        }

        vector<int> res(N, 0);
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                res[i] = (res[i] + 1LL * T[i][j] * freq[j]) % MOD;
            }
        }

        int cnt = 0;
        for (int i : res)
        {
            cnt = (cnt + i) % MOD;
        }
        return cnt;
    }
};
/*
solution reference
https://leetcode.com/problems/total-characters-in-string-after-transformations-ii/solutions/6740422/easy-matrix-exponentiation-o-nlogt
*/
