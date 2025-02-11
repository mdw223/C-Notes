// Demonstration of alternatives for how
// to allocate and initialize an array.

#include <stdio.h>

int main()
{
    // A literal string evaluates to a (constant) char pointer.
    // You can index off this pointer, like any other pointer.
    char c = "abcdefg"[4];
    printf("%c\n", c);

    // This gives us two common ways to initialize
    // string variables.

    // Really make a new array.
    char str1[] = "abc123";

    // Just copy a pointer to a literal string.
    char* str2 = "abc123";

    // Since str1 and str2 both look like pointers, we can often use
    // these as if they are equivalent (but they're not).
    printf("%s\n", str1);
    printf("%s\n", str2);

    // We can use similar syntax to initialize other array types (but
    // literal strings have special support in C that other arrays don't)
    int list1[] = { 5, 10, 15, 20 };
    int* list2 = (int[]) { 7, 14, 21, 28 };

    // Here also, we can use these as if they're the same.
    for (int i = 0; i < 4; i++)
        printf("%d\n", list1[i]);

    for (int i = 0; i < 4; i++)
        printf("%d\n", list2[i]);

    // But they're not the same.  list1 is an array, list2 is a pointer.
    printf("%zd %zd\n", sizeof(list1), sizeof(list2));
    /* list1 is 16 bytes because each integer is 4 bytes (4 elements * 4 bytes = 16 bytes)
     */
    /*  list2 is 8 bytes
    The size of a pointer in C depends on the architecture of the system it is running on.
    On a 32-bit system, a pointer typically takes up 4 bytes, while on a 64-bit system, it usually takes up 8 bytes.
    This is because a pointer needs to be large enough to store the memory address of any location in the system's address space.
    A 32-bit system has a 32-bit address space, which means it can address 2^32 bytes of memory.
    A 64-bit system has a 64-bit address space, which means it can address 2^64 bytes of memory.
    */
}
