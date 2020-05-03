class Solution {
public:
    Solution()
    {
        RomanMap.resize(13);
        RomanMap[0] = std::make_pair<int, string>(1,    "I");
        RomanMap[1] = std::make_pair<int, string>(4,    "IV");
        RomanMap[2] = std::make_pair<int, string>(5,    "V");
        RomanMap[3] = std::make_pair<int, string>(9,    "IX");
        RomanMap[4] = std::make_pair<int, string>(10,   "X");
        RomanMap[5] = std::make_pair<int, string>(40,   "XL");
        RomanMap[6] = std::make_pair<int, string>(50,   "L");
        RomanMap[7] = std::make_pair<int, string>(90,   "XC");
        RomanMap[8] = std::make_pair<int, string>(100,  "C");
        RomanMap[9] = std::make_pair<int, string>(400,  "CD");
        RomanMap[10] = std::make_pair<int, string>(500,  "D");
        RomanMap[11] = std::make_pair<int, string>(900,  "CM");
        RomanMap[12] = std::make_pair<int, string>(1000, "M");
    }

    string intToRoman(int num) {
        string result = "";
        for (int i = RomanMap.size() - 1; i >= 0; --i)
        {
            if(num / RomanMap[i].first != 0)
            {
                for (int j = 0; j < num / RomanMap[i].first; ++j)
                {
                    result += RomanMap[i].second;
                }
                num %= RomanMap[i].first;
            }
        }

        return result;
    }

private:
    std::vector<std::pair<int, string>> RomanMap;
};