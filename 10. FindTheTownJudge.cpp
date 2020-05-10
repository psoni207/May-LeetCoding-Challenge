class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        
        int M = trust.size();
        
        vector<int> count(N,0);
        vector<bool> check(N,true);
        
        for(int i = 0; i < M; i++){
            count[trust[i][1]-1] += 1;
            check[trust[i][0]-1] = false;
        }
        
        int res = -1;
        for(int i = 0; i < N; i++){
            if(check[i] && count[i] == N - 1){
                res = i+1;
                break;
            }
        }
        
        return res;
    }
};