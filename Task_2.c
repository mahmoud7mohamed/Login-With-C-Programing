#include <stdio.h>
#include<windows.h>


struct User {
    char username[20];
    char password[20];
    int activeFlag;
};

union Flag {
    int value;
    struct {
        unsigned int flag1 : 1;
        unsigned int flag2 : 1;
        unsigned int flag3 : 1;
        unsigned int flag4 : 1;
    } flags;
};

int main() {

    system("color 0b"); // color off the background and font color 

    struct User user;
    union Flag flag;

    // Registration
    printf("\n\n------####------Registration------####------\n\n");
    printf("- Enter username: ");
    scanf("%s", user.username);
    printf("- Enter password: ");
    scanf("%s", user.password);
    printf("- Set active flag (0 or 1): ");
    scanf("%d", &user.activeFlag);

    //choose flag value
    printf("- Set flag value (0-1): ");
    scanf("%d", &flag.value);

    //Login
    printf("\nLogin\n");
    printf("- Enter username: ");
    scanf("%s", user.username);
    printf("- Enter password: ");
    scanf("%s", user.password);

    if (user.activeFlag == 1 && (flag.flags.flag1 == 1 , flag.flags.flag2 == 1 , flag.flags.flag3 == 1 || flag.flags.flag4 == 1)) {
        printf(" Login successful.\n");
    } else {
        printf(" Login failed.\n");
    }

    return 0;
}
