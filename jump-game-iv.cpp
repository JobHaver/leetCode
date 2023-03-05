class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> duplicates;
        vector<bool> visited(arr.size());
        vector<int> curr, next;
        int count = 0;

        for(int i = 0; i < arr.size(); i++)// initalize
            duplicates[arr[i]].push_back(i);

        visited[0] = true;
        curr.push_back(0);

        while(curr.size() != 0){
            for(int& i: curr){
                if(i == arr.size()-1)
                    return count;

                if(i-1 >= 0 && !visited[i-1]) 
                    next.push_back(i-1), visited[i-1] = true;
                //dont need to check > size bc if it was last element we would have exited
                if(!visited[i+1]) 
                    next.push_back(i+1), visited[i+1] = true;

                vector<int>& dup= duplicates[arr[i]];
                for(int& copy: dup){
                    if(!visited[copy])
                        next.push_back(copy), visited[copy] = true;
                }
                dup.clear(); //done so never check copys again
            }
            curr = next;
            next.clear();
            count++;
        }

        return -1;
    }
};