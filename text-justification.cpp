class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        for(int i = 0; i < words.size(); ){
            vector<int> temp;
            int length = 0;
            for(;i < words.size() && length + temp.size() + words[i].length() <= maxWidth; i++){   
                temp.push_back(i);
                length += words[i].length();
            }
                
            string line;
            if(temp.size() == 1 || i >= words.size()){
                int rem = maxWidth;
                for(int s : temp){
                    line += words[s];
                    rem -= words[s].length();
                    if(rem--) //dont need to check for < 0
                        line += ' ';
                }
                
                if(rem > 0)
                    line += string(rem, ' ');
            }
            else{
                int size = temp.size()-1, diff = maxWidth - length, avg = diff / size, rem = diff % size;
                
                for(int j = 0; j < size; j++){
                    line += words[temp[j]];
                    line += string(avg, ' ');
                    if(rem-- > 0)
                        line += ' ';
                }

                line += words[temp[size]]; // last elm
            }

            ans.push_back(line);
        }

        return ans;
    }
};