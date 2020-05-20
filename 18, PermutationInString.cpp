class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        
        string s = s2;
        string p = s1;
        
        int n = s.size();
        int k = p.size();
        
        bool res = false;
        if(k > n){
            return res;
        }
        
        vector<int> freqP(26,0);
        vector<int> freqS(26,0);
        
        for(int i = 0; i < k; i++){
            freqP[p[i]-'a'] += 1;
            freqS[s[i]-'a'] += 1;
        }
        
        if(checkAnagram(freqP,freqS)){
            res = true;
        }else{
            
            for(int i = 1; i <= n - k; i++){
                freqS[s[i-1]-'a'] -= 1;
                freqS[s[i+k-1]-'a'] += 1;

                if(checkAnagram(freqP,freqS)){
                    res = true;
                    break;
                }
            }    
        }
        
        
        
        return res;
    }
    
    
    bool checkAnagram(vector<int> &freqP, vector<int> &freqS){
        
        for(int i = 0; i < 26; i++){
            if(freqP[i] != freqS[i]){
                return false;
            }
        }
        
        return true;
    }
};