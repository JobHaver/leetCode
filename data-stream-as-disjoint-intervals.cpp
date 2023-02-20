class SummaryRanges {
public:
    vector<vector<int>> intervals;

    SummaryRanges() {
        intervals.clear(); //idk man, just being safe here
    }
    
    void addNum(int value) {
        int i = 0, size = intervals.size();

        for(; i < size; i++){
            if(intervals[i][0]-1 > value)
                break; // out of any current range
            else if(intervals[i][0] <= value && intervals[i][1] >= value){
                return; // term - already within a range
            }
            else if(intervals[i][0]-1 == value){
                intervals[i][0]--;
                return; // term - apended to begining of range
            }
            else if(intervals[i][1]+1 == value){//have to check next value
                if(i+1 < size){
                    if(intervals[i+1][0]-1 == value){ //checking next value
                        intervals[i][1] = intervals[i+1][1]; //union of reanges
                        intervals.erase(intervals.begin()+i+1); // removing after union
                        return; // term, union of two ranges
                    }
                }

                intervals[i][1]++; // term - appended to end of range
                return;
            }
        }

        intervals.insert(intervals.begin()+i, vector<int> {value, value});
    }
    
    vector<vector<int>> getIntervals() {
        return intervals;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */