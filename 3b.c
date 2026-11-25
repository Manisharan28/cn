

#include <stdio.h>

struct node {
    unsigned dist[20];
    unsigned from[20];
} rt[10];

int main() {
    int dmat[20][20], n, i, j, k, count;

    printf("Enter the number of nodes: ");
    scanf("%d", &n);

    printf("Enter the cost matrix:\n");

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             scanf("%d", &dmat[i][j]);

             if(i == j){
                dmat[i][j] = 0;
             }

             rt[i].dist[j] = dmat[i][j];

             rt[i].from[j] = j;
        }
    }

    do{
        count = 0;
        for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
             for(int k=0;k<n;k++){
                if(rt[i].dist[j] >
                        dmat[i][k] + rt[k].dist[j]){




                        }

             }

        }
    }

    }while(count != 0);
    for (i = 0; i < n; i++) {
        printf("\nRouting table for router %d:\n", i + 1);

        for (j = 0; j < n; j++) {
            printf("Node %d via %d Distance = %u\n",
                   j + 1,
                   rt[i].from[j] + 1,
                   rt[i].dist[j]);
        }
    }

    return 0;
}
