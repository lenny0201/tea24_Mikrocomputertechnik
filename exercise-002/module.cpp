#include "module.h"

#include <fmt/format.h>

static int moduleCounter;        // nicht initialisiert -> automatisch 0 -> .bss
static int moduleValue = 123; 

static const int moduleConst = 77; // initialisiert -> .data

/* .bss Segment */
int foo;
int foo2 = 0;

/* .data Segment */
int data = 45;
int data2 = 43;

/* .rodata Segment */

const int rodata = 45;
const int rodata2 = 43;

const int big_data_blob[] = {42,0xff};

void doSomething(int value)
{
    value = value + 1;
    fmt::print("doSomething, value {}\n", value);
}

void doSomethingPtr(int* ptr)
{
    *ptr = *ptr + 1;
    fmt::print("doSomethingPtr, value {}\n", *ptr);
}

int* doReturnAPtr()
{
    int value = 4711;
    fmt::print("doReturnAPtr, value {}\n", value);
    /* 
     * This causes a warning and shall be avoided by all means
     * warning: address of stack memory associated with local variable 'value' returned [-Wreturn-stack-address]
     */
    return &value;
}

void doSomethingStatic()
{
    static int value = 56;      // statisch: einmal initialisiert, lebt bis Programmende
    int localValue = 56;        // nicht-statisch: bei jedem Aufruf neu auf dem Stack

    value = value + 1;
    localValue = localValue + 1;

    fmt::print("doSomethingStatic, static value {}  address {}\n", value, fmt::ptr(&value));
    fmt::print("doSomethingStatic, local  value {}  address {}\n", localValue, fmt::ptr(&localValue));
}

void printModuleStatics()
{
    moduleCounter = moduleCounter + 1;

    fmt::print("moduleCounter {}  address {}\n", moduleCounter, fmt::ptr(&moduleCounter));
    fmt::print("moduleValue   {}  address {}\n", moduleValue, fmt::ptr(&moduleValue));

    fmt::print("moduleConst   {}  address {}\n", moduleConst, fmt::ptr(&moduleConst));
}
