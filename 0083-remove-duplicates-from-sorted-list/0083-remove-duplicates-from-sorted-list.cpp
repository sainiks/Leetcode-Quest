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
    ListNode* deleteDuplicates(ListNode* head) {
    if(head==NULL){
            return head;
        }
        set<int> s;
        ListNode* cur=head;
        ListNode* ans=NULL;
        ListNode* tail=NULL;
        while(cur!=NULL){
            int x =cur->val;
            if(s.count(x)==0){
                s.insert(x);
                if(ans==NULL){
                    ans=cur;
                    tail=cur;
                }else{
                    tail->next=cur;
                    tail=tail->next;
                }
            }
            cout<<tail->val<<endl;
            cur=cur->next;
        }
        tail->next=NULL;
        return ans;    
    }
};