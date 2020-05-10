class Solution {
public:
    bool isPerfectSquare(int num) {
        
        int low = 0, high = num;
        
        bool res = checkSquare(low, high, num);
        
        return res;
    }
    
    bool checkSquare(long low, long high, long num){
        
        while(low <= high){
            long mid = low + (high - low)/2;
			
            if(mid*mid == num){
                return true;
				
            }else{
                if(mid*mid < num){
                    low = mid + 1;
                }else{
                    high = mid - 1;
                }
            }
        }
        
        return false;
    }
};