class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int low=0,high=k-1;
        int n=arr.size();
        int res=0,sum=0;
        for(int i=low;i<=high;i++)
        {
            sum+=arr[i];
        }
        while(high<n)
        {
            
            res = max(res,sum);
            low++;
            high++;
            if(high==n)
            break;
            sum-=arr[low-1];
            sum+=arr[high];
        }
        return res;
    }
};