#include <bits/stdc++.h>

using namespace std;

int main(){
    int n, w;

    cin >> n;
    cin >> w;

    int ack = 0;
    int sent = 0;

    while(sent < n){

        for(int i=sent;i<w+sent;i++){

            cout << "tranmitted bits from" << sent  << "to" << i << endl;
        }


        printf("Enter last ACK received (%d to %d): ",sent, sent + i - 1);
        scanf("%d", &ack);

        if(ack < 0 || ack > n){


            if(ack >= n){
                cout << "all frames are recived";
                break;
            }
            else{
                cout << "incorrect ack"
            }
        }
        else{
            printf("Acknowledgment %d received.\n", ack);
            sent = ack + 1;

        }
    }

}
