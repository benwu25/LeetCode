#include <vector>
#include <memory>

using namespace std;

class Trie {
private:
    class node {
        public:
        char c;
        bool marks_inserted;
        vector<unique_ptr<node>> children;
        node(char _c) : c(_c), marks_inserted(false) {}
    };
    // one for each unique starting character
    vector<unique_ptr<node>> roots;
public:
    Trie() : roots(vector<unique_ptr<node>>()) {}

    void insert(string word) {
        // initialize vec pointer to point to current vec, iterate
        // till next char is found, or append to the end.
        vector<unique_ptr<node>> *curr_vec = &roots;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            vector<unique_ptr<node>> *next_vec = curr_vec;
            for (int j = 0; j < curr_vec->size(); ++j) {
                node *p = (*curr_vec)[j].get();
                if (p->c == c) {
                    if (i+1 == word.size())
                        p->marks_inserted = true;
                    next_vec = &p->children;
                    break;
                }
            }
            if (next_vec == curr_vec) {
                curr_vec->push_back(make_unique<node>(c));
                next_vec = &curr_vec->back()->children;
                if (i+1 == word.size())
                    curr_vec->back()->marks_inserted = true;
            }
            curr_vec = next_vec;
        }
    }

    bool search(string word) {
        vector<unique_ptr<node>> *curr_vec = &roots;
        for (int i = 0; i < word.size(); ++i) {
            char c = word[i];
            vector<unique_ptr<node>> *next_vec = curr_vec;
            for (auto& p : *curr_vec) {
                if (p->c == c) {
                    if (i+1 == word.size() && p->marks_inserted)
                        return true;
                    next_vec = &p->children;
                    break;
                }
            }
            if (next_vec == curr_vec)
                return false;
            curr_vec = next_vec;
        }
        return false;
    }

    bool startsWith(string prefix) {
        vector<unique_ptr<node>> *curr_vec = &roots;
        for (int i = 0; i < prefix.size(); ++i) {
            char c = prefix[i];
            vector<unique_ptr<node>> *next_vec = curr_vec;
            for (auto& p : *curr_vec) {
                if (p->c == c) {
                    next_vec = &p->children;
                    break;
                }
            }
            if (next_vec == curr_vec)
                return false;
            curr_vec = next_vec;
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
