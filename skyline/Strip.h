// A strip in skyline
typedef struct
{
    // x coordinate of left side
    int left;

    // height
    int ht;
} Strip;

Strip *Strip_init(int l, int h);