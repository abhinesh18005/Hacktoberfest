class Solution {
public:
     
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        if(k<=1) return head;
        
        ListNode* dummy = new ListNode(0);
        ListNode *pre = dummy,*curr= dummy,*nex = dummy;
        
        
        
        while(len>=k){
            curr = pre->next;
            nex = curr->next;
            
            for(int i=1;i<k;i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            pre = curr;
            len-=k;
        }
        return dummy->next;
    }
};