/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*,Node*> mp;
        if(head==NULL){
            return NULL;
        }
        Node* newHead=new Node(head->val);
        Node* oldTemp= head->next;
        Node* newTemp= newHead;
        mp[head]=newHead;
        while(oldTemp!=NULL){
            Node* copynode=new Node(oldTemp->val);
            mp[oldTemp]=copynode;
            newTemp->next=copynode;
            oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }
        oldTemp=head; newTemp=newHead;
        while(oldTemp!=NULL){
            newTemp->random=mp[oldTemp->random];
            oldTemp=oldTemp->next;
            newTemp=newTemp->next;
        }
       return newHead; 
    }
};