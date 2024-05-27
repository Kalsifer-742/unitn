bool equal_string(char str1[], char str2[]);

bool equal_string(char str1[], char str2[])
{;
    if (string_length(str2) != string_length(str1))
    {
        return false;
    }
    
    bool result = true;
    for (int i = 0; i < string_length(str1); i++)
    {
        if (str1[i] != str2[i])
        {
            result = false;
        }
        
    }
    return result;
}