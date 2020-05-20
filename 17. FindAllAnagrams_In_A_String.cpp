class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size();
        int k = p.size();
        vector<int> res;
        
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
            res.push_back(0);
        }
        
        for(int i = 1; i <= n - k; i++){
            freqS[s[i-1]-'a'] -= 1;
            freqS[s[i+k-1]-'a'] += 1;
            
            if(checkAnagram(freqP,freqS)){
                res.push_back(i);
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