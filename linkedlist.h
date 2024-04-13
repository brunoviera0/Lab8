#pragma once
#include <iostream>
#include <memory>
#include <vector>

using namespace std;

struct Node;


std::ostream& operator<<(std::ostream& os, const Node& node);


template <typename T>
std::ostream& operator<<(std::ostream& os, const std::shared_ptr<T>& p) {
    return os << p.get() << " shared_ptr count: [" << p.use_count() << "]";
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const std::weak_ptr<T>& p) {
    T* raw = nullptr;
    auto sp = p.lock();
    raw = sp.get();
    return os << raw << " weak_ptr to shared_ptr count: [" << p.use_count() << "]";
}

struct Node {
    int data;
    shared_ptr<Node> next;
    Node(int data = 0, shared_ptr<Node> ptr = nullptr) : data(data), next(ptr) {}
};

struct CopyNode {
    weak_ptr<Node> weak_node_ptr;
};

class LinkedList {
public:
    LinkedList();
    ~LinkedList();
    void build_node_list(int k);
    vector<CopyNode> build_copyNodes_weak_ptrs();
    void delete_node_shared_ptr_list();
    void print_node_list_shared_ptrs();
    void print_node_array_weak_ptrs();

private:
    shared_ptr<Node> root;
    int nodeCount;
};
