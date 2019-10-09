class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
	    std::string result = "";
	    if (strs.size() == 0 || strs[0].length() == 0) {
			return result;
		}

		int common_len = strs[0].length();
		const char* str = strs[0].c_str();
		for (size_t i = 1; i < strs.size(); ++i) {
			int len = 0;
			while (strs[i].length() > 0 && strs[i].length() >= len && common_len--) {
				const char* str2 = strs[i].c_str();
				if (str[len] == str2[len]) {
					++len;
				}
				else {
					break;
				}
			}
			common_len = len;
			if(common_len == 0){
                break;
			}
		}
		for (int i = 0; i < common_len; ++i) {
			result += str[i];
		}
		return result;
	}
};