#include "Strip.h"
#define max(a, b)                   \
    (                               \
        {                           \
            __typeof__(a) _a = (a); \
            __typeof__(b) _b = (b); \
            _a > _b ? _a : _b;      \
        })

// Skyline: To represent Output(An array of strips)
typedef struct
{
    // Array of strips
    Strip *arr;

    // Capacity of strip array
    int capacity;

    // Actual number of strips in array
    int n;
} SkyLine;

int SkyLine_count(SkyLine *self);

SkyLine *SkyLine_init(int cap);

void SkyLine_append(SkyLine *self, Strip *st);

void SkyLine_print(SkyLine *self);

SkyLine *SkyLine_merge(SkyLine *self, SkyLine *other);