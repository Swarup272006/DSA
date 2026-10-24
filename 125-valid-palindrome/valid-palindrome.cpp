class Solution {
public:
    bool isPalindrome(string s) {
        string word ;
        
        for (int i = 0 ; i < s.length() ; i++){
            if (s[i] >= 'A' && s[i] <= 'Z'){
                word.push_back (s[i] + 32) ;
            }
            if (s[i] >= 'a' && s[i] <= 'z'){
                word.push_back(s[i] ) ;
            }

            if (s[i] >= '0' && s[i] <= '9'){
                word.push_back(s[i]) ;
            }
        }

        int st = 0 ;
        int end = word.length() - 1 ;

        while (st < end ){

            if (word[st] != word[end]){
                return false ;
            }

            st ++ ;
            end -- ;
        }

        return true ;
        
    }
};