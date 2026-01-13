class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        addOne(digits, digits.size()-1);
        return digits;
    }

    void addOne(vector<int>& digits, int index){
        if(digits[index] != 9){
            digits[index]++;
            return;
        }

        digits[index] = 0;

        if(index == 0){
            digits.insert(digits.begin(), 1);
            return;
        }

        addOne(digits, index - 1);
    }
};