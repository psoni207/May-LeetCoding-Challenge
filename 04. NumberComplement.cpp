class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        int msb = findMsb(num);
        
		//Suppose num = 9 (1001) then msb bit is 4
		// create a mask with first 4 bits as 1. res = 1111
        for(int i=0; i<msb; i++){
            res += (1<<i);
        }
        
		//just xor res with num, you'll get the complement.. 
		//1111 ^ 1001 = 0110
		
		//Another ex: num = 5(101), mask = 111,  101 ^ 111 = 010
        res = res  ^ num;
        return res;
    }
    
    int findMsb(int num){
        int res = 0;
        while(num){
            res += 1;
            num/=2;
        }
        
        return res;
    }
};