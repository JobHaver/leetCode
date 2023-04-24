class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> s;

        for(int i : stones)
            s.push(i);


        while(s.size() > 1){
            int r0 = s.top();
            s.pop();
            int r1 = s.top();
            s.pop();

            if(r0 > r1)
                s.push(r0-r1);
        }

        return s.empty() ? 0 : s.top();
    }
};