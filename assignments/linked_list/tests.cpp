#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "List.h"
#include "Node.h"
#include "OList.h"
#include <iostream>


List *l1 = new List();

TEST_CASE("Constructor Method")
{
    CHECK(l1->toString() == "nullptr");
}

TEST_CASE("Insert Function")
{
    l1->insert("a");
    l1->insert("b");
    l1->insert("c");
    l1->insert("e");
    CHECK(l1->toString() == "e->c->b->a->nullptr");
    l1->insert(1, "d");
    CHECK(l1->toString() == "e->d->c->b->a->nullptr");
    l1->insert(0, "f");
    CHECK(l1->toString() == "f->e->d->c->b->a->nullptr");
    CHECK(l1->length() == 6);
}

TEST_CASE("Remove Function")
{
    l1->remove(1);
    CHECK(l1->toString() == "f->d->c->b->a->nullptr");
    l1->remove(0);
    CHECK(l1->toString() == "d->c->b->a->nullptr");
    CHECK(l1->length() == 4);
}

TEST_CASE("Locate Function")
{
    std::string result;
    int i = 0;
    result = l1->get(i);
    CHECK(l1->get(i) == "d");
    i = 1;
    result = l1->get(i);
    CHECK(l1->get(i) == "c");
    i = 4;
    result = l1->get(i);
    CHECK(l1->get(i) == "");
}

TEST_CASE("Destructor")
{
    l1->~List();
    CHECK(l1->toString() == "nullptr");
}

//Test OList
OList *l2 = new OList();

TEST_CASE("Constructor Method OList")
{
    CHECK(l2->toString() == "head->nullptr");
}

TEST_CASE("Insert Function OList")
{
    l2->insert(1);
    l2->insert(2);
    l2->insert(32);
    l2->insert(25);
    CHECK(l2->toString() == "head->1->2->25->32->nullptr");
    l2->insert(-25);
    CHECK(l2->toString() == "head->-25->1->2->25->32->nullptr");
}

TEST_CASE("Remove Function")
{
    l2->remove(1);
    CHECK(l2->toString() == "head->-25->2->25->32->nullptr");
    l2->remove(0);
    CHECK(l2->toString() == "head->2->25->32->nullptr");
}

TEST_CASE("Locate Function")
{
    std::string result;
    int i = 0;
    result = l2->get(i);
    CHECK(l2->get(i) == 2);
    i = 1;
    result = l2->get(i);
    CHECK(l2->get(i) == 25);
    i = 4;
    result = l2->get(i);
    CHECK(l2->get(i) == INT_MIN);
}
TEST_CASE("Contains")
{
    CHECK(l2->contains(2) == true);
    CHECK(l2->contains(10) == false);
}

TEST_CASE("Reverse")
{
    l2->insert(1);
    l2->insert(3);
    l2->insert(4);
    l2->reverse();
    CHECK(l2->toString() == "head->32->25->4->3->2->1->nullptr");
    std::string result;
    int i = 0;
    result = l2->get(i);
    CHECK(l2->get(i) == 32);
    l2->insert(-25);
    CHECK(l2->toString() == "head->-25->32->25->4->3->2->1->nullptr");
}

TEST_CASE("Destructor")
{
    l2->~OList();
     CHECK(l2->toString() == "head->nullptr");
}
