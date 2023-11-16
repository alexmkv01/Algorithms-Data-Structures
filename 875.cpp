#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int left = 1;
        int right = *max_element(piles.begin(), piles.end());
        int mid;
        int result=right;

        while (left <= right){
            mid = left + (right-left)/2;

            if (canEatInTime(piles, h, mid)){
                right = mid-1;
                if (mid < result){
                    // update new minimum hours
                    result = mid;
                }
            } else {
                left = mid+1;
            }
        }
        return result;
    }

private:
    bool canEatInTime(vector<int>& piles, int h, int k){
        long total=0;
        for (int pile : piles){
            total += ceil(double(pile) / k);
        }
        return (total <= h);
    }
};