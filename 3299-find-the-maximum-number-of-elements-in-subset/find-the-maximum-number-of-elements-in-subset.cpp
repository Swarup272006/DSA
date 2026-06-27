class Solution {
public:
    int maximumLength(vector<int>& nums) {

        unordered_map<long long, int> freq;

        for (int x : nums)
            freq[x]++;

        int ans = 1;

        // Handle 1 separately
        if (freq.count(1)) {
            ans = max(ans, (freq[1] % 2) ? freq[1] : freq[1] - 1);
        }

        for (auto &p : freq) {

            long long cur = p.first;

            if (cur == 1)
                continue;

            int len = 0;

            while (true) {
                auto it = freq.find(cur);

                if (it == freq.end() || it->second < 2)
                    break;

                len += 2;

                // Prevent overflow / values beyond constraint
                if (cur > 1000000000LL / cur) {
                    cur = -1;
                    break;
                }

                cur *= cur;
            }

            if (cur != -1) {
                auto it = freq.find(cur);

                if (it != freq.end() && it->second >= 1)
                    len++;
                else
                    len--;
            } else {
                len--;
            }

            ans = max(ans, len);
        }

        return ans;
    }
};