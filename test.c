// (c)bitwise studio

#include <stdio.h>
#include <stdlib.h>
#include "lcg.h"


int main(int argc, char** argv)
{
    printf("Created by (c)bitwise studio\n");

    if (argc < 4)
    {
        printf("<%s> <min> <max> <frequency>\n", argv[0]);
        return -1;
    }

    struct Rand rand;
    struct Seed seed = { 1 };
    rand.seed = seed;
    rand.multiplier = RAND_MUL;
    rand.increment = RAND_INC;
    rand.frequency = atoi(argv[3]);
    rand.min = atoll(argv[1]);
    rand.max = atoll(argv[2]);

    lli* random_number_list = random_list(&rand);

    for (int i = 0; i < rand.frequency; i++)
    {
        printf("%lli\n", *(random_number_list + i));
    }

    free(random_number_list);

    return 0;
}
