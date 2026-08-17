class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>>dp(n + 1,vector<bool>(sum + 1, false));
        // Initialization
        for(int i=0;i<=n;i++){
            dp[i][0] = true;
        }
        // Fill DP
        for(int i=1;i<=n;i++){
            for(int target =1;target<=sum;target++){
                // SKIP kiya 
                dp[i][target] = dp[i-1][target];

                // Take
                if(arr[i-1] <= target){
                    dp[i][target] = dp[i][target] || dp[i-1][target - arr[i-1]];
                }
            }
        }

        return dp[n][sum];
    }
};