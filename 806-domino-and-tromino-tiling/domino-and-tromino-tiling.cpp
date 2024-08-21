class Solution {
public:
    int arr[1001],N=1e9+7;
    int numTilings(int n) {
         arr[1]=1; arr[2]=2; arr[3]=5;
         for(int i=4;i<=n;i++){ 
             arr[i]=((arr[i-1]*2)%N+arr[i-3])%N; //for i>=4
         }
        return arr[n];
    }
};