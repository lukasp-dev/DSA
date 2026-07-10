class Skiplist {
private:
    struct Node{
        int val;
        vector<Node*> next; 

        Node(int num, int level):val(num), next(level, nullptr){}
    };

    int getRandomLevel(){
        static random_device rd;
        static mt19937 gen(rd());
        static uniform_int_distribution dist(0, 1);
        
        int level = 1;
        while(level < MAX_LEVEL && dist(gen) == 1){
            ++level;
        }

        return level;
    }

    Node* head;
    int currentLevel;
    static int constexpr MAX_LEVEL = 18;
    
public:
    Skiplist() {
        head = new Node(INT_MIN, MAX_LEVEL);
        currentLevel = 1;
    }
    
    bool search(int target) {
        Node* cur = head;

        for(int level = currentLevel - 1; level >= 0; --level){
            while(cur->next[level] && cur->next[level]->val < target){
                cur = cur->next[level];
            }
        }

        cur = cur->next[0];

        return cur && cur->val == target;
    }
    
    void add(int num) {
        Node* cur = head;
        vector<Node*> update(MAX_LEVEL, nullptr);

        for(int level = currentLevel - 1; level >= 0; --level){
            while(cur->next[level] && cur->next[level]->val < num){
                cur = cur->next[level];
            }
            update[level] = cur;
        }

        int randomLevel = getRandomLevel();

        if(randomLevel > currentLevel){
            for(int level = currentLevel; level < randomLevel; ++level){
                update[level] = head;
            }

            currentLevel = randomLevel;
        }

        Node* newNode = new Node(num, randomLevel);

        for(int level = 0; level < randomLevel; ++level){
            newNode->next[level] = update[level]->next[level];
            update[level]->next[level] = newNode;
        }
    }
    
    bool erase(int num) {
        Node* cur = head;
        vector<Node*> update(MAX_LEVEL, nullptr);

        for(int level = currentLevel - 1; level >= 0; --level){
            while(cur->next[level] && cur->next[level]->val < num){
                cur = cur->next[level];
            }
            update[level] = cur;
        }

        Node* node_to_delete = cur->next[0];

        if(!node_to_delete || node_to_delete->val != num) return false;

        for(int level = currentLevel - 1; level >= 0; --level){
            if(update[level]->next[level] != node_to_delete) continue;
            update[level]->next[level] = node_to_delete->next[level];
        }
        
        delete node_to_delete;

        while(head->next[currentLevel - 1] == nullptr){
            --currentLevel;
        }

        return true;
    }
};

/**
 * Your Skiplist object will be instantiated and called as such:
 * Skiplist* obj = new Skiplist();
 * bool param_1 = obj->search(target);
 * obj->add(num);
 * bool param_3 = obj->erase(num);
 */