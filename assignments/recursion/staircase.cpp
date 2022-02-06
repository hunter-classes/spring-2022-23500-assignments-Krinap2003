#include <iostream>
#include "string"


/*
Created three based cased with 1 two and three becuase he can only
climb these 1 2 or 3 staircase at a time than called the fucntion with 
the paremeter in decrementation of 1 2 and 3 so when eventually it reaches
the base case it will add the number of way he can clim the stairs.
 */
int stepPerm(int n)
{
    //base case
    if(n==1){
        return 1;
    }
    //base case
    if(n==2) {
        return 2;
    }
    //base case
    if(n==3) {
        return 4;
    }
    else{
        return stepPerm(n-3)  + stepPerm(n-2) + stepPerm(n-1);
    }
}

// int ways(int steps)
// {
//     if(steps == 0)
//     {
//         return 1;
//     }
//     int w = 0;
//     for (int i = 3; i >= 1; i--)
//     {
//         int r = steps -i;
//         if(r>=0)
//         w = w + ways(r);
//     }
//    return w;
// }

int fibtable[10000];
int fib_dyn(int n){

   if(n==1){
        return 1;
    }
    //base case
    if(n==2){
        return 2;
    }
    //base case
    if(n==3){
        return 4;
    }else if (fibtable[n] != 0){
    return fibtable[n];
    }else {
    int tmp = fib_dyn(n-1) + fib_dyn(n-2) + fib_dyn(n-3);
    fibtable[n]=tmp;
    return tmp;
  }
}

int main()
{
    
    std::cout<<stepPerm(1)<<std::endl;
    std::cout<<stepPerm(2)<<std::endl;
    std::cout<<stepPerm(3)<<std::endl;
    std::cout<<stepPerm(5)<<std::endl;
    std::cout<<stepPerm(10)<<std::endl;
    std::cout<<stepPerm(7)<<std::endl;
    //std::cout<<stepPerm(7000)<<std::endl;

    std::cout<<"\n";
    std::cout<<fib_dyn(1)<<std::endl;
    std::cout<<fib_dyn(2)<<std::endl;
    std::cout<<fib_dyn(3)<<std::endl;
    std::cout<<fib_dyn(5)<<std::endl;
    std::cout<<fib_dyn(10)<<std::endl;
    std::cout<<fib_dyn(7)<<std::endl;
    std::cout<<fib_dyn(7000)<<std::endl;
    return 0;
}




//n=5
// 1 1 1 1 1
// 1 1 1 2
// 1 1 2 1 
// 1 2 1 1
// 2 1 1 1
// 1 2 2
// 2 2 1
// 2 1 2
// 1 1 3
// 1 3 1
// 3 1 1
// 2 3
// 3 2

