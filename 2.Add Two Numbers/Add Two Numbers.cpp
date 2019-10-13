class Solution {
public:
    //the title means that the lase node is never zero
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        bool add = false;
        ListNode* tmp1 = l1;
        ListNode* tmp1_front = nullptr;
        ListNode* tmp2 = l2;
        int result = 0;
        while(tmp1 && tmp2){
            result = tmp1->val + tmp2->val + add;
            if(result > 9){
                tmp1->val = result % 10;
                add = true;
            }
            else{
                tmp1->val = result;
                add = false;
            }
            tmp1_front = tmp1;
            tmp1 = tmp1->next;
            tmp2 = tmp2->next;
        }
        while(tmp1){
            if(add){
                tmp1->val += 1;
                if(tmp1->val > 9){
                    tmp1->val %= 10;
                    tmp1_front = tmp1;
                    tmp1 = tmp1->next;
                }
                else{
                    add = false;
                    break;
                }
            }
            else{
                break;
            }
        }

        if(tmp2 != nullptr){
            tmp1_front->next = tmp2;
        }
        while(tmp2){
            if(add){
                tmp2->val += 1;
                if(tmp2->val > 9){
                    tmp2->val %= 10;
                    tmp1_front = tmp2;
                    tmp2 = tmp2->next;
                }
                else{
                    add = false;
                    break;
                }
            }
            else{
                break;
            }
        }

        if(add){
            ListNode* add = new ListNode(1);
            tmp1_front->next = add;
            add->next = nullptr;
        }
        return l1;
    }
};