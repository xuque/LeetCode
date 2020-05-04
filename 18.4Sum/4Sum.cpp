class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        if (nums.size() < 4)
        {
            return result;
        }

        int minValue = 0;
        for (const auto& num : nums)
        {
            if (minValue > num)
            {
                minValue = num;
            }
        }

        if (minValue < 0)
        {
            minValue = abs(minValue);
            target += minValue * 4;
            for (auto& num : nums)
            {
                num += minValue;
            }
        }
        else
        {
            minValue = 0;
        }

        for (int i = 0; i <= (nums.size() - 4); ++i)
        {
            if (nums[i] <= target)
            {
                for (int j = i + 1; j <= (nums.size() - 3); ++j)
                {
                    if ((nums[i] + nums[j]) <= target)
                    {
                        for (int k = j + 1; k <= (nums.size() - 2); ++k)
                        {
                            if ((nums[i] + nums[j] + nums[k]) <= target)
                            {
                                for (int t = k + 1; t <= (nums.size() - 1); ++t)
                                {
                                    if ((nums[i] + nums[j] + nums[k] + nums[t]) == target)
                                    {
                                        std::vector<int> add;
                                        add.resize(4);
                                        add[0] = nums[i] - minValue;
                                        add[1] = nums[j] - minValue;
                                        add[2] = nums[k] - minValue;
                                        add[3] = nums[t] - minValue;
                                        std::sort(add.begin(), add.end());
                                        result.push_back(add);
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        std::set<vector<int>> resultSet;
        for (const auto& num : result)
        {
            resultSet.insert(num);
        }
        result.clear();
        for (const auto& num : resultSet)
        {
            result.push_back(num);
        }

        //std::sort(result.begin(), result.end());
        return result;
    }
};