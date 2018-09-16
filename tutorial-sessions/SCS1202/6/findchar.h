void find_char(char *sp, char ch_cpy)
   /* address of string str copied into sp, pointer to string */
{
    char ch;
 
    while ( (ch = *sp++) != '\0' && ch != ch_cpy)
        ;
 
    if (ch_cpy == ch )
        printf("Character \"%c\" is found!\n", ch_cpy);
    else
        printf("Character \"%c\" isn't found!\n", ch_cpy);
}
