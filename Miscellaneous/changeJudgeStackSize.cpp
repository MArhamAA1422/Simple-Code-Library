#include <sys/resource.h>
#include <cerrno>
int main() {
    // add this 3 line;

    struct rlimit rlim; 
    rlim.rlim_cur = 1073741824; // assign number of bytes you need
    setrlimit(RLIMIT_STACK, &rlim);
}