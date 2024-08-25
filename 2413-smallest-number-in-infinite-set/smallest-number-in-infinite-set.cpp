class SmallestInfiniteSet {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    bool store[1001];

    SmallestInfiniteSet() {
        for(int i=1;i<=1000;i++) {
            pq.push(i);
            store[i]=true;
        }
    }
    
    int popSmallest() {
       int ele=pq.top();
       pq.pop();
       store[ele]=false;
       return ele; 
    }
    
    void addBack(int num) {
        if(store[num]==true) return;
        store[num]=true;
        pq.push(num);
    }
};