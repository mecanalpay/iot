#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "lo/lo.h"

int done = 0;

void error(int num, const char *m, const char *path);

int generic_handler(const char *path, const char *types, lo_arg ** argv,
                    int argc, void *data, void *user_data);

int data_handler(const char *path, const char *types, lo_arg ** argv,
                int argc, void *data, void *user_data);

int main()
{
    lo_server_thread st = lo_server_thread_new("9000", error);

    lo_server_thread_add_method(st, NULL, NULL, generic_handler, NULL);

    lo_server_thread_add_method(st, "/lab/data", "ff", data_handler, NULL);

    lo_server_thread_start(st);

    while (!done) {
        usleep(1000);
    }

    lo_server_thread_free(st);

    return 0;
}

void error(int num, const char *msg, const char *path)
{
    printf("Server error %d in path %s: %s\n", num, path, msg);
    fflush(stdout);
}

int generic_handler(const char *path, const char *types, lo_arg ** argv,
                    int argc, void *data, void *user_data)
{
    int i;

    printf("path: <%s>\n", path);
    for (i = 0; i < argc; i++) {
        printf("arg %d '%c' ", i, types[i]);
        lo_arg_pp((lo_type)types[i], argv[i]);
        printf("\n");
    }
    printf("\n");
    fflush(stdout);

    return 1;
}

int data_handler(const char *path, const char *types, lo_arg ** argv,
                int argc, void *data, void *user_data)
{
    printf("%s  xdata:%f, ydata:%f\n", path, argv[0]->f, argv[1]->f);
    fflush(stdout);

    return 0;
}

