class Solution {
public:
    double average(vector<int>& salary) {
        double ans;
        int min = salary[0], max = salary[0];
        for(int& i : salary){
            ans += i;
            if(i < min)
                min = i;
            else if(i > max)
                max = i;
        }

        return (ans - min - max) / (salary.size()-2);
    }
};