
#include <bits/stdc++.h>
using namespace std;

int main(){

    int i = 0,j = 0;int n = 10;
    int t = 0;

    srand(time(NULL));


    while(n > 0){

        cout << "Sending the frame" << i << endl;

        t = rand() % 10;

        if (x == 0) {
            printf("\nFrame delayed. Resending frame %d", i);
            x = rand() % 10;
        }

        cout << "Ack recieved" << j << endl;

        n--;
        i++;
        j++;
    }

    printf("\nEnd of Stop-and-Wait protocol\n");
    return 0;
}
