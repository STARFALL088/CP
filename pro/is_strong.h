#include "function.h"


int isStrongPassword(const char *password)
{
    int len = strlen(password);
    int hasUpper = 0, hasLower = 0, hasDigit = 0, hasSpecial = 0;

    if (len < 8)
        return 0;

    for (int i = 0; i < len; i++)
    {
        if (isupper(password[i]))
            hasUpper = 1;
        if (islower(password[i]))
            hasLower = 1;
        if (isdigit(password[i]))
            hasDigit = 1;
        if (!isalnum(password[i]))
            hasSpecial = 1;
    }

    return (hasUpper && hasLower && hasDigit && hasSpecial);
}