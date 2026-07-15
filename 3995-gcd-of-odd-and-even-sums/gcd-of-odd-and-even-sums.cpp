class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        int GCD = 1 ;
        int sumOdd = n * n ;
        int sumEven = n * (n + 1);

        // now main task is to find gcd (sumOdd , sumEven )
        GCD = n ;



        return GCD ;
        
    }
};