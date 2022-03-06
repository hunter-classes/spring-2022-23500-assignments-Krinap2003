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
    l2->insert(3);
    l2->insert(5);
    CHECK(l2->toString() == "head->5->3->2->1->nullptr");
}
