#include "SkyLine.h"

#include <stdio.h>
#include <stdlib.h>

int SkyLine_count(SkyLine *self)
{
    return self->n;
}

SkyLine *SkyLine_init(int cap)
{
    SkyLine *self = malloc(sizeof(SkyLine));
    self->capacity = cap;
    self->arr = malloc(cap * sizeof(Strip));
    self->n = 0;
    return self;
}

void SkyLine_append(SkyLine *self, Strip *st)
{
    // Check for redundant strip, a strip is
    // redundant if it has same height or left as previous
    if (self->n > 0 && self->arr[self->n - 1].ht == st->ht)
        return;
    if (self->n > 0 && self->arr[self->n - 1].left == st->left)
    {
        self->arr[self->n - 1].ht = max(self->arr[self->n - 1].ht, st->ht);
        return;
    }
    self->arr[self->n] = *st;
    self->n++;
}

void SkyLine_print(SkyLine *self)
{
    for (int i = 0; i < self->n; i++)
    {
        printf("(%d, %d),", self->arr[i].left, self->arr[i].ht);
    }
}

SkyLine *SkyLine_merge(SkyLine *self, SkyLine *other)
{

    // Create a resultant skyline with
    // capacity as sum of two skylines
    SkyLine *res = SkyLine_init(
        self->n + other->n);

    // To store current heights of two skylines
    int h1 = 0, h2 = 0;

    // Indexes of strips in two skylines
    int i = 0, j = 0;
    while (i < self->n && j < other->n)
    {
        // Compare x coordinates of left sides of two
        // skylines and put the smaller one in result
        if (self->arr[i].left < other->arr[j].left)
        {
            int x1 = self->arr[i].left;
            h1 = self->arr[i].ht;

            // Choose height as max of two heights
            int maxh = max(h1, h2);

            SkyLine_append(res, Strip_init(x1, maxh));
            i++;
        }
        else
        {
            int x2 = other->arr[j].left;
            h2 = other->arr[j].ht;
            int maxh = max(h1, h2);
            SkyLine_append(res, Strip_init(x2, maxh));
            j++;
        }
    }

    // If there are strips left in this
    // skyline or other skyline
    while (i < self->n)
    {
        SkyLine_append(res, &self->arr[i]);
        i++;
    }
    while (j < other->n)
    {
        SkyLine_append(res, &other->arr[j]);
        j++;
    }
    return res;
}