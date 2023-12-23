class Solution {
public:
    bool isPathCrossing(string path) {
        map<pair<short,short>, short> points;
        short x = 0, y = 0;
        points[{x,y}]++;
        for(char c : path){
            if(c == 'E')
                x++;
            else if(c == 'W')
                x--;
            else if(c == 'N')
                y++;
            else
                y--;

            if(points[{x,y}]++)
                return true;
        }

        return false;
    }
};