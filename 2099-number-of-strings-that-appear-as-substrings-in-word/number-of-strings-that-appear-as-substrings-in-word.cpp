class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count = 0 ;
        int n = patterns.size() ;
        // basically count will update if pattern[i] is a subset of word 
        // but for me the issue is how can i compare it wethere it is subset or not ?
        for (int i = 0 ; i < n ; i ++){
                if (word.find(patterns[i]) != string::npos) {
                    count++;
                }
        }



        return count ; 
    }
};