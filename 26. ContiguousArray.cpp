class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int> umap;
        
        int res = 0,currSum=0;
        int n = nums.size();
        
        for(int i = 0;i < n; i++){
            currSum += (nums[i]==0) ? -1 : 1;
            
            if(currSum == 0){
                if(res < i+1)
                    res = i+1;
            }
            else if(umap.find(currSum) != umap.end()){
            
                if(res < i - umap[currSum]){
                    res = i - umap[currSum];
                }
            }
            else{
                umap[currSum] = i;
            }
        }
        return res;
    }
};