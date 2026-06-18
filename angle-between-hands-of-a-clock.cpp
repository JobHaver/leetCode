class Solution {
public:
    double angleClock(int hour, int minutes) {
        double minuteAngle = minutes*6;
        double hourAngle = std::fmod(((hour*30) + (0.5*minutes)), 360);

        double angleMade = abs(minuteAngle - hourAngle);

        return angleMade > 180 ? 360 - angleMade : angleMade;
    }
};