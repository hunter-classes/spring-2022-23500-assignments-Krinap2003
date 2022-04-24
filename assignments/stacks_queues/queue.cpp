#include <iostream>
#include "queue.h"


//Construtor
Queue::Queue(){
    queue = new int[5];
    int head = 0;
    int tail = tail;
    int numAdded = 0;
    int size = 0;

}

//Deconstructor
Queue::~Queue(){
   
    delete[] queue;
    queue = nullptr;
    int head, tail, numAdded = 0;
}


//Add Item to the end of the Queue
void Queue::enqueue(int item){
    if(is_full())
    {
        throw QUEUE_ERR_FULL;
    }
        if(tail > 5)
        {
            tail = tail % 5; 
        }
        queue[tail] = item;
        tail++;
        size++;
        numAdded++;
}


//Removes and returns the first element of the queue
int Queue::sequeue(){

    if(is_empty()){
        throw QUEUE_ERR_EMPTY;
    }

        if(head > 5)
        {
            head = head % 5;
        }
        int temp = queue[head];
        head++;
        numAdded--;
        size--;
        return temp;
}

//Return the first item of the queue doesn't delete
int Queue::front(){
    if(is_empty()){
        throw QUEUE_ERR_EMPTY;
    }
    else{
        return queue[head];
    }
}


//Return True if the queue empty and false otherwise
bool Queue::is_empty(){
    if(head == tail)
    {
        if(numAdded < 1)
        {
            std::cout.setf(std::ios::boolalpha);
            return true;
        }
    }
    std::cout.setf(std::ios::boolalpha);
         return false;
}


//Return True if the queue is full and false otherwise
bool Queue::is_full(){
    //std::cout<<head<<tail<<numAdded<<"\n";
    if((head%5 == tail%5) && numAdded > 0) 
    {
        // if(numAdded > 0)
        // {
            std::cout.setf(std::ios::boolalpha);
            return true;
        //}
    }
    std::cout.setf(std::ios::boolalpha);
    return false;
}


//Print the Queue
std::string Queue::printQueue()
{
    std::string result = "head->";

    if(is_empty())
    {
        return result+"tail";
    }
    // else{
    //      result += "head->";
    //         for(int i = head; i < tail; i++)
    //         {
    //             std::string temp = std::to_string(queue[i]);
    //             result+=temp+"->";
    //         }
    //     result+="tail";
    // }
    
   //return result;

   //std::string result = "head->";
    else if(tail <= head) {
        for (int i = 0; i < size; i++) {
            result += std::to_string(queue[i]);
            result += "->"; 
        }
    }
    else {
        for (int i = head; i < tail; i++) {
            result += std::to_string(queue[i]);
            result += "->";
        }
    }
    result+="tail";
    return result;
}
