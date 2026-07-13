class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector <int> solution ;
        // low and high 
        // we will push back the number which will be valid solution in the vector solution 
        // but will we check if the number is sorted or not ?? 
        // for (int i = low ; i <= high ; i ++ ){//loop will travel within all the numbers 
            

        // }

        // friends suggestion 
        vector<int> answer = {12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,1234,2345,3456,4567,5678,6789,12345,23456,34567,45678,56789,123456,234567,345678,456789,1234567,2345678,3456789,12345678,23456789,123456789} ;

        for (int i = 0 ; i < answer.size(); i++){
            if (answer[i] >= low ){
                if (answer[i] <= high ){
                    solution.push_back(answer[i]) ;
                }
            }
        }

        return solution ;
                
    }
};