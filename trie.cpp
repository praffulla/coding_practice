#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node {
    bool flag;
    Node *child[26];
    
    bool containsKey(char c) {
        if(child[c-'a'] != NULL)
            return true;
        return false;
    }
    
    void put(char c, Node *node) {
        child[c-'a'] = node;
    }
    
    Node* get(char c) {
        return child[c-'a'];
    }
};


class Trie {
  
  Node *root;  
  public:
  
  Trie() {
    root = new Node();  
  }

    void suggestUtil(Node *temp, string s) {

        if(temp->flag == 1) {
            cout << s << "\n";
        }

        for(int i = 0; i < 26; i++) {
            if(temp->child[i] != NULL) {
                char c = i + 'a';
                suggestUtil(temp->child[i], s+c);
            }
        }
            
    }

    void suggest(string s) {
        Node *temp = root;
        for(int i =0 ; i < s.length(); i++) {
            if(!temp->containsKey(s[i]))
                return;

            temp = temp->get(s[i]);
        }

        suggestUtil(temp, s);

    }

    bool search(string s) {
        Node *temp = root;
        for(int i = 0; i < s.length(); i++) {
            if(!temp->containsKey(s[i])){
                cout << s << " not found" << "\n";
                return false;
            }
            temp = temp->get(s[i]);
        }
        
        if(temp->flag == false) {
            cout << s << "not found\n";
            return false;
        }
        cout << s << " found" << "\n";
        return true;
        
    } 
  
  void insert(string s) {
      //cout << "in for ";
      
      Node *temp = root;
      for(int i = 0; i < s.length(); i++) {
        if(!temp->containsKey(s[i])) {
            temp->put(s[i], new Node());
        }
        
        temp = temp->get(s[i]);
      }
      
      temp->flag = true;
      cout << "inserted " << s << "\n";
  }  
};

int main() {
    // Write C++ code here
    
    Trie *trie = new Trie();
    trie->insert("ram");
    trie->insert("ramprasad");
    trie->insert("ramkumar");
    trie->insert("harry");
    trie->insert("harrystyle");
    trie->insert("harrypotter");

    trie->search("ram");
    trie->search("harry");
    trie->search("harrypotter");
    trie->search("ramsing");
    trie->suggest("harry");
    return 0;
}
