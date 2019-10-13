class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty() || s.size() == 1){
            return s.size();
        }
        int front = 0;
        int rear = 1;
        int record_len = 1;
        std::map<char, bool>record;
        record.insert(std::pair<char,bool>(s[0],true));
        while(rear < s.size()){
            if(record.find(s[rear]) != record.end()){
                while(s[front] != s[rear]){
                    record.erase(s[front++]);
                }
                ++front;
            }
            else{
                record.insert(std::pair<char,bool>(s[rear],true));
                if(record_len < record.size()){
                    record_len = record.size();
                }
            }
            ++rear;
        }
        return record_len;
    }
};