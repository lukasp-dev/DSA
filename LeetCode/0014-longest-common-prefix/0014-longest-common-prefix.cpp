struct Node {
    Node* children[26];
    int childCount;
    bool isEnd;

    Node() : children(), childCount(0), isEnd(false) {}
};
    
class Trie {
private:
    Node* root;
public:
    Node* getRoot(){
        return root;
    }

    Trie() : root(new Node()) {}

    void insert(string& str) {
        Node* current = root;
        
        for(char& c : str) {
            int index = c - 'a';

            if(current->children[index] == nullptr) {
                current->children[index] = new Node();
                current->childCount++;
            }
            current = current->children[index];
        }

        current->isEnd = true;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie* trie = new Trie();
        string prefix;

        for(string& str : strs) {
            trie->insert(str);
        }

        Node* curr = trie->getRoot();
        string str = strs[0];
        
        for(char& c : str) {
            int index = c - 'a';
            if(curr->childCount == 1 && curr->isEnd == false) {
                prefix += c;
                curr = curr->children[index];
            }else {
                return prefix;
            }
        }

        return prefix;
    }
};