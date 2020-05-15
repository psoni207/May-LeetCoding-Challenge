class Solution {
    private:
    int low, high, n;
public:
    int singleNonDuplicate(vector<int>& nums) {
        n = nums.size();
        low = 0;
        high = nums.size() - 1;
        
        int res = binSearch(nums);
        return res;
    }
    
    int binSearch(vector<int> &nums){
        int res;
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if( mid%2 == 1){
                if(mid != 0 && nums[mid] == nums[mid-1]){
                    low = mid + 1;
                }else if(mid != n-1 && nums[mid] == nums[mid+1]){
                    high = mid - 1;
                }else{
                    res = nums[mid];
                    break;
                }
            }else{
                if(mid != n-1 && nums[mid] == nums[mid+1]){
                    low = mid + 1;
                }else if(mid != 0 && nums[mid] == nums[mid-1]){
                    high = mid - 1;
                }else{
                    res = nums[mid];
                    break;
                }
            }
        }
        
        return res;
    }
    
};