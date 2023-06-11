class SnapshotArray {
private:
    vector<vector<pair<int, int>>> snaps;
    int s;

public:
    SnapshotArray(int length) {
        s = 0;
        snaps.resize(length);
    }
    
    void set(int index, int val) {
        if(!snaps[index].empty() && snaps[index].back().first == s)
            snaps[index].back().second = val;
        else
            snaps[index].push_back({s, val});
    }
    
    int snap() {
        return s++;
    }
    
    int get(int index, int snap_id) {
        // int prev = -1;
        // for(int i = 0; i < snaps[index].size() && snaps[index][i].first <= snap_id; prev = i++);
        // return prev < 0 ? 0 : snaps[index][prev].second;

        if(snaps[index].empty() || snaps[index][0].first > snap_id)
            return 0;

        int l = 0, r = snaps[index].size()-1;
        while(l < r) {
            int mid = (r+l+1)/2;
            if(snaps[index][mid].first <= snap_id)
                l = mid;
            else 
                r = mid-1;
        }

        return snaps[index][l].second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */