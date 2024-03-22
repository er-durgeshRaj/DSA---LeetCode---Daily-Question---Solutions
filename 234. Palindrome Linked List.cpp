/*QUESTION
Given the head of a singly linked list, return true if it is a palindrome or false otherwise.

 

Example 1:


Input: head = [1,2,2,1]
Output: true
Example 2:


Input: head = [1,2]
Output: false
 

Constraints:

The number of nodes in the list is in the range [1, 105].
0 <= Node.val <= 9
//////////////////////////////////////////////////////////////////////////////////////
SOLUTION*/
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> temp;

        ListNode* curr = head;
        while(curr) {
            temp.push_back(curr->val);
            curr = curr->next;
        }

        int i = 0;
        int j = temp.size()-1;

        while(i < j) {
            if(temp[i] != temp[j]) 
                return false;

            i++;
            j--;
        }

        return true;
    }
};
