class Solution {
public:
    string frequencySort(string s) {
        vector<pair<int,char> > count;
        vector<int> freq(256,0);
        
        int n = s.size();
        for(int i = 0; i < n; i++){
            freq[s[i]] += 1;
        }
        
        for(int i = 0; i < 256; i++){
            if(freq[i] != 0){
                count.push_back({freq[i],i});
            }
        }
        
        sort(count.begin(),count.end());
        
        string res = "";
        for(int i = count.size() - 1; i >= 0; i--){
            char ch = count[i].second;
            for(int j = 0; j < count[i].first; j++){
                res += ch;
            }
        }
        
        return res;
    }
};