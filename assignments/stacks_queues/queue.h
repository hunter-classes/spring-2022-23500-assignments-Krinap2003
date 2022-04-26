#pragma once
#include <iostream>
#define QUEUE_ERR_EMPTY 1
#define QUEUE_ERR_FULL 2
#define QUEUE_ERR_OTHER 4

class Queue{
    private:
        int* queue;
        int head,tail, numAdded, size;
 public:

    Queue();
    ~Queue();
    void enqueue(int item);
    int sequeue();
    int front();
    bool is_empty();
    bool is_full();
    std::string printQueue();
};