class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        int n = points.size();
        multimap<int,int> mm;
    
        for(int i = 0; i < n; i++){
            mm.insert( {points[i][0]*points[i][0] + points[i][1]*points[i][1], i} );   
        }
        
        vector<vector<int> > res;
        
        int count = 0;
        for(auto it = mm.begin(); count < K; it++){
            res.push_back(points[it->second]);
            count += 1;
        }
        
        return res;
    }
};