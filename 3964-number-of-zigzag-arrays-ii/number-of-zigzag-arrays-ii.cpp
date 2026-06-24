class Solution {
public:
    static const int MOD = 1000000007;

    using Matrix = vector<vector<long long>>;

    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));

        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (A[i][k] == 0) continue;

                for (int j = 0; j < n; j++) {
                    if (B[k][j] == 0) continue;

                    C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
                }
            }
        }

        return C;
    }

    vector<long long> multiplyMatVec(const Matrix& A,
                                     const vector<long long>& v) {
        int n = A.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                res[i] = (res[i] + A[i][j] * v[j]) % MOD;
            }
        }

        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1) return m;

        int S = 2 * m;

        Matrix M(S, vector<long long>(S, 0));

        // up[i] = sum of down[j] where j < i
        // down[i] = sum of up[j] where j > i

        for (int i = 0; i < m; i++) {

            for (int j = 0; j < i; j++) {
                M[i][m + j] = 1;
            }

            for (int j = i + 1; j < m; j++) {
                M[m + i][j] = 1;
            }
        }

        // Length = 2 states
        vector<long long> vec(S, 0);

        for (int i = 0; i < m; i++) {
            vec[i] = i;             // up
            vec[m + i] = m - 1 - i; // down
        }

        long long power = n - 2;

        while (power > 0) {
            if (power & 1) {
                vec = multiplyMatVec(M, vec);
            }

            M = multiply(M, M);
            power >>= 1;
        }

        long long ans = 0;

        for (long long x : vec) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};