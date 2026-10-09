class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int pd_sum = 0 ;
        int sd_sum = 0 ;
        int common = 0 ;

        int n = mat.size() ;

        int i = 0 ;
        int j = n - 1 ; 

        while (i < n){
            pd_sum += mat[i][i] ;

            sd_sum += mat[i][j] ;

            if (i == j){
                common += mat[i][i] ;
            }

            i++ ;
            j = n - i - 1 ;
        }

        return pd_sum + sd_sum - common ;

        
    }
};