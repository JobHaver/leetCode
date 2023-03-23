class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> connected(n);
        int groups = 1;
        int merged_groups = 2;
        int in = 0;
        int lines = connections.size();

        if(n - lines > 1) //fun fact, .size() returns unsigned int so you cant use it here
            return -1;

        for(const vector<int> &i : connections){
            int & c1 = connected[i[0]];
            int & c2 = connected[i[1]];

            if(c1 && c2){
                if(c1 != c2){ //merge groups
                    merged_groups++;
                    int min = std::min(c1, c2);
                    int max = std::max(c1, c2);

                    replace(connected.begin(), connected.end(), max, min);
                }
            }
            else if(c1){
                c2 = c1;
                in++;
            }
            else if(c2){
                c1 = c2;
                in++;
            }
            else{
                in += 2;
                c1 = groups++;
                c2 = c1;
            }
        }

        return (n - in) + (groups - merged_groups);
    }
};