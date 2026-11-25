
#include <stdio.h>
#include <string.h>
//Character stuffing - 1c
int main() {
    int n;
    printf("max no of strings : ");

    scanf("%d",&n);

    int maxframe[n];

    for(int i=0;i<n;i++){
        printf("max frame size of maxframe[%d]",i);

        scanf("%d",&maxframe[i]);

    }


    int s[n][100];

    for(int i=0;i<n;i++){

         do {
            printf("Enter content for frame %d: ", i + 1);
            scanf("%99s", s[i]);

            if (strlen(s[i]) > maxframe[i])
                printf("String exceeds maximum size! Enter again.\n");

        } while (strlen(s[i]) > maxframe[i]);

    }


    for(int i=0;i<n;i++){

        printf("length of string %s",s[i]);

        cout << strlen(s) << endl;
    }


}
