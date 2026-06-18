class Node {
   public:
    int val;
    int key;
    Node* next;
    Node(int key, int val) {
        this->val = val;
        this->key = key;
        next = NULL;
    }
};

class MyHashMap {
   public:
    int totalSize;
    int size;
    Node** table;

    int hashFunction(int key) { return key % totalSize; }

    MyHashMap() {
        totalSize = 10000;
        size = 0;
        table = new Node* [totalSize] {};
    }

    void put(int key, int value) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                temp->val = value;
                return;
            }
            temp = temp->next;
        }

        Node* newNode = new Node(key, value);

        newNode->next = table[idx];
        table[idx] = newNode;
        size++;
    }

    int get(int key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        while (temp != NULL) {
            if (temp->key == key) {
                return temp->val;
            }
            temp = temp->next;
        }

        return -1;
    }

    void remove(int key) {
        int idx = hashFunction(key);

        Node* temp = table[idx];
        Node* prev = temp;
        while (temp != NULL) {
            if (temp->key == key) {
                if (prev == temp) {
                    table[idx] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                size--;
                delete temp;
                break;
            }
            prev = temp;
            temp = temp->next;
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */