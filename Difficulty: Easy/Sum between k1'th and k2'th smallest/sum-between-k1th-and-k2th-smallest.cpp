class Solution {
  public:
  
  int solve(vector<int>& arr, int k){
      priority_queue<int>pq;
     
     for(int i=0;i<arr.size();i++){
         pq.push(arr[i]);
         if(pq.size()>k)
            pq.pop();
        
     }
     return pq.top();
      
  }
    int sumBetweenK1K2(vector<int>& arr, int k1, int k2) {
        // code here
    //  int a = solve(arr, k1);
    //  int b = solve(arr, k2);
    //  int sum =0;
     
    //  for(int i=0;i<arr.size();i++){
    //      if(arr[i]>a && arr[i]<b)
    //         sum += arr[i];
    //  }
    //  return sum;
    
    sort(arr.begin(), arr.end());

    int sum = 0;

    for(int i = k1; i < k2 - 1; i++){
        sum += arr[i];
    }

    return sum;
    }
};