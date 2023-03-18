class BrowserHistory {
public:
    vector<string> visited;
    int curr;
    int end;

    BrowserHistory(string homepage) {
        visited.push_back(homepage);
        curr = 0;
        end = curr;
    }
    
    void visit(string url) {
        if(++curr < visited.size())
            visited[curr] = url;
        else
            visited.push_back(url);
        
        end = curr;
    }
    
    string back(int steps) {
        curr = std::max(0, curr-steps);
        return visited[curr];
    }
    
    string forward(int steps) {
        curr = std::min(end, curr+steps);
        return visited[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */