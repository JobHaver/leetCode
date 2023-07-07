class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int n) {
        int j = 0, k = 0, max = -1, size = answerKey.length(), nj = n, nk = n;

        for(int i = 0; i < size; i++){
            if(answerKey[i] != 'T' && --nj < 0){
                max = std::max(max, i - j);
                while(answerKey[j++] == 'T'){}
            }
            else if(answerKey[i] != 'F' && --nk < 0){
                max = std::max(max, i - k);
                while(answerKey[k++] == 'F'){}
            }
        }

        return std::max(max, std::max(size - k, size - j));
    }
};