class Solution {
public:
	int removeElement(vector<int>& nums, int val) {
		if (nums.size() == 0 || (nums.size() == 1 && nums[0] == val)) {
			return 0;
		}
		auto iter = nums.begin();
		for (++iter; iter != nums.end();) {
			auto tmp = iter;
			if (*tmp == val) {
				nums.erase(tmp);
			}
			else {
				++iter;
			}
		}
		if (nums.size() != 0 && nums[0] == val) {
			nums.erase(nums.begin());
		}
		return nums.size();
	}
};