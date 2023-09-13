class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();
        pair<int, int> index[size];
        vector<int> candies(size);

        for(int i = 0; i < size; i++)
            index[i] = {ratings[i], i};

        sort(index, index + size);

        int ans = 0;
        for(pair<int, int> &p : index){
            int i = p.second;
            int left = i-1 < 0 ? 0 : ratings[i-1] == p.first ? 0 :  candies[i-1];
            int right = i+1 >= size ? 0 : ratings[i+1] == p.first ? 0 :  candies[i+1];
            int toBeat = max(left, right) + 1;
            candies[i] = toBeat;
            ans += toBeat;
        }

        return ans;
    }
};