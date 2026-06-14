#include <stdio.h>
int i;
int main() {
    for (int i = 0; i <= 10; i++) {
        printf("%d\n", i);
    }
    if (i > 10) {
        printf("i is less than 2\n");
    }
    else if (i > 2) {
        printf("i is between 2 and 5\n");
    }
    else {
        printf("i is greater than or equal to 2\n");
    }
    i =6;

    switch (i) {
        case 1 :
            printf("i is 1\n");
            break;
        case 2 :
            printf("i is 2\n");
            break;
        case 3 :
            printf("i is 3\n");
            break;
        case 4 :
            printf("i is 4\n");
            break;
        case 5 :
            printf("i is 5\n");
            break;
          case 6 :
            printf("i is 6\n");
             
        case 7 :
            printf("i is 7\n");
            
        case 8 :
            printf("i is 8\n");
            
        case 9 :
            printf("i is 9\n");
            break;
        case 10 :
            printf("i is 10\n");
            break;
        default:
            printf("i is not between 1 and 10\n");
    }   


    return 0;
}