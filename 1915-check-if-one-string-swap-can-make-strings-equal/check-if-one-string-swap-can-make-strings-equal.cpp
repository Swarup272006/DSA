class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if (s1.length() != s2.length() ){
            return false ;
        }

        vector <int> freq (26, 0) ;
        for (int i = 0 ; i < s1.length () ; i++){
            freq [s1[i] - 'a'] ++ ;
            freq [s2[i] - 'a'] -- ;
        }

        for (int i = 0 ; i < 26 ; i++){
            if (freq[i] != 0){
                return false ;
            }
        }

        int unequal = 0 ;
        for (int i = 0 ; i < s1.length() ; i++){
            if (s1[i] != s2[i]){
                unequal ++ ;
            }
        }

        

        if (unequal == 0 || unequal == 2){
            return true ;
        }

        else {
            return false ;
        }

        
    }
};