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