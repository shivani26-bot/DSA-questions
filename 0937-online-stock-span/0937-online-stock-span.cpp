class StockSpanner {
    stack<pair<int,int>>st;
public:
    StockSpanner() {
        
    }
    // monotonic stack, maintain a pair of {price, count} inside stock, so that if we even pop out the element from the stock, count will maintain that how many consecutive days were there where stck price was <= price of the current day
    int next(int price) {
     int count=1;//every element itself is a count 1

while(!st.empty() && st.top().first<=price){
   count+=st.top().second;
    st.pop();
}

  st.push({price,count});
      return count;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */