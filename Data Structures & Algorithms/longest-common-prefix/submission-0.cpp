class Node {
    public:
        unordered_map<char, Node*> children;
        bool endOfWord;
        int freq;

        Node() {
            endOfWord = false;
        }
};

class Trie {
    Node* root;
public:
    Trie() {
        root = new Node();
        root->freq = -1;
    }

    void insert(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(temp->children.count(word[i]) == 0) {
                temp->children[word[i]] = new Node();
                temp->children[word[i]]->freq = 1;
            } else {
                temp->children[word[i]]->freq++;
            }
            temp = temp->children[word[i]];
        }
        temp->endOfWord = true;
    }

    bool search(string word) {
        Node* temp = root;
        for(int i=0; i<word.size(); i++) {
            if(temp->children.count(word[i])) {
                temp = temp->children[word[i]];
            } else {
                return false;
            }
        }
        return temp->endOfWord;
    }
    string findCommonPrefix(Trie &trie, string key, string &ans, int n) {
        Node* temp = root;
        for(int i=0; i<key.size(); i++) {
            if(temp->children.count(key[i])) {
                if(temp->children[key[i]]->freq == n) {
                    ans += key[i];
                    temp = temp->children[key[i]];
                } else {
                    break;
                }
            } else {
                break;
            }
        }

        return ans;
    }
};

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        Trie trie;
        string ans;
        for(int i=0; i<strs.size(); i++) {
            trie.insert(strs[i]);
        }

        return trie.findCommonPrefix(trie, strs[0], ans, strs.size());
        
    }
};