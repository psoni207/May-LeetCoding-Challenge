class StockSpanner {
private:
    stack<int> st;
    vector<int> prices;
    int i = 0;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        if(st.empty()){
            prices.push_back(price);
            st.push(i);
            return i + 1;
        }
        
        prices.push_back(price);
        i += 1;
        while( !st.empty() && prices[st.top()] <= prices[i]){
            st.pop();   
        }
        
        int res;
        if(st.empty()){
            res = i + 1;
        }else{
            res = i - st.top();
        }
        
        st.push(i);
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

class StockSpanner {
    private:
        stack<pair<int, int> > st;
        
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        
        // 100 80 60 70 60 75 85
        // 100 1
        // 100 1 80 1
        // 100 1 80 1 60 1
        // 100 1 80 1 70 2
        // 100 1 80 1 70 2 60 1
        // 100 1 80 1 75 4
        // 100 1 85 6
        int counter = 1;
        while(!st.empty() && st.top().first <= price){
            counter += st.top().second;
            st.pop();
        }
        st.push({price,counter}); 
        
        return counter;
        
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */