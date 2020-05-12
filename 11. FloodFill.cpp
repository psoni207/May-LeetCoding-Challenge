class Solution {
    private:
    int m, n, myColor;
    vector<vector<bool> > visited;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        
        m = image.size();
        n = image[0].size();
        
        visited = vector<vector<bool> > (m,vector<bool> (n,0));
        
        myColor = image[sr][sc];
        helperSolve(image, sr, sc, newColor);
        
        return image;
    }
    
    
    void helperSolve(vector<vector<int>>& A, int i, int j, int x){
        
        if(i < 0 || i >= m || j < 0 || j >= n){
            return;
        }
        if(A[i][j] == myColor && visited[i][j] == false){
            A[i][j] = x;
            visited[i][j] = true;
            
            helperSolve(A, i-1, j, x);
            helperSolve(A, i+1, j, x);
            helperSolve(A, i, j-1, x);
            helperSolve(A, i, j+1, x);
        }
    }
};