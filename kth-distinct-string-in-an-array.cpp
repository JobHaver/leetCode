class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        vector<bool> repeat(arr.size());
        unordered_map<string, int*> mp;

        for(int i = 0; i < arr.size(); i++){
            int *&index = mp[arr[i]];
            if(index == NULL)
                index = new int(i);
            else
                repeat[*index] = repeat[i] = true;
        }

        for(int i = 0; i < arr.size(); i++)
            if(!repeat[i] && !--k)
                return arr[i];

        return "";
    }
};