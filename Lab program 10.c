#include <stdio.h>

#define m 10

int ht[m];

void init()
{
    int i;
    for(i = 0; i < m; i++)
        ht[i] = -1;
}

void insert(int key)
{
    int index = key % m;
    int start = index;

    while(ht[index] != -1)
    {
        index = (index + 1) % m;
        if(index == start)
        {
            printf("hash table is full\n");
            return;
        }
    }
    ht[index] = key;
}

void display()
{
    int i;
    printf("\nhash table contents:\n");
    for(i = 0; i < m; i++)
        printf("address %d : %d\n", i, ht[i]);
}

int main()
{
    int n, key, i;

    init();

    printf("enter number of employee records: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("enter 4-digit key: ");
        scanf("%d", &key);
        insert(key);
    }

    display();

    return 0;
}

