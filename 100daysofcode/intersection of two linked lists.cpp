/*Intersection of Two Linked Lists
Write a program to find the node at which the intersection of two singly linked lists begins.
Input: intersectVal = 8, listA = [4,1,8,4,5], listB = [5,6,1,8,4,5], skipA = 2, skipB = 3
Output: Reference of the node with value = 8
Input Explanation: The intersected node's value is 8 (note that this must not be 0 if the two lists intersect).
 From the head of A, it reads as [4,1,8,4,5]. From the head of B, it reads as [5,6,1,8,4,5]. There are 2 nodes before the intersected node in A; 
 There are 3 nodes before the intersected node in B
 */
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA==NULL||headB==NULL) return NULL;
        ListNode *l1=headA , *l2=headB;
        while(l1!=l2){
            l1=l1==NULL?l1=headB:l1->next;
            l2=l2==NULL?l2=headA:l2->next;
        }
        return l1;
    }
};
//move both the l1 and l2 along the 2 lists
//whenever l1 or l2 reaches null,make it point to the head of the other list
//this makes the pointer l1 and l2 to align itself by equal pos wrt both lists before intersection in the 
//second iteraton
//so now wen we mov l1 and l2 by 1 , the point at which it collides is the intersection point 