class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        int m = ransomNote.size();
        int n = magazine.size();
        
        int freq1[26] = {0};
        int freq2[26] = {0};
        
        for(int i = 0; i < m; i++){
            freq1[ransomNote[i] - 'a'] += 1;
        }
        
        for(int i = 0; i < n; i++){
            freq2[magazine[i] - 'a'] += 1;
        }
        
        bool res = true;
        for(int i = 0; i < 26 ; i++){
            if(freq1[i] > freq2[i]){
                res = false;
                break;
            }
        }
        
        return res;
    }
};