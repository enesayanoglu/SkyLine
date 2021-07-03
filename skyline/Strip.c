#include "Strip.h"
#include <stdlib.h>

Strip *Strip_init(int l, int h)
{
    Strip *self = malloc(sizeof(Strip));
    self->left = l;
    self->ht = h;
    return self;
};