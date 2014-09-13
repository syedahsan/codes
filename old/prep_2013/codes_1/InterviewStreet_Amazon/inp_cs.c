#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define N 200

int main()
{
        int i, j;

        srand(time(NULL));
        FILE *fd = fopen("inp_cs.txt", "w");
        fprintf(fd, "1\n%d\n", N);
        for (i = 0; i < N; ++i) {
                for (j = 0; j < N; ++j)
                        fprintf(fd, "%d ", rand()%2);
                fprintf(fd, "\n");
        }
        fclose(fd);

        return 0;
}

