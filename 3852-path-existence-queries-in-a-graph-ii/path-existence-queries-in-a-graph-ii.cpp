class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff,
                                     vector<vector<int>>& queries) {

        vector<pair<int,int>> arr;
        arr.reserve(n);

        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> value(n), rank(n);

        for (int i = 0; i < n; i++) {
            value[i] = arr[i].first;
            rank[arr[i].second] = i;
        }

        // Components
        vector<int> comp(n);
        comp[0] = 0;
        for (int i = 1; i < n; i++) {
            comp[i] = comp[i - 1];
            if (value[i] - value[i - 1] > maxDiff)
                comp[i]++;
        }

        // farthest reachable in one jump
        vector<int> nxt(n);
        int r = 0;

        for (int i = 0; i < n; i++) {
            if (r < i) r = i;
            while (r + 1 < n && value[r + 1] - value[i] <= maxDiff)
                r++;
            nxt[i] = r;
        }

        int LOG = 18;   // 2^17 > 1e5
        vector<vector<int>> up(LOG, vector<int>(n));

        up[0] = nxt;

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++)
                up[k][i] = up[k - 1][ up[k - 1][i] ];
        }

        vector<int> ans;

        for (auto &q : queries) {

            int a = rank[q[0]];
            int b = rank[q[1]];

            if (a == b) {
                ans.push_back(0);
                continue;
            }

            if (a > b) swap(a, b);

            if (comp[a] != comp[b]) {
                ans.push_back(-1);
                continue;
            }

            int cur = a;
            int jumps = 0;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < b) {
                    cur = up[k][cur];
                    jumps += (1 << k);
                }
            }

            ans.push_back(jumps + 1);
        }

        return ans;
    }
};