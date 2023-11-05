class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int curr = arr[0];
        for(int i = 1, winCount = 0, size = arr.size(); i < size; i++){
            if(curr < arr[i])
                winCount = 0, curr = arr[i];
            
            if(++winCount == k)
                return curr;
        }

        return curr;
    }
};