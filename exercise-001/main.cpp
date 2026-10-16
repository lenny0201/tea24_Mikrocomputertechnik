#include <fmt/chrono.h>
#include <fmt/format.h>

#include "config.h"

int globalVar = 1;
int globalVar1;
int globalVar3 = NULL;
static int globalVar4 = 69;
const int globalVar5 = 6767;

void foo() { fmt::print("Hello from foo!\n"); }

int main(int argc, char **argv) {

    int localVar = 2;
    static int localVarstat = 3;
    const int localVarconst = 4;

    int* heapVar = new int(3);

    fmt::print("Hello, {}!\n", tea::PROJECT_NAME);

    fmt::print("Adresse von foo: {}\n", fmt::ptr(&foo));

    fmt::print("The Value of heapVar is: {}, The Adress of heapVar is: {}\n", *heapVar, fmt::ptr(&heapVar));
    fmt::print("The Value of localVar is: {}, The Adress of localVar is: {}\n",localVar,  fmt::ptr(&localVar));
    fmt::print("The Value of localVarstat is: {}, The Adress of localVarstat is: {}\n",localVarstat,  fmt::ptr(&localVarstat));
    fmt::print("The Value of localVarconst is: {}, The Adress of localVarconst is: {}\n",localVarconst,  fmt::ptr(&localVarconst));
    fmt::print("The Adress of globalVar is: {}\n", fmt::ptr(&globalVar));
    fmt::print("The Adress of globalVar is: {}\n", fmt::ptr(&globalVar1));
    fmt::print("The Adress of globalVar is: {}\n", fmt::ptr(&globalVar3));
    fmt::print("The Adress of globalVar is: {}\n", fmt::ptr(&globalVar4));
    fmt::print("The Adress of globalVar is: {}\n", fmt::ptr(&globalVar5)); /*Alle adressen beginnen auf 0x5e866c03*/

    delete heapVar;
    return 0; /* exit gracefully*/
}
