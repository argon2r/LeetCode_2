class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int idx= 1;
        int firstIdx = -1;  //for maxd
        int lastIdx = -1;

        ListNode *a = head;
        ListNode *b = head->next;
        ListNode *c = head->next->next;

        if(c==NULL) return {-1,-1};

        int mind = INT_MAX;
        int f = -1;  // for mind
        int s = -1;

        while(c){
            if(b->val > a->val && b->val > c->val || b->val < a->val && b->val < c->val){
                //maxd
                if(firstIdx==-1) firstIdx = idx;
                else lastIdx = idx;
                
                //mind
                f = s;
                s = idx;
                if(f!=-1){
                    int d = s-f;
                    mind = min(mind,d);
                }
            }
            a = a->next;
            b = b->next;
            c = c->next;
            idx++;
        }
        if(lastIdx == -1) return {-1,-1};
        int maxd = lastIdx - firstIdx;
        return {mind,maxd};
    }   
};