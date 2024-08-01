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
    ListNode* reverse(ListNode* head){
        ListNode* prev=NULL;
        while(head!=NULL){
            ListNode* temp=head->next;
            head->next=prev;
            prev=head;
            head=temp;
        }
        return prev;
    }
    ListNode* middle(ListNode* head){
        ListNode* f=head->next;
        ListNode* s=head;
        while(f!=NULL and f->next!=NULL){
            f=f->next->next;
            s=s->next;
        }
        return s;
    }
    bool isPalindrome(ListNode* head){
        if(head->next==NULL){
            return true;
        }
        ListNode* mid=middle(head);
        ListNode* head2=mid->next;
        mid->next=NULL;
        head2=reverse(head2);
        while(head!=NULL && head2!=NULL){
            if(head->val!=head2->val){
                return false;
            }
            head=head->next;
            head2=head2->next;
        }
        return true;
    }
};