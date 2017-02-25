#include <stdio.h>
#include <assert.h>

void print_stars(int n);

int main() 
{
    int n;

    int counter = 0;
    do {
        printf("%s", "Enter an any number (or -1 to finish): ");
        scanf("%d", &n);
        printf("Entered number: %d\n", n);

        if (n == -1) {
            printf("%s\n", "-1 was entered. Execution of program is finished");
            break;
        } else if (n < 0) {
            printf("%s\n", "Entered number is negative. Cannot print stars");
            continue;
        }

        int isEven = !(n % 2);  // !0 = 1; !1 = 0
        if (isEven)
            printf("%s\n", "Entered number is even");
        else
            printf("%s\n", "Entered number is odd");

        int m = isEven ? (n / 2) : (n / 2 + 1);

        int i = 1;
        for (; i <= m; ++i)
            print_stars(i);

        i = isEven ? m : (m - 1);
        for (; i > 0; --i)
            print_stars(i);
        counter++;
    } while (counter < 5);  // zero = false; any non zero number = true

    return 0;
}

void print_stars(int n)
{
    assert(n > 0);

    for (int i = 0; i < n; ++i)
        putchar('*');

    putchar('\n');
}
