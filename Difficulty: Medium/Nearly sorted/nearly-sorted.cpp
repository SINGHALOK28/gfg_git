class Solution {
  public:
    void nearlySorted(vector<int>& arr, int k) {
        // code here
    priority_queue<int,vector<int>,greater<int>>pq;
    vector<int> temp;
    for(int i=0;i<arr.size();i++)
         {
            pq.push(arr[i]);

            if(pq.size()>k)
               { temp.push_back(pq.top());
                pq.pop();}
         }
          while(!pq.empty()) {
            temp.push_back(pq.top());
            pq.pop();
        }
        for(int i=0;i<temp.size();i++){
            arr[i]=temp[i];
        }
    }
};