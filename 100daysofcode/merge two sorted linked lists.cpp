/*Merge Two Sorted Lists
Merge two sorted linked lists and return it as a sorted list. The list should be made by splicing together the nodes of the first two lists.
Example 1:
Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL) return l2;
        if(l2==NULL) return l1;
        if(l1->val > l2->val) std::swap(l1,l2);
        ListNode *output =l1;
        while(l1!=NULL && l2!=NULL){
            ListNode *temp =NULL;
            while(l1!=NULL && l1->val <=l2->val){
                temp=l1;
                l1=l1->next;
            }
            temp->next=l2;
            std::swap(l1,l2);
        }
        return output;
    }
};