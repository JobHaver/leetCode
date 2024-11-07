class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        vector<int> binaryPositionCount(32);
        for(int num : candidates){
            for(int i = 0; num != 0; i++, num >>= 1)
                if(num & 1)
                    binaryPositionCount[i]++;
        }

        return *std::max_element(binaryPositionCount.begin(), binaryPositionCount.end());
    }
};