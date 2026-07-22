class Solution {
public:
    unordered_map<Node*, Node*> mp;

    Node* copyRandomList(Node* head) {

        if(head == NULL)
            return NULL;

        Node* copy = new Node(head->val);
        mp[head] = copy;

        Node* curr = head->next;
        Node* net = copy;

        while(curr != NULL){
            Node* copy1 = new Node(curr->val);
            net->next = copy1;

            net = copy1;
            mp[curr] = copy1;

            curr = curr->next;
        }

        curr = head;
        net = copy;

        while(curr != NULL){

            if(curr->random)
                net->random = mp[curr->random];
            else
                net->random = NULL;

            curr = curr->next;
            net = net->next;
        }

        return copy;
    }
};