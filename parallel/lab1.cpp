#include <stdio.h>
#include <omp.h>

int main(int argc, char *argv[])
{

    // #pragma omp parallel
    //     {
    //         int nthreads, thread_id;
    //         nthreads = omp_get_num_threads();
    //         thread_id = omp_get_thread_num();
    //         printf("Hello OpenMP \n");
    //         printf("I have %d thread(s) and my thread id is %d\n", nthreads, thread_id);
    //     }

    int sum = 0;
#pragma omp parallel for reduction(+ : sum)
    for (int i = 0; i < 80; i++)
    {
        sum = sum + i;
    }
    printf("sum:%d", sum);
}
// export OMP_NUM_THREADS=4