class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        size_t len = nums1.size() + nums2.size();
        size_t mid = len / 2;
        size_t flag = len % 2;
        size_t p1 = 0, p2 = 0;
        size_t findIndex = mid + flag;

        int last = 0;
        for (size_t i = 0; i < findIndex; ++i)
        {
            if (p1 < nums1.size() && p2 < nums2.size())
            {
                //if v1's value is the same as v2's, firstly moved the p1 
                if (nums1[p1] <= nums2[p2])
                {
                    last = nums1[p1];
                    ++p1;
                }
                else 
                {
                    last = nums2[p2];
                    ++p2;
                }
            }
            else if (p1 < nums1.size())
            {
                last = nums1[p1];
                ++p1;
            }
            else if (p2 < nums2.size()) 
            {
                last = nums2[p2];
                ++p2;
            }
        }
        double result = last;
        if (flag == 0)
        {
            //get min between v1 and v2
            if (p1 == nums1.size())
            {
                result += nums2[p2];
            }
            else if (p2 == nums2.size())
            {
                result += nums1[p1];
            }
            else
            {
                result += nums1[p1] <= nums2[p2] ? nums1[p1] : nums2[p2];
            }
            result /= 2;
        }

        return result;
    }
};