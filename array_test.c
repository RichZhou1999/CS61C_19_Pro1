//
// Created by 周毅华 on 2022/11/30.
//
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>


#include <stdbool.h>

bool getIntHandle(unsigned handleId, int **handle)
{
    static int handles[] = {12, 23, 34, 45};
    static int x = 10;
    bool success = (handleId < sizeof(handles)/sizeof(handles[0])); // Check that handleId is in range
//    if(success)
//    {
//        *handle = &handles[handleId];
//    }
//    *handle = &handles[0];
//    *(handle+1) = &handles[1];
//    *(handle+2) = &handles[2];
//    *handle[0] = 10;
//    *handle[1] = 11;
    *handle[0] = 10;
//    *(handle+1) = 11;
//    printf("%d \n",**handle);
    return success;
}

int main(void)
{
//    int* handle[3];
    int* handle = malloc(3*sizeof(int));
    handle[2] = 20;
    *(handle +1 ) = 11;
//      int handle[3];
//    int*
//      handle[0] = 0;
//      handle[1] = 1;
    bool success = getIntHandle(2, &handle); // Get a pointer to the integer at index 2
    printf("*handle = %d \n", handle[0]);
//    printf("*handle = %d \n", *handle);
    return 0;
}