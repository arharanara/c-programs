#include <stdio.h>
#include <assert.h>

void print_stars(int n);
void flush_input();

int main()
{
    int n;

    do {
        printf("Enter the number of stars to be printed (or -1 to finish): ");
        int ret = scanf("%d", &n);

        if (ret == 0) {
            puts("Cannot read input: incorrect data type specified. Please try again");
            flush_input();
            continue;
        } else if (n < -1) {
            puts("Cannot be printed negative amount of stars. Please try again");
            continue;
        } else if (n == -1) {
            puts("Program execution is finished");
            break;
        }

        int isEven = !(n % 2);
        int m = isEven ? (n / 2) : (n / 2 + 1);

        int i = 1;
        for (; i <= m; ++i)
            print_stars(i);

        i = isEven ? m : (m - 1);
        for (; i > 0; --i)
            print_stars(i);
    } while (1);

    return 0;
}

void print_stars(int n)
{
    assert(n > 0);

    for (int i = 0; i < n; ++i)
        putchar('*');

    putchar('\n');
}

void flush_input()
{
    char c;
    while ((c = getchar()) != '\n' && c != EOF);
}
