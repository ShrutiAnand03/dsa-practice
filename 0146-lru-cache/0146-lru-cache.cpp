class Node{
public:
    int key;
    int value;
    Node* prev;
    Node* next;

    Node(int k, int val){
        key = k;
        value = val;
        prev = nullptr;
        next = nullptr;
    }
};

class LRUCache {
public:
    int capacity;
    unordered_map<int,Node*>mp;
    Node* head;
    Node* tail;

    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    void remove(Node* node){
        Node* prevNode = node->prev;
        Node* nextNode = node->next;

        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void add(Node* node){
        Node* nextNode = head->next;

        head->next = node;
        node->prev = head;

        node->next = nextNode;
        nextNode->prev = node;
    }
    
    int get(int key) {
        if(mp.find(key)==mp.end()) return -1;

        Node* nodeToUpdate = mp[key];
        remove(nodeToUpdate);
        add(nodeToUpdate);
        return nodeToUpdate->value;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end()){
            Node* oldNode = mp[key];
            remove(oldNode);
            mp.erase(key);
            delete oldNode;
        }

        Node* newNode = new Node(key, value);
        add(newNode);
        mp[key] = newNode;

        if(mp.size()>capacity){
            Node* nodeToDelete = tail->prev;
            remove(nodeToDelete);
            mp.erase(nodeToDelete->key);
            delete nodeToDelete;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */