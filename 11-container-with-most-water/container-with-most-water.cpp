class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size() ;
        int left = 0;
        int right = n - 1;

        int max_area = 0 ;
        int curr_area = 0 ;

       while (right > left ){
        curr_area = min(height[left] , height[right]) * (right - left) ;
        max_area = max (max_area , curr_area) ;

        if (height[left] < height[right]){
            left ++ ;
        }
        else {
            right -- ;
        }
       }
       return max_area ;
    }
};