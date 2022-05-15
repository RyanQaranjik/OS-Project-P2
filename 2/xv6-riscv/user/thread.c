#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int base, limit;

void f(void *arg) {
    base++;
    if (base == limit)
        return;
    thread_creator(&f, (void *) 0);
    printf("[ID] %d => %d\n", thread_id(), base);
}

int
main(int argc, char *argv[]) {
//    base = atoi(argv[1]);
//    limit = atoi(argv[2]);
    base = 1;
    limit = 5;
    thread_creator(&f, (void *) 0);
    exit(0);
}
