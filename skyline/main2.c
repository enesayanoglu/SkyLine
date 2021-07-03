#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Building.h"
#include "SkyLine.h"
// This function returns skyline for a
// given array of buildings arr[l..h].
// This function is similar to mergeSort().
SkyLine* findSkyline(Building arr[], int l, int h)
{

    if (l == h)
    {

        SkyLine *res = SkyLine_init(2);

        SkyLine_append(res, Strip_init(arr[l].left, arr[l].ht));
        SkyLine_append(res, Strip_init(arr[l].right, 0));
        return res;
    }

    int mid = (l + h) / 2;

    // Recur for left and right halves
    // and merge the two results
    SkyLine *sl = findSkyline(
        arr, l, mid);
    SkyLine *sr = findSkyline(
        arr, mid + 1, h);

    SkyLine *res = SkyLine_merge(sl, sr);

    // Return merged skyline
    return res;
}

int main()
{

    FILE *fp;
    int scanned = 0;
    int coord;
    int height;
    int width;
    fp = fopen("input.txt", "r");
    int i = 0;
    Building arr[6];
    while ((scanned = fscanf(fp, "%d %d %d", &coord, &height, &width)) != EOF)
    {
        arr[i].left = coord;
        arr[i].ht = height;
        arr[i].right = coord + width;
        i++;
    }
    int n = sizeof(arr) / sizeof(arr[0]);
    // Find skyline for given buildings
    // and print the skyline

    SkyLine *ptr = findSkyline(arr, 0, n - 1);
    printf("Skyline for given buildings is \n");
    SkyLine_print(ptr);
    return 0;
}
