#include "linkedlist.h"

int main() {
    LinkedList list;
    list.build_node_list(5);
    cout << "Main list before deletion:" << endl;
    list.print_node_list_shared_ptrs();

    cout << "Weak pointers before deletion:" << endl;
    list.print_node_array_weak_ptrs();

    list.delete_node_shared_ptr_list();

    cout << "Main list after deletion:" << endl;
    list.print_node_list_shared_ptrs();

    cout << "Weak pointers after deletion:" << endl;
    list.print_node_array_weak_ptrs();

    return 0;
}
