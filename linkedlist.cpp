#include "linkedlist.h"
using namespace std;

//connstructor
LinkedList::LinkedList() : root(nullptr), nodeCount(0) {}

//destructor
LinkedList::~LinkedList() {
    delete_node_shared_ptr_list();
}

ostream& operator<<(ostream& os, const Node& node) {
    return os << "Node(data: " << node.data << ")";
}


void LinkedList::build_node_list(int k) {
    root = nullptr;
    shared_ptr<Node> current = nullptr;
    for (int i = 0; i < k; ++i) {
        auto newNode = make_shared<Node>(i);
        if (!root) {
            root = newNode;
        } else {
            current->next = newNode;
        }
        current = newNode;
    }
    nodeCount = k;
}

vector<CopyNode> LinkedList::build_copyNodes_weak_ptrs() {
    vector<CopyNode> copyNodes;
    auto current = root;
    while (current != nullptr) {
        CopyNode copyNode;
        copyNode.weak_node_ptr = current;
        copyNodes.push_back(copyNode);
        current = current->next;
    }
    return copyNodes;
}

void LinkedList::delete_node_shared_ptr_list() {
    root = nullptr;
    nodeCount = 0;
}

void LinkedList::print_node_list_shared_ptrs() {
    auto current = root;
    while (current != nullptr) {
        cout << *current << " -> ";
        current = current->next;
    }
    cout << "nullptr" << endl;
}

void LinkedList::print_node_array_weak_ptrs() {
    auto copyNodes = build_copyNodes_weak_ptrs();
    for (const auto& cn : copyNodes) {
        cout << cn.weak_node_ptr << endl;
    }
}
