class Solution {
public:
	string convert(string s, int numRows) {
		if (s.size() == 0 || s.size() == 1 || numRows == 1) {
			return s;
		}
		std::string result = "";
		int shortQueueNum = numRows - 2;
		for (int i = 0; i < numRows; ++i) {
			int flag = i;
			while (flag < s.size()) {
				result += s[flag];
				if (i != 0 && i != (numRows - 1)) {
					//add short queue
					int tag = numRows - i + shortQueueNum - i;
					if((tag + flag) < s.size()){
                        result += s[(flag + tag)];
					}
				}
				flag += numRows + shortQueueNum;
			}
		}
		return result;
	}
};