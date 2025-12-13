#include "auth.c"

int test_auth_functions_exist()
{
    int success = 1;
    {
        printf("Test 1 - userSignup exists: ");
        void (*ptr1)() = userSignup;
        if (ptr1 != NULL) {
            printf("PASS\n");
        } else {
            printf("FAIL\n");
            success = 0;
        }
    }
    
    
    {
        printf("Test 2 - changePassword exists: ");
        void (*ptr2)() = changePassword;
        if (ptr2 != NULL) {
            printf("PASS\n");
        } else {
            printf("FAIL\n");
            success = 0;
        }
    }
    
    return success;
}

int main()
{
    test_auth_functions_exist();
    return 0;
}