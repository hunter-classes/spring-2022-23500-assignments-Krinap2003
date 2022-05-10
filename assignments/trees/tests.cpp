#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "BSTree.h"
#include "Node.h"

BSTree *t = new BSTree();

TEST_CASE("serch and rsearch")
{
    t->setup();
    CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 30, ");
    int serchInt = t->search(10);
    CHECK(serchInt == 10);
    serchInt = t->search(20);
    CHECK(serchInt == 20);
    serchInt = t->rsearch(30);
    CHECK(serchInt == 30);
    serchInt = t->rsearch(5);
    CHECK(serchInt == 5);
    try {
    serchInt = t->search(16);
    } catch (int e){
    CHECK(e == 1);
    }
    try {
    serchInt = t->rsearch(16);
    } catch (int e){
    CHECK(e == 1);
    }
}

TEST_CASE("insert")
{
    t->insert(21);
    CHECK(t->get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 21, , 30, ");
    try {
    int serchInt = t->search(21);
    CHECK(serchInt == 21);
    } catch (int e){
    CHECK(e == 1);
    }
    t->insert(7);
    CHECK(t->get_debug_string() == ", 3, , 5, , 7, , 8, , 10, , 15, , 20, , 21, , 30, ");
    t->insert(32);
    CHECK(t->get_debug_string() == ", 3, , 5, , 7, , 8, , 10, , 15, , 20, , 21, , 30, , 32, ");

}

TEST_CASE("delete")
{
    t->deleteNum(3);
    CHECK(t->get_debug_string() == ", 5, , 7, , 8, , 10, , 15, , 20, , 21, , 30, , 32, ");
    t->deleteNum(8);
    CHECK(t->get_debug_string() == ", 5, , 7, , 10, , 15, , 20, , 21, , 30, , 32, ");
    t->deleteNum(30);
    CHECK(t->get_debug_string() == ", 5, , 7, , 10, , 15, , 20, , 21, , 32, ");
    t->deleteNum(32);
    CHECK(t->get_debug_string() == ", 5, , 7, , 10, , 15, , 20, , 21, ");
    t->deleteNum(10);
    CHECK(t->get_debug_string() == ", 5, , 7, , 15, , 20, , 21, ");
    t->insert(22);
    CHECK(t->get_debug_string() == ", 5, , 7, , 15, , 20, , 21, , 22, ");
    t->insert(3);
    CHECK(t->get_debug_string() == ", 3, , 5, , 7, , 15, , 20, , 21, , 22, ");
    t->insert(10);
    CHECK(t->get_debug_string() == ", 3, , 5, , 7, , 10, , 15, , 20, , 21, , 22, ");
    t->deleteNum(3);
    CHECK(t->get_debug_string() == ", 5, , 7, , 10, , 15, , 20, , 21, , 22, ");
    t->deleteNum(22);
    CHECK(t->get_debug_string() == ", 5, , 7, , 10, , 15, , 20, , 21, ");
}

BSTree *t2 = new BSTree();

TEST_CASE("count leaves")
{
    CHECK(t2->countLeaves() == 0);
    t2->insert(10);
    CHECK(t2->countLeaves() == 1);
    t2->setup();
    CHECK(t2->countLeaves() == 4);
    CHECK(t2->get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 30, ");
    t2->insert(9);
    CHECK(t2->countLeaves() == 4);
    CHECK(t2->get_debug_string() == ", 3, , 5, , 8, , 9, , 10, , 15, , 20, , 30, ");
}

TEST_CASE("height")
{
    CHECK(t2->getHeight() == 4);
    BSTree *t3 = new BSTree();
    CHECK(t3->getHeight() == 0);
    t3->setup();
    CHECK(t3->getHeight() == 3);
    t3->insert(31);
    t3->insert(32);
    CHECK(t3->getHeight() == 5);
}

TEST_CASE("Get Level Sum")
{
    CHECK(t2->sumAtLevel(0) == 0);
    CHECK(t2->sumAtLevel(1) == 10);
    CHECK(t2->sumAtLevel(2) == 25);
    CHECK(t2->sumAtLevel(3) == 56);
    CHECK(t2->sumAtLevel(4) == 9);
}
