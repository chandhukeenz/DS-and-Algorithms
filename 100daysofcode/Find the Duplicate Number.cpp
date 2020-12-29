//Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.

//There is only one duplicate number in nums, return this duplicate number.

//Follow-ups:

//How can we prove that at least one duplicate number must exist in nums? 
//Can you solve the problem without modifying the array nums?
//Can you solve the problem using only constant, O(1) extra space?
//Can you solve the problem with runtime complexity less than O(n2)?

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow=nums[0],fast=nums[0];
        do{
            slow=nums[slow];
            fast=nums[nums[fast]];
        } while(slow!=fast);
        fast=nums[0];
        while(fast!=slow){
            slow=nums[slow];
            fast=nums[fast];
        }
        return fast;
    }
        
};

// 1(s)(f) 3 4 2 2
//take slow and fast pointer to traverse through the array using linked list concept (slow moves by 1, fast moves by 2)
//stop when the slow and fast pointer meet each other
//restart the fast pointer to its first pos.Now move the slow and fast pointer in the same speed.
//Now the collision point of slow and fast pointer becomes the duplicate number in the array