#include "calc.h"

// The implementation is far from being the best of the best 
// because the main point of this repo is to learn the new algorithm

const char* string = NULL;

int main()
{
    string = GetInputLine();

    int res = GetG();

    printf ("Got result %d\n", res);
}


int GetG () 
{
    SkipSpaces();

    int val = GetE();

    if (*string == '\0')
    {
        printf ("G: Got termination symbol, ending\n");
        return val;
    }
    else
    {
        printf ("Compilation error at char %c\n", *string);
    }


    return val;
}


int GetE ()
{
    SkipSpaces();

    int val = GetT ();

    while (*string == '+' || *string == '-')
    {
        int last_op = *string;
        string++;
        int cur_val = GetT ();

        if (last_op == '+')
            val += cur_val;
        else
            val -= cur_val;
    }   

    return val;
}


int GetT()
{
    SkipSpaces();

    int val = GetP ();

    while (*string == '*' || *string == '/')
    {
        int last_op = *string;
        string++;
        int cur_val = GetP ();

        if (last_op == '*')
            val *= cur_val;
        else
            val /= cur_val;
    }   

    printf ("T: Passing up %c\n", *string);

    return val;
}


int GetP ()
{
    SkipSpaces();

    int val = 0;

    if (*string == '(')
    {
        string++;

        val = GetE ();
        if (*string != ')') printf ("Missing \')\' - end of subexpression\n");
        
        string++;

        SkipSpaces ();
    }
    else
    {
        val = GetN ();
    }

    return val;
}


int GetN ()
{
    SkipSpaces();

    int val = 0;
    
    const char* OldString = string;

    while ('0' <= *string && *string <= '9')
    {
        val = val*10 + (*string - '0');
        string++;

        SkipSpaces();
    }

    printf ("N: Passing up %c\n", *string);

    return val;
}



char* GetInputLine ()
{
    char* buffer = (char*) calloc (MAX_DEF_SIZE, sizeof (char));

    FILE* input_file = get_file ("data/input.txt", "r");

    fgets (buffer, MAX_DEF_SIZE, input_file);

    fclose (input_file);

    return buffer;   
}


void SkipSpaces ()
{
    while (isspace (*string)) string++;
}