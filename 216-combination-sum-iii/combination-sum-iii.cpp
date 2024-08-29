class Solution {
public:
    vector<vector<int>>ans; //For storing the answer

    void get(vector<int>temp, int digit, int n, int sum, int NumSum){
        if( sum == n ){  // When Sum == Target number
            if(temp.size() == digit)ans.push_back(temp); //Digit Check
            return;
        }

        if(NumSum > 9 || sum > n)return; //Base Case
        
        //Include 
        sum += NumSum;
        temp.push_back(NumSum); 
        get(temp, digit, n, sum,  NumSum+1); //Recursive call
        sum -= NumSum;
        temp.pop_back();
        
        //Exclude 
        get(temp, digit, n, sum,  NumSum+1); //backTracking
    } 
    vector<vector<int>> combinationSum3(int k, int n) {
        if(k>n)return {}; //Simple Check 
        int sum=0 , NumSum=1;
        vector<int>temp;
        get(temp, k, n, sum, NumSum);
        return ans;
    }
};