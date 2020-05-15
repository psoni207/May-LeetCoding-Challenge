class Solution {
    private:
    int N;
public:
    int maxSubarraySumCircular(vector<int>& A) {
        
        N = A.size();
        int minVal = INT_MIN;
        bool flag = false;
        
        
        //Check if all numbers are negative, then return least negative number
        for(int i = 0; i < N; i++) {
            if (A[i] >= 0) {
                flag = true;
                break;
            } else {
                minVal = max(minVal, A[i]);
            }
        }
        if (!flag) {
            return minVal;
        }
        
        //Invert array elements
        for (int i = 0; i < N; i++) {
            A[i] = -A[i];
        }

        // Run Kadane's algorithm on modified array
        int negMaxSum = maxSubArraySum(A);
        int arraySum = 0;

        // Restore the array
        for (int i = 0; i < N; i++) {
            A[i] = -A[i];
            arraySum += A[i];
        }
        
         //Return maximum of
         //1. Sum returned by Kadane's algorithm on original array.
         //2. Sum returned by Kadane's algorithm on modified array + Sum of all elements of the array.
        
         return max(maxSubArraySum(A), arraySum + negMaxSum);
    }
    
    int maxSubArraySum(vector<int> &A){
        int sum = 0;
        int maxSum = 0;
        
        for(int i = 0; i < N; i++){
            sum += A[i];
            
            if(maxSum < sum){
                maxSum = sum;
            }
            if(sum < 0){
                sum = 0;
            }
        }
        
        return maxSum;
    }
};