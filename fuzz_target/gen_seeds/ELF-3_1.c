
#include <stdio.h>
#include <dlfcn.h>

int main() {
    void (*hello)();

    // Load the shared library
    void* handle = dlopen("./tmp/libshared.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Get the function address from the shared library
    hello = dlsym(handle, "hello_from_shared_lib");
    if (!hello) {
        fprintf(stderr, "%s\n", dlerror());
        return 1;
    }

    // Call the function from the shared library
    (*hello)();

    // Close the shared library
    dlclose(handle);

    return 0;
}
