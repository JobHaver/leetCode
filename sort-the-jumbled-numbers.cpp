class Solution {
private:
    vector<int>* map;
    unordered_map<int, int> evaluated;

    int numConverter(int i){
        int ans = 0, power = 1;
        if(i == 0)
            return (*map)[i];

        while(i > 0){
            ans = (*map)[i % 10] * power + ans;
            power *= 10;
            i /= 10;
        }

        return ans;
    }

public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        map = &mapping;
        sort(nums.begin(), nums.end(), [this](const int a, const int b){
            int &conA = evaluated[a], &conB = evaluated[b];
            if(!conA)
                conA = numConverter(a);
            if(!conB)
                conB = numConverter(b);

            return conA < conB;
        });

        return nums;
    }
};