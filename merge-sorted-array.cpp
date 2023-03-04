class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums1Copy(nums1.begin(), nums1.begin()+m);
        std::merge(nums1Copy.begin(), nums1Copy.end(), nums2.begin(), nums2.end(), nums1.begin());
    }
};