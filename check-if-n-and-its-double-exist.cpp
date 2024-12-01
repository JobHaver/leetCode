class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> s;
        bool zero = false;

        for(int i : arr){
            if(i == 0){
                if(zero)
                    return true;
                else
                    zero = true;
            }
            else
                s.insert(i*2);
        }
            
        for(int i : arr)
            if(s.find(i) != s.end())
                return true;

        return false; 
    }
};