public class Solution {
    public int MaxFrequencyElements(int[] nums) {
        int maxSize = 101;
        int[] numCount = new int[maxSize];
        
        foreach(int i in nums)
            numCount[i]++;

        int max = Int32.MinValue, count = 0;
        foreach(int c in numCount){
            if(c > max){
                max = c;
                count = 1;
            }
            else if(c == max)
                count++;
        }

        return count * max;
        
    }
}