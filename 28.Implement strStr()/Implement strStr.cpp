class Solution {
public:
	int strStr(string haystack, string needle) {
		if (needle.empty())
		{
			return 0;
		}

		int hay_len = haystack.length();
		int need_len = needle.length();
		int next_arr[need_len];
		::memset(next_arr, 0, need_len);
		getNext(needle.c_str(), need_len, next_arr);

		int i = 0;
		int j = 0;
		while (i < hay_len && j < need_len)
		{
			if (j == -1 || haystack[i] == needle[j])
			{
				i++;
				j++;
			}
			else
			{
				j = next_arr[j];
			}
		}
		if (j == need_len)
			return i - j;
		else
			return -1;
	}

private:
	void getNext(const char* str, int len, int* next) {
		next[0] = -1;
		int k = -1;
		int j = 0;
		while (j < (len - 1))
		{
			if (k == -1 || str[j] == str[k])
			{
				++k;
				++j;
				next[j] = k;
			}
			else
			{
				k = next[k];
			}
		}
	}
};