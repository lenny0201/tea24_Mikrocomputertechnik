#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int main(int argc, char **argv) {

    int var = 4711;


    /**
     * The {fmt} lib is a cross platform library for printing and formatting text
     * it is much more convenient than std::cout and printf
     * More info at https://fmt.dev/12.0/api/
     */
    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);
    fmt::print("Value of var:, {}!\n", var);
    fmt::println("Value of argc:, {}!\n", argc);

    /* Teil 1*/
    int x = 10; 

    int* p = &x;

    fmt::print("Wert von x: {}, Adresse von x: {}\n", x, fmt::ptr(&x));

    fmt::print("Wert auf den p zeigt (*p): {}, Adresse in p: {}\n", *p, fmt::ptr(p));

    *p = 42;

    fmt::print("Neuer Wert von x: {}, Neuer Wert auf den p zeigt (*p): {}\n", x, *p);

    /*Teil 2*/

    return 0; /* exit gracefully*/
}
