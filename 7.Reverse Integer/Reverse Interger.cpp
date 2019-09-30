class Solution {
public:
	int reverse(int x) {
	    long result = 0;
	    bool negative = false;
		std::queue<int>Queue;
		if (x < 0) {
            if (x == pow(-2, 31)) {
				return 0;
			}
			x = -1 * x;
			negative = true;
		}
		while (x != 0) {
			int remainder_num = x % 10;
			Queue.push(remainder_num);
			x /= 10;
		}
		int len = Queue.size();
		for (int i = 0; i < len; ++i) {
			result = result * 10 + Queue.front();
			Queue.pop();
		}
        if(negative == true){
            result *= -1;
        }
        return result;
	}
};
