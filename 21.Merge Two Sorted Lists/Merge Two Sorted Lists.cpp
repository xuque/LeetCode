/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode* result = new ListNode(-1);
		result->next = nullptr;
		ListNode* result_tmp = result;
		while (l1 && l2) {
			result_tmp->next = l1->val < l2->val ? l1 : l2;
			l1->val < l2->val ? l1 = l1->next : l2 = l2->next;
			result_tmp = result_tmp->next;
			result_tmp->next = nullptr;
		}
		if (l1 != nullptr) {
			result_tmp->next = l1;
		}
		if (l2 != nullptr) {
			result_tmp->next = l2;
		}
		return result->next;
	}
};