class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == NULL)
            return list2;
        if(list2 == NULL)
            return list1;
        ListNode * head = list1;
        if(list1 -> val > list2 -> val){
            head = list2;
            list2 = list2 -> next;
        }
        else{
            list1 = list1 -> next;
        }
        ListNode *curr = head;
        while(list1 &&  list2){
            if(list1 -> val < list2 -> val){
                curr->next = list1;
                list1 = list1 -> next;
            }
            else{
                curr->next = list2;
                list2 = list2 -> next;
            }
            curr = curr -> next;       
        }
        if(list1==NULL)
            curr -> next = list2;
        else
            curr -> next = list1;   
        return head;
       
    }
};