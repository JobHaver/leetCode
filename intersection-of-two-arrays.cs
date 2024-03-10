public class Solution {
    public int[] Intersection(int[] nums1, int[] nums2) {
        Dictionary<int, bool> mp = new();
        foreach(int i in nums1)
            mp[i] = true;

        List<int> ans = new();
        foreach(int i in nums2){
            if(mp.ContainsKey(i)){
                mp.Remove(i);
                ans.Add(i);
            }
        }

        return ans.ToArray();
    }
}