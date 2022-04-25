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


Queue *q1 = new Queue();


TEST_CASE("enqueue")
{
    CHECK(q1->is_empty() == true);
    CHECK(q1->is_full() == false);
    q1->enqueue(1);
    q1->enqueue(2);
    q1->enqueue(3);
    CHECK(q1->printQueue() == "head->1->2->3->tail");
    CHECK(q1->front() == 1);
    q1->enqueue(4);
    q1->enqueue(5);
    CHECK(q1->printQueue() == "head->1->2->3->4->5->tail");
    CHECK(q1->front() == 1);
    CHECK(q1->is_full() == true);
    try{
         q1->enqueue(6);
    }
    catch(int e)
    {
        CHECK(e == 2);
    }
}

TEST_CASE("sequeue"){
    q1->sequeue();
    CHECK(q1->front() == 2);
    CHECK(q1->printQueue() == "head->2->3->4->5->tail");
    q1->sequeue();
    CHECK(q1->printQueue() == "head->3->4->5->tail");
    CHECK(q1->is_empty() == false);
    CHECK(q1->is_full() == false);
    q1->sequeue();
    q1->sequeue();
    q1->sequeue();
    CHECK(q1->printQueue() == "head->tail");
    try{
        q1->sequeue();
    }
    catch(int e){
        CHECK(e == 1);
    }
    q1->enqueue(1);
    CHECK(q1->front() == 1);
    CHECK(q1->printQueue() == "head->1->tail");
    q1->enqueue(2);
    q1->enqueue(3);
    CHECK(q1->printQueue() == "head->1->2->3->tail");
}







