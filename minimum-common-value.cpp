class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int i = 0, j = 0, si = nums1.size(), sj = nums2.size();
        while(i < si && j < sj){
            if(nums1[i] == nums2[j])
                return nums1[i];

            if(nums1[i] > nums2[j]) j++; else i++;
        }

        return -1;
    }
};