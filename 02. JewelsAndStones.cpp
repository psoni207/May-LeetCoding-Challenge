class Solution {
public:
    int numJewelsInStones(string J, string S) {
        
        int freq[256] = {0};
        int m = J.size();
        int n = S.size();
        
		//Count freq of each stones
        for(int i = 0; i < n; i++){
            freq[S[i]] += 1;
        }
        
        int res = 0;
		//Count no. of each type of Jewels
        for(int i = 0; i < m; i++){
            res += freq[J[i]];
        }
        
        return res;
        
    }
};