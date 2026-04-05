// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        int mid,start=0,end=arr.size()-1;
        int result =-1;
        while(start<=end)
        {
            mid = start + (end - start)/2;
            if( arr[mid] < x)
            start = mid + 1;
            else{
            
            result = mid;    
            end = mid - 1;
            }
        }
        return result;
    }
};