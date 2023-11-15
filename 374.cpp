/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        int pick;
        int outcome;

        while (left <= right){
            // pick = (left + right) / 2;
            pick = left + ((right - left) / 2); // prevent int overflow

            outcome = guess(pick);
            
            if (outcome == -1){
                right = pick-1;
            } else if (outcome == 1){
                left = pick+1;
            } else {
                return pick;
            }
        }
        return -1;
    }
};