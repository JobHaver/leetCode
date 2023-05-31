class UndergroundSystem {
private:
    unordered_map<int, pair<string, int>> ids;
    unordered_map<string, pair<int, int>> stations;

public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        pair<string, int> &idMap = ids[id];
        idMap.first = stationName;
        idMap.second = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> &idMap = ids[id];
        pair<int, int> &time = stations[idMap.first+'+'+stationName];
        time.first += t - idMap.second;
        time.second++; 
        //cout << id << " " << time.first << " " << time.second << endl;
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<int, int> &time = stations[startStation+'+'+endStation];
        return (double)time.first / time.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */