class Solution {
private:
    vector<bool> visited;
    vector<int> *n;

    bool helper(int i){
        if(i >= n->size())
            return true;

        if(visited[i])
            return false;
        
        visited[i] = true;
        vector<int> &v = *n; // not needed just for readability
        //had a disgusting error were i forgot size() was unsigned and was doing subtraction and geting 3190230578
        if(i+3 <= v.size() && ((v[i] == v[i+1] && v[i+1] == v[i+2]) || (v[i] == v[i+1]-1 && v[i+1] == v[i+2]-1))){
            if(helper(i+3))
                return true;
        }

        if(i+2 <= v.size() && v[i] == v[i+1]){
            if(helper(i+2))
                return true;
        }
            
        return false;
    }

public:
    bool validPartition(vector<int>& nums) {
        n = &nums;
        visited.resize(nums.size()+1);
        return helper(0);
    }
};