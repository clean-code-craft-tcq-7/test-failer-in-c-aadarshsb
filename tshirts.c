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
    //Give -1 in hex as test to check,if it still prints S, as negative size doesn't exist
    assert(SizeOfTShirt(0x80000001) != 'S');
    //Give unreasonably large value and expect error, here 2^31, and keep sign bit as 0
    assert(SizeOfTShirt(0x7FFFFFFF) != 'L');
    //Give unreasonably small number and expect error, here 2^31 and 1 for sign bit
    assert(SizeOfTShirt(0xFFFFFFFF) != 'S');
    assert(SizeOfTShirt(0x8FFFFFFF) != 'S');
    #if 0
    assert(SizeOfTShirt(37) == 'S');
    assert(SizeOfTShirt(40) == 'M');
    assert(SizeOfTShirt(43) == 'L');
    #endif
    printf("All is well (maybe!)\n");
    return 0;
}
