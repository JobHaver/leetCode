class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> combined;
        int v1i = 0, v2i = 0;
        int size1 = nums1.size(), size2 = nums2.size(), mid = (size1+size2)/2;

        combined.reserve(mid+1);
        
        while(mid >= combined.size()){
            if(v1i == size1)
                combined.push_back(nums2[v2i++]);
            else if(v2i == size2)
                combined.push_back(nums1[v1i++]);
            else{
                if(nums1[v1i] < nums2[v2i])
                    combined.push_back(nums1[v1i++]);
                else
                    combined.push_back(nums2[v2i++]);
            }
        }

        if ((size1+size2) % 2 == 0)
            return double ((combined[mid] + combined[mid - 1])/2.0);
        else
            return double (combined[mid]);
    }
};
