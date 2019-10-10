class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty() || nums.size() == 1){
			return nums.size();
		}
        int flag = nums[0];
        auto tmp = nums.begin();
        for(auto iter = nums.begin() + 1;iter != nums.end();){
            tmp = iter;
            if(*tmp == flag){
                nums.erase(tmp);
            }
            else{
                ++iter;
                flag = *tmp;
            }
        }
		return nums.size();
	}
};
