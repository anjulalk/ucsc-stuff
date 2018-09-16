void write_table(int copy)    /* num copied into copy */
{
    int i;
 
    printf("\tTable of %d\n", copy);
    for (i = 1; i <= 10; i++)
        printf("%5d * %5d = %5d\n", copy, i, copy * i);
 
    printf("\n");
}
