/*********************
**  Color Map generator
** Skeleton by Justin Yokota
**********************/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>
#include <string.h>
#include "ColorMapInput.h"


/**************
**This function reads in a file name colorfile.
**It then uses the information in colorfile to create a color array, with each color represented by an int[3].
***************/
int** FileToColorMap(char* colorfile, int* colorcount)
{
    FILE *fp;
    fp = fopen(colorfile, "r");
    if(fp == NULL) return NULL;

    fscanf(fp, "%d", colorcount);
    int **res = (int**) malloc((*colorcount)*sizeof(int*));
    for(int i=0; i<*colorcount; i++){
        res[i] = (int*) malloc(3*sizeof(int));
    }
    for(int i=0; i<*colorcount; i++){
        fscanf(fp, "%d %d %d", &res[i][0], &res[i][1], &res[i][2]);
    }
    fclose(fp);
    return res;
//    uint8* output[*colorcount];
//    char line[256];
//    while ((fgets(line, 256, fp))) {
//        printf("%s", line);
//    }
	//YOUR CODE HERE
}
//int main(int argc, char* argv[]){
//    char* colorfile;
//    colorfile = "defaultcolormap.txt";
//    int colorcount;
//    colorcount = 0;
//    printf("1 : %s\n", colorfile );
//    FileToColorMap(colorfile, &colorcount);
//}


