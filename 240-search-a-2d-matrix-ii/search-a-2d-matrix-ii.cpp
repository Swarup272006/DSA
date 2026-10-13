class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size() ;
        int m = matrix[0].size() ;

        int st = matrix [0][m-1] ;

        int row = 0 ;
        int col = m-1 ;

        while (row < n && col >= 0){
            st = matrix [row][col] ;
            if (st == target){
                return true ;
            }
            else if (st > target){
                col -- ;
            }
            else{
                row ++ ;
            }
        }
        return false ;
        
    }
};