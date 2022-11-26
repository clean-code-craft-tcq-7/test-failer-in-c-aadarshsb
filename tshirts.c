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
    assert(SizeOfTShirt(-1) != 'S');
    assert(SizeOfTShirt(0x8FFFFFFF) != 'L');
    assert(SizeOfTShirt(0xFFFFFFFF) != 'S');
    assert(SizeOfTShirt(1) !='S');
    #if 0
    assert(SizeOfTShirt(37) == 'S');
    assert(SizeOfTShirt(40) == 'M');
    assert(SizeOfTShirt(43) == 'L');
    #endif
    printf("All is well (maybe!)\n");
    return 0;
}
