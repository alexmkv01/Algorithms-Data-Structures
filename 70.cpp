class Solution {
public:
    int climbStairs(int n) {

        // space: O(1)
        // time : O(n)
        if (n==2){
            return 2;
        } 
        if (n==1){
            return 1;
        }

        int result = 0;
        int first = 1;
        int second = 2;

        for (int i=2; i<n; i++){
            result = first + second;
            first = second;
            second = result;
        }

        return result;
    }
};