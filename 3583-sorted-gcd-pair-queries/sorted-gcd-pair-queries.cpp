class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {

        int mx = *max_element(nums.begin(), nums.end());

        // freq[x] = occurrences of x
        vector<int> freq(mx + 1, 0);
        for (int x : nums)
            freq[x]++;

        // exact[g] = number of pairs having gcd exactly g
        vector<long long> exact(mx + 1, 0);

        // Process from largest gcd to smallest
        for (int g = mx; g >= 1; g--) {

            long long cnt = 0;

            // Count numbers divisible by g
            for (int multiple = g; multiple <= mx; multiple += g)
                cnt += freq[multiple];

            // Total pairs divisible by g
            long long pairs = cnt * (cnt - 1) / 2;

            // Remove pairs already counted for larger gcds
            for (int multiple = 2 * g; multiple <= mx; multiple += g)
                pairs -= exact[multiple];

            exact[g] = pairs;
        }

        // Prefix counts
        vector<long long> prefix(mx + 1, 0);
        for (int g = 1; g <= mx; g++)
            prefix[g] = prefix[g - 1] + exact[g];

        vector<int> ans;

        for (long long q : queries) {

            int l = 1;
            int r = mx;

            while (l < r) {
                int mid = l + (r - l) / 2;

                if (prefix[mid] > q)
                    r = mid;
                else
                    l = mid + 1;
            }

            ans.push_back(l);
        }

        return ans;
    }
};