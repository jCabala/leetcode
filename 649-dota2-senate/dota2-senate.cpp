class Solution {
public:
    string predictPartyVictory(string senate) {
        ios::sync_with_stdio(0); cin.tie(0);
        queue<int> r, d;
        int total = 0;
        
        for (int i = 0; i < senate.length(); i++) {
            char c = senate[i];
            if (c == 'R') r.push(i);
            else d.push(i);

            total++;
        }

        while(!r.empty() && !d.empty()) {
            int rf = r.front(), df = d.front();
            r.pop(); d.pop();

            if (rf < df) r.push(rf + total);
            else d.push(df + total);
        }

        if (r.empty()) return "Dire";

        return "Radiant";
    }
};