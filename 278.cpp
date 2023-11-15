// The API isBadVersion is defined for you.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 0, right = n;
        int mid;
        bool found = false;

        if (n==1){
            return n;
        }

        while (!found){
            mid = left + (right-left)/2;
            // found case #1
            if ((isBadVersion(mid) == 0) && (isBadVersion(mid+1) == 1)){
                return mid+1;
            } 
            // found case #2
            else if ((isBadVersion(mid) == 1) && (isBadVersion(mid-1) == 0)){
                return mid;
            }
            // refine search space
            else if ((isBadVersion(mid) == 0) && (isBadVersion(mid+1) == 0)){
                left = mid+1;
            } else if ((isBadVersion(mid) == 1) && (isBadVersion(mid-1) == 1)){
                right = mid-1;
            }
        }
        return mid;
    }
};