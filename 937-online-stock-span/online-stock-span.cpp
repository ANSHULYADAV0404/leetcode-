class StockSpanner {
public:
    stack<pair<int, int>> st;
    // vector<int> ans;
    StockSpanner() {}

    int next(int price) {
        // for(int i=0;i<price.size();i++){
        int span = 1;
        while (st.size() > 0 && st.top().first <= price) {
            span += st.top().second;
            st.pop();
        }
        // prevhigh=st.top();
        /// if(!st.empty()){
        ///  ans=ans+st[price[i]];
        /// }else{
        //   i-prevhigh;
        // }
        //}
        st.push({price, span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */