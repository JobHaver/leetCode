public class Solution {
    public int MissingNumber(int[] nums) {
        int expected = nums.Length;
        int actual = 0;
        for(int i = 0; i < nums.Length; i++){
            expected += i;
            actual += nums[i];
        }

        return expected - actual;
    }
}