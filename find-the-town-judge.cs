public class Solution {
    public int FindJudge(int n, int[][] trust) {
        int[] trustCount = new int[n + 1];
        for(int i = 0; i < trust.Length; i++){
            trustCount[trust[i][0]] = Int32.MinValue;
            trustCount[trust[i][1]]++;
        }
        
        for(int i = 1, k = n - 1; i < trustCount.Length; i++)
            if(k == trustCount[i])
                return i;

        return -1;
    }
}