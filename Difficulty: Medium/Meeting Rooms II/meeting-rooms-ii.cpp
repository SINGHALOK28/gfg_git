class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        int n = start.size();
        sort(start.begin(),start.end());
        sort(end.begin(),end.end());
        int room=0,res=0,i=0,j=0;
        while(i<n && j<n)
        {
            if(start[i]<end[j])
            {
                room++;
                res = max(res,room);
                i++;
            }
            else
            {
                room--;
                j++;
            }
        }
        
        return res;
    }
};
