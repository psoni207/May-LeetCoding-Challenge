class Solution {
    private:
        unordered_map<int,set<int> > graph;
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        
        int m = dislikes.size();
        
        for(int i = 0; i < m; i++){
            graph[dislikes[i][0]].insert(dislikes[i][1]);
            graph[dislikes[i][1]].insert(dislikes[i][0]);
        }
        
        vector<int> colors(N+1,0);
        for(int i = 1; i <= N; i++){
            if(colors[i] == 0 && !dfsColor(colors,1,i)){
                return false;
            }
        }
        
        return true;
    }
    
    bool dfsColor(vector<int> &colors, int col, int node){
        if(colors[node] != 0){
            return (colors[node] == col ? true : false );
        }
        
        colors[node] = col;
        if( graph.find(node) == graph.end() ){
            return true;
        }
        
        set<int> nodes;
        nodes = graph[node];
        for(auto it = nodes.begin(); it != nodes.end(); it++){
            if(!dfsColor(colors,-col,*it)){
                return false;
            }
        }
        
        return true;
    }
    
};