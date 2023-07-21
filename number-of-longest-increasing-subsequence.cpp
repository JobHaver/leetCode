class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int size = nums.size(), ans = 0, max = 0;
        vector<int> sorted(nums), count(size), ways(size);

        sort(sorted.begin(), sorted.end());

        for(int i = 0; i < size; i++){
            int index = upper_bound(sorted.begin(), sorted.end(), nums[i]) - sorted.begin() - 1;
            while(count[index])//there will always be one that is 0
                index--;

            count[index]++;

            for(int j = index - 1; j > -1; j--){
                if(count[j]){
                    int subSize = count[j] + 1;
                    if(subSize == count[index])
                        ways[index] += ways[j];
                    else if(subSize > count[index]){
                        count[index] = subSize;
                        ways[index] = ways[j];
                    }
                }
            }

            ways[index] = ways[index] ? ways[index] : 1;
        }

        for(int i = 0; i < size; i++){
            // cout << sorted[i] << " " << count[i] << " " << ways[i] << ", ";
            if(count[i] == max)
                ans += ways[i];
            else if(count[i] > max){
                max = count[i];
                ans = ways[i];
            }
        }

        return ans;
    }
};