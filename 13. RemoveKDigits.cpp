class Solution {
public:
    string removeKdigits(string num, int k) {
        
        int n = num.size();
       
        string NUM = num;
        if (n == k){
            return "0";   
        }
        
		/*We will iterate the number k times. In each iteration:
        1. Remove the digit for which the next digit is smaller.
        2. If we reach at the end than remove last digit.*/
        for (int i = 0; i < k; i++) {
            int j = 0;
            while (j < NUM.size() - 1 ) {
                if(NUM[j] <= NUM[j+1]){
                    j += 1;
                }else{
                    break;
                }
            }
            NUM.erase(j,1);
        }
        
		//remove leading 0's
        int i = 0;
        while(i < NUM.size() && NUM[i] == '0'){
            i += 1;
        }
        
        NUM.erase(0,i);
        if (NUM.size() == 0) {
            return "0";
        }

        return NUM;
        
    }
};