// QUESTION
// Given the head of a linked list, we repeatedly delete consecutive sequences of nodes that sum to 0 until there are no such sequences.

// After doing so, return the head of the final linked list.  You may return any such answer.

 

// (Note that in the examples below, all sequences are serializations of ListNode objects.)

// Example 1:

// Input: head = [1,2,-3,3,1]
// Output: [3,1]
// Note: The answer [1,2,1] would also be accepted.
// Example 2:

// Input: head = [1,2,3,-3,4]
// Output: [1,2,4]
// Example 3:

// Input: head = [1,2,3,-3,-2]
// Output: [1]
 

// Constraints:

// The given linked list will contain between 1 and 1000 nodes.
// Each node in the linked list has -1000 <= node.val <= 1000.
// /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// SOLUTION
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        unordered_map<int, ListNode*> mp;
        mp[0] = dummyNode;
        int prefSum = 0;

        while(head != nullptr){
            prefSum += head->val;
            if(mp.find(prefSum) != mp.end()){
                ListNode* start = mp[prefSum]; //start->next to head [delete all]
                int pf = prefSum;
                ListNode* temp = start;
                while(temp->next != head){
                    temp = temp->next;
                    pf += temp->val;
                    mp.erase(pf);
                }
                start->next = head->next;
            }else{
                mp[prefSum] = head;
            }
            head = head->next;
        }

        ListNode* newHead = dummyNode->next;
        delete(dummyNode);
        return newHead;
    }
};
