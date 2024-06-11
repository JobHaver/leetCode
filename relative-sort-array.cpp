class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;

        for(int i : arr1)
            mp[i]++;

        int j = 0;
        for(int i = 0; i < arr2.size(); i++){
            int &curr = mp[arr2[i]];
            while(curr-- > 0)
                arr1[j++] = arr2[i];
        }

        for(pair<const int, int> &p : mp)
            while(p.second-- > 0)
                arr1[j++] = p.first;

        return arr1;
    }
};