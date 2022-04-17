#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "stack.h"
#include "queue.h"

Stack *s = new Stack();

TEST_CASE("tests 1")
{
    CHECK(s->is_empty() == 1);
    s->push(5);
    s->push(10);
    s->push(15);
    CHECK(s->is_empty() == 0);
    CHECK(s->top() == 15);
    CHECK(s->pop() == 15);
    CHECK(s->top() == 10);
}