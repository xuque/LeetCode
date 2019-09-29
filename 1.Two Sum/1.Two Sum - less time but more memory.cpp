class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		std::map<int, int> num_map;
		vector<int>result;
		for (int i = 0; i < nums.size(); ++i) {
			num_map.insert(std::pair<int, int>(nums[i], i));
		}
		for (int i = 0; i < nums.size(); ++i) {
			int find_num = target - nums[i];
			auto find_result = num_map.find(find_num);
			if (find_result->second != i && find_num * 2 == target) {
				result.push_back(i);
				result.push_back(find_result->second);
				break;
			}
			if (find_result != num_map.end() && find_result->second != i) {
				result.push_back(i);
				result.push_back(find_result->second);
				break;
			}
		}
		return result;
	}
};