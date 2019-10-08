#include <iostream>
#include <string>
#include <queue>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result = 0;
        int len = s.length();
        const char* str = s.c_str();
        char tmp = str[0];

        std::queue<char> Queue;
        for(int i = 1; i < len; ++i){
            Queue.push(str[i]);
        }
        while(!Queue.empty()){
            const char& p = Queue.front();
            if(judge(tmp, p)){
                result -= calculate(tmp);
            }
            else{
                result += calculate(tmp);
            }
            tmp = p;
            Queue.pop();
        }
        result += calculate(tmp);
        return result;
    }
private:
    int calculate(const char& p){
        int result = 0;
        switch(p){
        case 'I':
            result = 1;
            break;
        case 'V':
            result = 5;
            break;
        case 'X':
            result = 10;
            break;
        case 'L':
            result = 50;
            break;
        case 'C':
            result = 100;
            break;
        case 'D':
            result = 500;
            break;
        case 'M':
            result = 1000;
            break;
        default:
            result = 0;
        }
        return result;
    }
    bool judge(const char& p1, const char& p2){
        if(p1 == 'I' && (p2 == 'V' || p2 == 'X')){
            return true;
        }
        else if(p1 == 'X' && (p2 == 'L' || p2 == 'C')){
            return true;
        }
        else if(p1 == 'C' && (p2 == 'D' || p2 == 'M')){
            return true;
        }
        return false;
    }
};

int main()
{
    Solution s;
    int r = s.romanToInt("MCMXCIV");
    std::cout << r ;
    return 0;
}
