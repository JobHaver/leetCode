class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;

        for(int i = 0; i < words.size(); ){
            int length = 0, start = i;
            for(; i < words.size() && length + (i - start) + words[i].length() <= maxWidth; i++)
                length += words[i].length();
                
            string line;
            if(i - start == 1 || i >= words.size()){
                int width = maxWidth;
                for(; start < i; start++){
                    width -= words[start].length();
                    line += width-- ? words[start] + ' ' : words[start]; //dont need to check for < 0
                }
                
                if(width > 0)
                    line += string(width, ' ');
            }
            else{
                int end = i - 1, size = i - start - 1, diff = maxWidth - length;
                int avg = diff / size, rem = diff % size;
                
                for(; start < end; start++)
                    line += words[start] + string(rem-- > 0 ? avg + 1 : avg, ' ');

                line += words[end]; // last word
            }

            ans.push_back(line);
        }

        return ans;
    }
};