public class Solution {
    public string CustomSortString(string order, string s) {
        int[] alph = new int[26];
        foreach(char c in s)
            alph[c-'a']++;
        
        String ans = "";
        foreach(char c in order){
            int i = c-'a';
            if(alph[i] != 0){
                ans += new String(c, alph[i]);
                alph[i] = 0;
            }
        }

        for(int i = 0; i < alph.Length; i++)
            if(alph[i] != 0)
                ans += new String((char)(i+'a'), alph[i]);

        return ans;
    }
}