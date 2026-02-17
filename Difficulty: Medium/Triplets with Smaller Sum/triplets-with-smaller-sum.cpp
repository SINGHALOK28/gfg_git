class Solution {

  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        // Your code goes here
        sort(arr,arr+n);
        long long ans=0;
        for(int i=0;i<n-2;i++)
        {
            int left = i+1;
            int right = n-1;
            while(left<right)
            {   
                int target = arr[i]+arr[left]+arr[right];
                if(target>=sum)
                {
                    right--;
                }
                
                if(target<sum)
                {
                    ans = ans + (right-left);
                    left++;
                }
            }
        }
        
        return ans;
    }
};