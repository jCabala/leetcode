class RecentCounter {
private:
    queue<int> q;
public:
    RecentCounter() {
    }
    
    int ping(int t) {
        ios::sync_with_stdio(0); cin.tie(0);
        while(!q.empty() && t - q.front() > 3000) q.pop();
        q.push(t);

        return q.size();
    }
};

/**
 * Your RecentCounter object will be instantiated and called as such:
 * RecentCounter* obj = new RecentCounter();
 * int param_1 = obj->ping(t);
 */