class Solution {
public:
    string reorganizeString(string s) {
        vector<int> count(26);
        string ans = s;

        for(char c : s)
            count[c - 'a']++;
        
        priority_queue<pair<int, char>> pq;
        for(int i = 0; i < 26; i++){
            if(count[i])
                pq.push({count[i], i + 'a'});
        }

        if(pq.top().first > (s.size() + 1) / 2)
            return "";

        pair<int, char> prev = pq.top(), c; //init prev
        pq.pop();
        ans[0] = prev.second;
        for(int i = 1; !pq.empty(); i++, prev = c){
            c = pq.top();
            pq.pop();
            ans[i] = c.second;

            if(--prev.first)
                pq.push(prev);
        }

        return ans;
    }
};