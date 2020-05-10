class Solution {
    int n;
public:
    int majorityElement(vector<int>& nums) {
        n = nums.size();
        
		//Using Moore’s Voting Algorithm:
        int major = findCandidate(nums);
        
        int count = 0;
        for(int i = 0; i < n; i += 1){
            if(major == nums[i]){
                count += 1;
            }
        }
        
        if( count > n/2){
            return major;
        }
        
        return -1;
        
    }
    
    int findCandidate(vector<int> &nums){
        int maj_ind = 0;
        int count = 1;
        
        for(int i = 1; i < n; i +=1){
            if(nums[maj_ind] == nums[i]){
                count+= 1;
            }else{
                count -= 1;
            }
            
            if(count == 0){
                maj_ind = i;
                count = 1;
            }
        }
        
        return nums[maj_ind];
    }
};