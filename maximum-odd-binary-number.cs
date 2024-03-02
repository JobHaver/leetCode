public class Solution {
    public string MaximumOddBinaryNumber(string s) {
        StringBuilder sb = new StringBuilder(s);
        int ones = -1;
        for(int i = 0; i < sb.Length; i++){
            if(sb[i] == '1'){
                ones++;
                sb[i] = '0';
            }
        }

        sb[sb.Length - 1] = '1';
        for(int i = 0; ones-- != 0; i++)
            sb[i] = '1';

        return sb.ToString();
    }
}