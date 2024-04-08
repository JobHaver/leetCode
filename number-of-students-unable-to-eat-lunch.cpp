class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int stud[] = {0,0};
        for(int i : students)
            stud[i]++;

        int i;
        for(i = 0; i < sandwiches.size(); i++)
            if(!stud[sandwiches[i]]--) 
                break;

        return sandwiches.size() - i;
    }
};