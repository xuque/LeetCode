class Solution {
public:
    int maxArea(vector<int>& height) {
        int p1 = 0, p2 = height.size() - 1;
        int max = (height[p1] < height[p2] ? height[p1] : height[p2]) * (p2 - p1);
        while (p1 != p2)
        {
            bool tag;   //false -> move the left ptr, true -> move the right ptr
            height[p1] < height[p2] ? (++p1, tag = false) : (--p2, tag = true);
            if ((tag == false && height[p1] > height[p1 - 1]) || (tag == true && height[p2] > height[p2 + 1]))
            {
                if (((height[p1] < height[p2] ? height[p1] : height[p2]) * (p2 - p1)) > max)
                {
                    max = (height[p1] < height[p2] ? height[p1] : height[p2]) * (p2 - p1);
                }
            }
        }
        return max;
    }
};