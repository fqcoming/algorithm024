/**
 * 21. 合并两个有序链表
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(l1==NULL) return l2;
    if(l2==NULL) return l1;
    struct ListNode *head, *last;
    if(l1->val <= l2->val){
        head = l1;
        l1 = l1->next;
    }
    else{
        head = l2;
        l2 = l2->next;
    }
    last = head;
    while(l1!=NULL && l2!=NULL){
        if(l1->val <= l2->val){
            last->next = l1;
            l1 = l1->next;
        }
        else{
            last->next = l2;
            l2 = l2->next;
        }
        last = last->next;        
    }
    if(l1!=NULL) 
        last->next = l1;
    else if(l2!=NULL) 
        last->next = l2;
    else
        last = NULL;
    return head;
}