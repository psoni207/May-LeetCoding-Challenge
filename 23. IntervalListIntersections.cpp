class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
        vector<vector<int> > res;
        int n = A.size();
        int m = B.size();
        
        int i,j;
        i = j = 0;
        
        
        // 5 - - - - 10
        //       8 - - - 12
        vector<int> temp(2);
        while(i < n && j < m){
            
            if(A[i][0] <= B[j][1] && B[j][0] <= A[i][1]){
                
                temp[0] = max(A[i][0],B[j][0]);
                temp[1] = min(A[i][1],B[j][1]);
                res.push_back(temp);
            }
            
            if(A[i][1] <= B[j][1]){
                i += 1;
            }else{
                j += 1;
            }
        }
        
        return res;
    }
};