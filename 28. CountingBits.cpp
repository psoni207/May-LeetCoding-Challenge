class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res(num+1);
        res[0] = 0;
        
        int i = 1;
        while(i <= num){
            if(i % 2 == 1){
                res[i] = res[i/2] + 1;
            }else{
                res[i] = res[i/2];
            }
            i += 1;
        }
        
        return res;
    }
};