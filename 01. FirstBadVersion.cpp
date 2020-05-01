// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        
        int low = 1;
        int high = n;
        
        int res = 1;
        while( low <= high){
            int mid = low + (high - low) / 2;
            
            if(isBadVersion(mid)){
                if(mid == 1 || !isBadVersion(mid - 1)){
                    res = mid;
                    break;
                }else{
                    high = mid - 1;
                }
            }else{
                low = mid + 1;
            }
        }
        
        return res;
    }
};