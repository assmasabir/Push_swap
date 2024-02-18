#include "push_swap.h"

static int ft_int_length(long value)
{
    int l;

    l = 1;
    if (value < 0)
    {
        value *= (-1);
        l += 1;
    }
    while (value > 9)
    {
        l++;
        value /= 10;
    }
    return (l);
}

void show(stack *a, stack *b, int clear)
{
    int i;
    int j;
    node *tmpa = a->head;
    node *tmpb = b->head;

    i = tmpa->capacity;

    if (i > 100 || i < 0)
        i = tmpb->capacity;
    int k = ft_lstsize(a);
    int l = ft_lstsize(b);

    printf("\033[0;37m");
    printf("_________________________\n");
    while (tmpa || tmpb)
    {
        if (tmpa && 0 <= i && i <= k)
        {
            // if (stack->a[i] == stack->sorted[i])
            printf("|\033[0;32m");
            // else if (stack->a[i] != stack->sorted[i])
            // printf("|\033[0;31m");
            printf("%d", tmpa->value);
            j = ft_int_length(tmpa->value);
            while (j < 11)
            {
                printf(" ");
                j++;
            }
            tmpa = tmpa->next;
        }
        else
            printf("|           ");
        printf("\033[0;37m");
        if (tmpb && 0 <= i && i <= l)
        {
            printf("|\033[0;33m");
            printf("%d", tmpb->value);
            j = ft_int_length(tmpb->value);
            while (j < 11)
            {
                printf(" ");
                j++;
            }
            printf("\033[0;37m|\n");
            tmpb = tmpb->next;
        }
        else
            printf("|           |\n");
        i--;
    }
    printf("|-----------------------|\n");
    printf("|a          |b          |\n");
    printf("|-----------------------|\n");
    usleep(1000);
    if (clear)
    {
        // getchar();
        system("clear");
    }
}
