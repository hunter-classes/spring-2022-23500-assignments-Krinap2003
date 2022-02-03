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

int main()
{
    
    std::cout<<stepPerm(1)<<std::endl;
    std::cout<<stepPerm(2)<<std::endl;
    std::cout<<stepPerm(3)<<std::endl;
    std::cout<<stepPerm(5)<<std::endl;
    std::cout<<stepPerm(10)<<std::endl;
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

