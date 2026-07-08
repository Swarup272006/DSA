class Solution {
public:
    static const int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.size();

        vector<int> pos;
        vector<long long> prefHash(1, 0), prefSum(1, 0);

        vector<int> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (1LL * pow10[i - 1] * 10) % MOD;

        for (int i = 0; i < n; i++) {
            if (s[i] != '0') {
                int d = s[i] - '0';
                pos.push_back(i);
                prefHash.push_back((prefHash.back() * 10 + d) % MOD);
                prefSum.push_back(prefSum.back() + d);
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0], r = q[1];

            auto it1 = lower_bound(pos.begin(), pos.end(), l);
            auto it2 = upper_bound(pos.begin(), pos.end(), r);

            int L = it1 - pos.begin() + 1;
            int R = it2 - pos.begin();

            if (L > R) {
                ans.push_back(0);
                continue;
            }

            int len = R - L + 1;

            long long x =
                (prefHash[R] -
                 prefHash[L - 1] * 1LL * pow10[len] % MOD +
                 MOD) % MOD;

            long long sum = prefSum[R] - prefSum[L - 1];

            ans.push_back(x * sum % MOD);
        }

        return ans;
    }
};