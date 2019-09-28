class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		auto iter_first = nums.begin();
		int index_first = 0;
		int index_second = 0;
		bool set_flag = true;
		vector<int>result;
		while (iter_first != nums.end() && set_flag) {
			auto iter_second = iter_first + 1;
			index_second = index_first + 1;
			while (iter_second != nums.end()) {
				if ((*iter_first + *iter_second) == target) {
					result.push_back(index_first);
					result.push_back(index_second);
					set_flag = false;
					break;
				}
				++iter_second;
				++index_second;
			}
			++iter_first;
			++index_first;
		}
		return result;
	}
};