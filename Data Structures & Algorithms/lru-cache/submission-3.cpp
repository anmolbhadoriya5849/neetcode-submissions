class LRUCache {
public:

    class Node{
        public:
            int key;
            int value;
            Node* next;
            Node* prev;

        Node(int k, int v){
            key = k;
            value = v;
            next = NULL;
            prev = NULL;
        }
    };

    int capa;
    unordered_map<int,Node*> mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        capa = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void addNode(Node* node){
        tail->prev->next = node;
        node->prev = tail->prev;

        node->next = tail;
        tail->prev = node;
    }

    void deleteNode(Node* node){
        node->prev->next = node->next;
        node->next->prev = node->prev;

        node->next = NULL;
        node->prev = NULL;
    }
    
    int get(int key) {
        if(mp.count(key)){

            deleteNode(mp[key]);

            addNode(mp[key]);
            return mp[key]->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.size() == capa && !mp.count(key)){
            Node* node = new Node(key, value);
            addNode(node);
            Node* lru = head->next;
            mp.erase(lru->key);
            deleteNode(lru);
            delete lru;
            mp[key] = node;
            return;
        }

        if(mp.count(key)){
            mp[key]->value = value;
            deleteNode(mp[key]);
            addNode(mp[key]);
        }
        else{
            Node* node = new Node(key, value);
            mp[key] = node;
            addNode(node);
        }
    }
};
