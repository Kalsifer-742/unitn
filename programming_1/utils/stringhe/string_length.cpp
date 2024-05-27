int string_length(const char string[]);

int string_length(const char string[])
{
    int i;
    for (i = 0; string[i] != '\0'; i++){}
    return i;
}