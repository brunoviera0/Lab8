#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "linkedlist.h"

TEST_CASE("Testing linked list creation and deletion") {
    LinkedList list;
    list.build_node_list(3);
    CHECK(list.build_copyNodes_weak_ptrs().size() == 3);
    list.delete_node_shared_ptr_list();
    auto copyNodes = list.build_copyNodes_weak_ptrs();
    for (auto& cn : copyNodes) {
        CHECK(cn.weak_node_ptr.expired() == true);
    }
}

TEST_CASE("Testing node data") {
    LinkedList list;
    list.build_node_list(3);

    auto copyNodes = list.build_copyNodes_weak_ptrs();
    int expectedValue = 0;
    for (auto& cn : copyNodes) {
        auto nodePtr = cn.weak_node_ptr.lock();
        if (nodePtr) {
            CHECK(nodePtr->data == expectedValue++);
        } else {
            CHECK(false);  //fail the test if we cannot lock the weak_ptr
        }
    }
}
