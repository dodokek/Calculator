#include "calc.h"

int main()
{
    char* string = GetInputLine ();

    GetN (&string);

    printf ("Got string %s\n", string);
}


int GetN (char** string)
{
    int val = 0;
    
    const char* OldString = *string;
}



char* GetInputLine ()
{
    char* buffer = (char*) calloc (MAX_DEF_SIZE, sizeof (char));

    FILE* input_file = get_file ("data/input.txt", "r");

    fgets (buffer, MAX_DEF_SIZE, input_file);

    fclose (input_file);

    return buffer;   
}