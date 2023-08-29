class Solution {
public:
    int bestClosingTime(string customers) {
        int n = 0;
        for(int i = 0; i < customers.size(); i++){
            if(customers[i] == 'Y')
                n++;
        }
        
        int min = n, minIndex = -1;
        for(int i = 0; i < customers.size(); i++){
            if((customers[i] == 'N' ? ++n : --n) < min)
                min = n, minIndex = i;
        }

        return minIndex + 1;
    }
};