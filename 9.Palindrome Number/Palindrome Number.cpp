class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
        {
            return false;
        }
        string str = std::to_string(x);
        int len = str.length();
        bool result = true;

        for (int i = 0; i < len / 2; ++i)
        {
            if (str.c_str()[i] != str.c_str()[len - i - 1])
            {
                result = false;
                break;
            }
        }

        return result;
    }
};