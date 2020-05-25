class Solution {
    private:
    int m,n;
public:
    int countSquares(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return 0;
        }
        m = matrix.size();
        n = matrix[0].size();
        
        vector<vector<int> > dp(m, vector<int>(n,0));
        int res = 0;
        
        for(int i = 0; i < m; ++i){
            dp[i][0] = matrix[i][0] == 1 ? 1 : 0;
            if(dp[i][0]){
                res += 1;
            }
        }
        for(int j = 1; j < n; ++j){
            dp[0][j] = matrix[0][j] == 1 ? 1 : 0;
            if(dp[0][j]){
                res += 1;
            }
        }
        
		findMaxSquare(matrix,dp,res);
        
        return res;
        
    }
    
    void findMaxSquare(vector<vector<int> > &matrix, vector<vector<int> > &dp, int &res){
		
		for(int i = 1; i < m; ++i){
            for(int j = 1; j < n; ++j){
                if(matrix[i][j] == 1){
                    dp[i][j] = min( min(dp[i-1][j], dp[i][j-1]), dp[i-1][j-1]) + 1;
                    res += dp[i][j];
                }else{
                    dp[i][j] = 0;
                }
            }
        }
	}
};