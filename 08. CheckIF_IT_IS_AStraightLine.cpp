class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int N = coordinates.size();
        int nume,deno;
        
        //Sort the Points
		sort(coordinates.begin(),coordinates.end(),comparatorFunc);
        
        //As N >= 2
        nume = coordinates[1][0] - coordinates[0][0];
        deno = coordinates[1][1] - coordinates[0][1];
        
        
        //Slope = nume/deno
        if(nume != 0 || deno != 0 ){
            int gcd = __gcd(abs(nume),abs(deno));
            nume = nume / gcd;
            deno = deno / gcd;    
        }
        
        
        int x, y;
        bool res = true;
        for(int i = 2; i < N; i += 1){
            x = coordinates[i][0] - coordinates[i-1][0];
            y = coordinates[i][1] - coordinates[i-1][1];
            
            if( x != 0 || y != 0){
                int gcd = __gcd(abs(x),abs(y));
                x = x / gcd;
                y = y / gcd;    
            }     
            
            
            if( x != nume || y!= deno){
                res = false;
                break;
            }
        }       
        
        return res;
    }
                            
     
    static bool comparatorFunc(vector<int> &a, vector<int> &b){
        if(a[0] < b[0]){
            return true;
        }
        
        if(a[0] == b[0] ){
            if(a[1] <= b[1]){
                return true;
            }
        }
        
        return false;
    }
 
};