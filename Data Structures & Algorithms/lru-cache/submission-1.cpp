struct Node{
    int key;
    Node* prev;
    Node* next;
    Node(int k) : key(k){
        prev = nullptr;
        next = nullptr;
    }
};
class LRUCache {
private:
    int num_items = 0;
    int cap = 0;
    unordered_map<int, pair<int, Node*>> key_to_val_node;
    Node* head = nullptr;
    Node* tail = nullptr;
    

public:
    LRUCache(int capacity) : cap(capacity){}
    
    int get(int key) {
        if(key_to_val_node.contains(key)){
            Node* middle = key_to_val_node[key].second;
            Node* left = middle->prev;
            Node* right = middle->next;
            if(left == nullptr && right != nullptr){
                head = middle->next;
                head->prev = nullptr;
                middle->prev = tail;
                tail->next = middle;
                middle->next = nullptr;
                tail = middle;
            }
            else if(right != nullptr){
                left->next = right;
                right->prev = left;
                tail->next = middle;
                middle->prev = tail;
                middle->next = nullptr;
                tail = middle;
            }
            return key_to_val_node[key].first;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(head == nullptr){
            head = new Node(key);
            tail = head;
            key_to_val_node[key] = {value, head};
            num_items++;
        }
        else if(!key_to_val_node.contains(key)){
            num_items++;
            Node* new_one = new Node(key);
            tail->next = new_one;
            new_one->prev = tail;
            tail = new_one;
            key_to_val_node[key] = {value, new_one};
        }
        else{
            Node* middle = key_to_val_node[key].second;
            Node* left = middle->prev;
            Node* right = middle->next;
            key_to_val_node[key] = {value, middle};
            if(left == nullptr && right != nullptr){
                head = middle->next;
                head->prev = nullptr;
                middle->prev = tail;
                tail->next = middle;
                middle->next = nullptr;
                tail = middle;
            }
            else if(right != nullptr){
                left->next = right;
                right->prev = left;
                tail->next = middle;
                middle->prev = tail;
                middle->next = nullptr;
                tail = middle;
            }
        }
        if(num_items > cap){
            num_items--;
            Node* temp = head;
            head = head->next;
            head->prev = nullptr;
            key_to_val_node.erase(temp->key);
            delete(temp);
        }
    }
};
