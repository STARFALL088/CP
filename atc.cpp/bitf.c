#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>

typedef struct {
    unsigned a:3;
    unsigned b:2;
}x;
x p={3,2};

int main() {
    printf("%u %u",sizeof(p.a),p.b);
    return 0;
}