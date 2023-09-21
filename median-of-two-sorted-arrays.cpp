class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int size1 = nums1.size(), size2 = nums2.size(), mid = (size1+size2)/2;
        int combined[mid + 1];
        int v1i = 0, v2i = 0;
        
        for(int i = 0; mid >= i; i++){
            if(v1i == size1)
                combined[i] = nums2[v2i++];
            else if(v2i == size2)
                combined[i] = nums1[v1i++];
            else if(nums1[v1i] < nums2[v2i])
                combined[i] = nums1[v1i++];
            else
                combined[i] = nums2[v2i++];
        }

        return (size1+size2) % 2 == 0 ? double ((combined[mid] + combined[mid - 1])/2.0) : double (combined[mid]);
    }
};