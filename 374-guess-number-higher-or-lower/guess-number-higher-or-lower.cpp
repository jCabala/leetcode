/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        ios::sync_with_stdio(0); cin.tie(0);
        return guessNumber(1, n);
    }

private:
    int guessNumber(int lo, int hi) {
        int myGuess = lo + (hi - lo) / 2;

        int gs = guess(myGuess);
        if (gs == 0) return myGuess;
        else if (gs == 1) return guessNumber(myGuess + 1, hi);
        else return guessNumber(lo, myGuess - 1);
    }
};