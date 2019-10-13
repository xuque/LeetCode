class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty() || s.size() == 1){
            return s.size();
        }
        int front = 0;
        int rear = 1;
        int len = 1;
        int record_len = 1;
        std::map<char, bool>record;
        record.insert(std::pair<char,bool>(s[0],true));
        while(rear < s.size()){
            if(record.find(s[rear]) != record.end()){
                ++front;
                record.clear();
                rear = front;
                len = 1;
            }
            else{
                ++len;
                if(record_len < len){
                    record_len = len;
                }
            }
            record.insert(std::pair<char,bool>(s[rear],true));
            ++rear;
        }
        return record_len;
    }
};