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
    ListNode* convertToLL(vector<int>& arr){
        if(arr.size() == 0) return nullptr;
        ListNode* head = new ListNode(arr[0]);
        ListNode* temp = head;

        for(int i=1; i<arr.size(); i++){
            ListNode* newNode = new ListNode(arr[i]);
            temp->next = newNode;
            temp = temp->next;
        }

        return head;

    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        vector<int>arr;

        ListNode* temp1 = list1;
        ListNode* temp2 = list2;

        while(temp1!=NULL){ // o(n1)
            arr.push_back(temp1->val);
            temp1=temp1->next;
        }

        while(temp2!=NULL){ // o(n2)
            arr.push_back(temp2->val);
            temp2=temp2->next;
        }

        sort(arr.begin(), arr.end()); // o(NlogN) N=n1+n2

        return convertToLL(arr); // o(N)
    }
};