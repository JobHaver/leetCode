class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        string temp;

        for(int i = 0; i < path.size(); i++){
            while(i < path.size() && path[i] != '/')
                temp += path[i++];
            
            if(temp == ".."){
                if(!dirs.empty()) 
                    dirs.pop_back();
            }
            else if(temp != "." && !temp.empty())
                dirs.push_back(temp);
            
            temp.clear();
        }

        for(const string &s : dirs)
            temp += '/' + s; 

        return temp.empty() ? "/" : temp;
    }
};