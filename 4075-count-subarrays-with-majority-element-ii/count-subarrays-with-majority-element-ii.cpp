class Solution {
public:
    class Fenwick {
    public:
        vector<long long> bit;
        int n;

        Fenwick(int sz) {
            n = sz;
            bit.assign(n + 1, 0);
        }

        void update(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & (-idx);
            }
        }

        long long query(int idx) {
            long long sum = 0;
            while (idx > 0) {
                sum += bit[idx];
                idx -= idx & (-idx);
            }
            return sum;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {

        int n = nums.size();

        // Transform into +1 / -1
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            arr[i] = (nums[i] == target) ? 1 : -1;
        }

        // Prefix sums
        vector<int> prefix(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + arr[i - 1];
        }

        // Coordinate Compression
        vector<int> vals = prefix;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick ft(vals.size());

        long long ans = 0;

        for (int x : prefix) {

            int idx = lower_bound(vals.begin(), vals.end(), x) - vals.begin() + 1;

            // Count previous prefix sums strictly smaller
            ans += ft.query(idx - 1);

            // Insert current prefix sum
            ft.update(idx, 1);
        }

        return ans;
    }
};