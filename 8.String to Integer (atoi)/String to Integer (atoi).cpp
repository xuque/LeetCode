class Solution {
#define INT_MAX int(0x7fffffff)
#define INT_MIN int(0x80000000)
public:
    int myAtoi(string str) {
        if (str.size() <= 0) 
        {
            return 0;
        }

        const char* pStr = &(str[0]);
        bool flag = false;
        unsigned int result = 0;

        int index = 0;
        while (pStr[index] == ' ')
        {
            ++index;
        }

        if (pStr[index] == 43/* + */ || pStr[index] == 45/* - */)
        {
            flag = pStr[index] == 45 ? true : false;
            ++index;
        }

        while (index <= str.size() && pStr[index] >= 48 && pStr[index] <= 57)
        {
            unsigned tmp = result;
            for (int i = 0; i < 9 && result != 0; ++i) 
            {
                result += tmp;
                if (overflow(result, flag))
                {
                    return result;
                } 
            }
            result += (pStr[index] - '0'); //avoid to *10 more than 32bits 
            if (overflow(result, flag))
            {
                return result;
            }
            ++index;
        }
        return result * (flag ? -1 : 1);
    }
private:
    bool overflow(unsigned int& result, bool flag)
    {
        if (result & 0x80000000)
        {
            if (!flag)
            {
                result = INT_MAX;
                return true;
            }
            else if (result & 0x7fffffff)
            {
                result = INT_MIN;
                return true;
            }
        }
        return false;
    }
};