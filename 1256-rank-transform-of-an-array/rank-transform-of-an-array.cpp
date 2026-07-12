class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {

        vector<int> temp = arr;
        sort(temp.begin(), temp.end());

        unordered_map<int, int> rank;
        int currRank = 1;

        for (int num : temp) {
            if (!rank.count(num)) {
                rank[num] = currRank++;
            }
        }

        vector<int> ans;

        for (int num : arr) {
            ans.push_back(rank[num]);
        }

        return ans;
    }
};