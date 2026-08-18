class Solution {
  public:
  int dp[1001][1001];
  int solve(int W, vector<int> &val, vector<int> &wt, int n){
      if(W==0 || n==0 ) return 0;
      
      if(dp[n][W] != -1) return dp[n][W];
      if(wt[n-1]<=W){
          return  dp[n][W] = max(val[n-1] + solve(W-wt[n-1],val,wt,n-1), solve(W,val,wt,n-1) );
      }
      else if(wt[n-1]>W)
        return  dp[n][W] = solve(W,val,wt,n-1);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        memset(dp,-1,sizeof(dp));
    int n=val.size();    //number of items
       return solve(W,val,wt,n);
    }
};