#include <iostream>
#include <unordered_set>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) {
        this->data = x;
        this->next = nullptr;
    }
};

bool detectLoop(Node* head) {
    unordered_set<Node*>st;
  
    while (head != nullptr) {

        // if this node is already present
        // in hashmap it means there is a cycle
        if (st.find(head) != st.end())
            return true;

        // if we are seeing the node for
        // the first time, insert it in hash
        st.insert(head);

        head = head->next;
    }
    return false;
}

int main() {

    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(4);
  
    head->next->next->next = head->next;

    if (detectLoop(head))
        cout << "true";
    else
        cout << "false";

    return 0;
}
