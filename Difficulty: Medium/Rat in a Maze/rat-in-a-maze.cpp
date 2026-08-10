class Solution {
  public:
  vector<string> result;
  
  void solve(int i,int j,vector<vector<int>>& maze,string& path){
      
    int n=maze.size(); 
    if(i<0 || i>=n || j<0 || j>=n || maze[i][j]==0){
        return;
    }  
    if(i==n-1 && j==n-1){
        result.push_back(path);
        return;
    }
    
    maze[i][j]=0;
    
    path.push_back('D');
    solve(i+1,j,maze,path);
    path.pop_back();
    
    path.push_back('L');
    solve(i,j-1,maze,path);
    path.pop_back();
    
    path.push_back('R');
    solve(i,j+1,maze,path);
    path.pop_back();
    
    path.push_back('U');
    solve(i-1,j,maze,path);
    path.pop_back();
    
    maze[i][j]=1;
  }
  
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        string path="";
        solve(0,0,maze,path);
        // reverse(result.begin(), result.end());
        return result;
        
    }
};