#include <stdio.h>
#include <assert.h>

char SizeOfTShirt(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

int main() {
    //Standard T-shirt size based on chest measurement 
    // S - 38, M - 40, L - 42, XL - 44, XXL - 46, 3XL - 48, 4XL - 50
    assert(SizeOfTShirt(38) == 'S');
    assert(SizeOfTShirt(42) == 'L');
    assert(SizeOfTShirt(39) == 'S'); 
    //Give -1 in hex as test to check,if it still prints S, as negative size doesn't exist
    assert(SizeOfTShirt(0x80000001) == '\0');
    //Give unreasonably large value and expect error, here 2^31, and keep sign bit as 0
    assert(SizeOfTShirt(0x7FFFFFFF) == '\0');
    //Give unreasonably small number and expect error, here 2^31 and 1 for sign bit
    assert(SizeOfTShirt(0xFFFFFFFF) == '\0');
    assert(SizeOfTShirt(0x8FFFFFFF) == '\0');
    #if 0
    assert(SizeOfTShirt(37) == 'S');
    assert(SizeOfTShirt(40) == 'M');
    assert(SizeOfTShirt(43) == 'L');
    #endif
    printf("All is well (maybe!)\n");
    return 0;
}
