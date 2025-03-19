#include <stdio.h>
int function()
{
    static int i = 0;
    i++;
    printf("Hello, World! %d\n", i);
    if (i < 43191){
        function();
    }
    return 0;
}
int main()
{
    function();
    return 0;
}