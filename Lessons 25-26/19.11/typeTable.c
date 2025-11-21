#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main() {
    printf("%-20s %-20s %-20s %-20s %-20s %-20s\n", "Type", "Size bytes", "Min Value Signed", "Max Value Signed", "Max Value Unsigned", "Min Value Unsigned");
    printf("---------------------------------------------------------------------------------------------------------------------------\n");
    printf("%-20s %-20zu %-20d %-20d %-20u %-20u\n", "char", sizeof(char), SCHAR_MIN, SCHAR_MAX, UCHAR_MAX, 0u);
    printf("%-20s %-20zu %-20d %-20d %-20u %-20u\n", "short", sizeof(short), SHRT_MIN, SHRT_MAX, USHRT_MAX, 0u);
    printf("%-20s %-20zu %-20d %-20d %-20u %-20u\n", "int", sizeof(int), INT_MIN, INT_MAX, UINT_MAX, 0u);
    printf("%-20s %-20zu %-20ld %-20ld %-20lu %-20lu\n", "long", sizeof(long), LONG_MIN, LONG_MAX, ULONG_MAX, 0ul);
    printf("%-20s %-20zu %-20lld %-20lld %-20llu %-20llu\n", "long long", sizeof(long long), LLONG_MIN, LLONG_MAX, ULLONG_MAX, 0ull);
    return 0;

}