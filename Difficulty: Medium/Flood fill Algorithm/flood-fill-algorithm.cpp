class Solution {
public:

    void solve(vector<vector<int>>& image, int i, int j, int color, int val){
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size()){
            return;
        }

        if (image[i][j] != val){
            return;
        }
        if (image[i][j] == color){
            return;
        }
        image[i][j] = color;
        solve(image, i - 1, j, color, val); // up
        solve(image, i + 1, j, color, val); // down
        solve(image, i, j - 1, color, val); // left
        solve(image, i, j + 1, color, val); // right
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image,int sr, int sc, int newColor) {
        int val = image[sr][sc];
        if (val == newColor)
            return image;
        solve(image, sr, sc, newColor, val);
        return image;
    }
};