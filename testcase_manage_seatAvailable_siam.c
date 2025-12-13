#include "manage.c"

int test_seat_available_nobooking()
{
    int actual = isSeatAvailable(2);
    int expected = 1;  
    int success = actual == expected;

    printf("expected: %d, actual: %d, success: %d\n", expected, actual, success);
    return success;
}

int test_invalid_seat_check()
{
    int actual = isSeatAvailable(100);  
    int expected = 0; 
    int success = actual == expected;

    printf("expected: %d, actual: %d, success: %d\n", expected, actual, success);
    return success;
}

int main()
{
    test_seat_available_nobooking();
    test_invalid_seat_check();
    return 0;
}