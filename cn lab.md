TASK 1A : 


#include <stdio.h>

int main() {
    int a[100], b[120];
    int n, i, j = 0, count = 0;

    printf("Enter frame length: ");
    scanf("%d", &n);

    printf("Enter input frame (0s and 1s only): ");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (i = 0; i < n; i++) {
        b[j++] = a[i];

        if (a[i] == 1) {
            count++;

            if (count == 5) {
                b[j++] = 0;
                count = 0;
            }
        } else {
            count = 0;
        }
    }

    printf("After stuffing the frame is: ");
    for (i = 0; i < j; i++)
        printf("%d", b[i]);

    printf("\n");
    return 0;
}

=======================================================================================

Task 1b : 



#include <stdio.h>
#include <string.h>

int main() {
    char a[100], b[220];
    int i = 0, j = 0;

    printf("Enter string: ");
    scanf("%99s", a);

    strcpy(b, "DLESTX");
    j = strlen(b);

    while (a[i] != '\0') {
        if (strncmp(&a[i], "DLE", 3) == 0) {
            strcpy(&b[j], "DLE");
            j += 3;
        }

        b[j++] = a[i++];
    }

    strcpy(&b[j], "DLEETX");

    printf("Frame after stuffing: %s\n", b);

    return 0;
}


=======================================================================================


Task1c:  


#include <stdio.h>
#include <string.h>

int main() {
    int n, i, j;
    printf("Enter no of frames: ");
    scanf("%d", &n);

    int frames[n];
    char string[n][50];

    for (i = 0; i < n; i++) {
        printf("Enter frame %d max_size: ", i + 1);
        scanf("%d", &frames[i]);
    }

    printf("Enter the content for each frame:\n");

    for (i = 0; i < n; i++) {
        do {
            printf("Enter content for frame %d: ", i + 1);
            scanf("%49s", string[i]);

            if (strlen(string[i]) > frames[i])
                printf("String exceeds maximum size! Enter again.\n");

        } while (strlen(string[i]) > frames[i]);
    }

    for (i = 0; i < n; i++) {
        int cnt = 0;

        for (j = 0; string[i][j] != '\0'; j++)
            cnt++;

        printf("Character count in frame %d is: %d\n",
               i + 1, cnt);
    }

    return 0;
}


=======================================================================================

Task2a :



#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i = 1, j = 1, n = 10, x;

    srand(time(NULL));
    printf("No. of frames is %d\n", n);

    while (n > 0) {
        printf("\nSending frame %d", i);
        x = rand() % 10;

        if (x == 0) {
            printf("\nFrame delayed. Resending frame %d", i);
            x = rand() % 10;
        }

        printf("\nACK for frame %d\n", j);

        n--;
        i++;
        j++;
    }

    printf("\nEnd of Stop-and-Wait protocol\n");
    return 0;
}

=======================================================================================

Task2b:



#include <stdio.h>

int main() {
    int total_frames, windowsize, sent = 0, ack = 0, i;
    int frame_start = 0;

    printf("Enter the total number of frames: ");
    scanf("%d", &total_frames);

    printf("Enter the window size: ");
    scanf("%d", &windowsize);

    if (windowsize <= 0 || total_frames <= 0 ||
        windowsize > total_frames) {
        printf("Invalid input.\n");
        return 1;
    }

    while (sent < total_frames) {
        for (i = 0; i < windowsize &&
                    frame_start + i < total_frames; i++) {
            printf("Frame %d has been transmitted.\n",
                   frame_start + i);
        }

        printf("Enter last ACK received (%d to %d): ",
               frame_start, frame_start + i - 1);
        scanf("%d", &ack);

        if (ack < frame_start || ack > frame_start + i - 1) {
            if (ack >= total_frames) {
                printf("All frames acknowledged.\n");
                break;
            }
            printf("Invalid acknowledgment.\n");
        } else {
            printf("Acknowledgment %d received.\n", ack);
            frame_start = ack + 1;
            sent = frame_start;
        }
    }

    return 0;
}



=======================================================================================

task2c :


#include <stdio.h>
#include <stdbool.h>

#define MAX_FRAMES 10

int main() {
    int n, w, start = 0, i, ack;
    bool ack_received[MAX_FRAMES] = {false};

    printf("Enter total frames (max 10): ");
    scanf("%d", &n);
    printf("Enter window size: ");
    scanf("%d", &w);

    if (n <= 0 || n > MAX_FRAMES || w <= 0 || w > n) {
        printf("Invalid input.\n");
        return 1;
    }

    while (start < n) {
        int end = start + w;
        if (end > n) end = n;

        for (i = start; i < end; i++)
            if (!ack_received[i])
                printf("Frame %d transmitted.\n", i);

        for (i = start; i < end; i++) {
            if (!ack_received[i]) {
                printf("Enter ACK for frame %d (-1 if missing): ", i);
                scanf("%d", &ack);

                if (ack == i)
                    ack_received[i] = true;
            }
        }

        for (i = start; i < end; i++) {
            if (!ack_received[i]) {
                printf("Retransmitting frame %d.\n", i);
                printf("Enter ACK for frame %d: ", i);
                scanf("%d", &ack);

                if (ack == i)
                    ack_received[i] = true;
            }
        }

        while (start < n && ack_received[start])
            start++;
    }

    printf("All frames acknowledged.\n");
    return 0;
}

=======================================================================================

task3a : 


#include <stdio.h>
#include <limits.h>

#define V 9

int minDistance(int dist[], int sptSet[]) {
    int min = INT_MAX, min_index = -1;

    for (int v = 0; v < V; v++) {
        if (!sptSet[v] && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[]) {
    printf("Vertex\tDistance from Source\n");
    for (int i = 0; i < V; i++)
        printf("%d\t%d\n", i, dist[i]);
}

void dijkstra(int graph[V][V], int src) {
    int dist[V], sptSet[V];

    for (int i = 0; i < V; i++) {
        dist[i] = INT_MAX;
        sptSet[i] = 0;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        if (u == -1) break;

        sptSet[u] = 1;

        for (int v = 0; v < V; v++) {
            if (!sptSet[v] && graph[u][v] &&
                dist[u] != INT_MAX &&
                dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    printSolution(dist);
}

int main() {
    int graph[V][V] = {
        {0,4,0,0,0,0,0,8,0},
        {4,0,8,0,0,0,0,11,0},
        {0,8,0,7,0,4,0,0,2},
        {0,0,7,0,9,14,0,0,0},
        {0,0,0,9,0,10,0,0,0},
        {0,0,4,0,10,0,2,0,0},
        {0,0,0,14,0,2,0,1,6},
        {8,11,0,0,0,0,1,0,7},
        {0,0,2,0,0,0,6,7,0}
    };

    dijkstra(graph, 0);
    return 0;
}

=======================================================================================

Task3b : 


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

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &dmat[i][j]);

            if (i == j)
                dmat[i][j] = 0;

            rt[i].dist[j] = dmat[i][j];
            rt[i].from[j] = j;
        }
    }

    do {
        count = 0;

        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                for (k = 0; k < n; k++) {
                    if (rt[i].dist[j] >
                        dmat[i][k] + rt[k].dist[j]) {

                        rt[i].dist[j] =
                            dmat[i][k] + rt[k].dist[j];

                        rt[i].from[j] = k;
                        count++;
                    }
                }
            }
        }
    } while (count != 0);

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


=======================================================================================
Task3c :

#include <stdio.h>
#include <stdlib.h>

int main() {
    int bucket_size = 10;
    int tokens = 0;
    int token_rate = 3;
    int no_of_queries = 6;
    int input_pkt_size[] = {4, 6, 8, 2, 1, 5};
    int required_tokens = 4;
    int queue = 0;
    int time_interval = 1;

    for (int i = 0; i < no_of_queries; i++) {
        tokens += token_rate * time_interval;

        if (tokens > bucket_size)
            tokens = bucket_size;

        printf("\nTime: %d seconds\n", i + 1);
        printf("Incoming packet size: %d\n", input_pkt_size[i]);

        if (tokens < required_tokens) {
            printf("Not enough tokens! Queuing packet of size %d.\n",
                   input_pkt_size[i]);
            queue += input_pkt_size[i];
        } else {
            tokens -= required_tokens;

            printf("Processed packet of size %d. Tokens remaining: %d\n",
                   input_pkt_size[i], tokens);

            while (queue > 0 && tokens >= required_tokens) {
                printf("Processing queued packet of size %d\n", queue);
                tokens -= required_tokens;
                queue = 0;
            }
        }

        printf("Tokens in bucket: %d\n", tokens);
        printf("Packets in queue: %d\n", queue);
    }

    return 0;
}


=======================================================================================



task4b : 


#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

long long mod_exp(long long base, long long exponent,
                  long long modulus) {
    long long result = 1;

    while (exponent > 0) {
        if (exponent % 2 == 1)
            result = (result * base) % modulus;

        base = (base * base) % modulus;
        exponent /= 2;
    }

    return result;
}

int main() {
    long long p, q, n, phi, e, d;
    long long encrypted, decrypted, message;

    printf("Enter a prime number p: ");
    scanf("%lld", &p);

    printf("Enter another prime number q: ");
    scanf("%lld", &q);

    n = p * q;
    phi = (p - 1) * (q - 1);

    e = 2;
    while (gcd(e, phi) != 1)
        e++;

    printf("Chosen e = %lld\n", e);

    d = 1;
    while ((e * d) % phi != 1)
        d++;

    printf("Public Key (n = %lld, e = %lld)\n", n, e);
    printf("Private Key (n = %lld, d = %lld)\n", n, d);

    do {
        printf("Enter message (integer less than %lld): ", n);
        scanf("%lld", &message);
    } while (message < 0 || message >= n);

    encrypted = mod_exp(message, e, n);
    printf("Encrypted message: %lld\n", encrypted);

    decrypted = mod_exp(encrypted, d, n);
    printf("Decrypted message: %lld\n", decrypted);

    return 0;
}

=======================================================================================

task 5:

4 pcs	subnet mask

10.0.0.1 255.255.255.0

10.0.0.2 255.255.255.0
10.0.0.3 255.255.255.0

10.0.0.4 255.255.255.0

arp -a


=======================================================================================

task 6a:
(just a switch with switch config)

Switch> enable
Switch# configure terminal
Switch(config)# hostname sh
sh(config)# banner motd #Warning Unauthorised access is prohibited#
sh(config)# line console 0
sh(config-line)# password griet1234
sh(config-line)# login
sh(config-line)# exit
sh(config)# enable secret griet5678
sh(config)# service password-encryption
sh(config)# no ip domain-lookup
sh(config)# end
sh# copy running-config startup-config
sh# show startup-config

task 6b : 

router and a pc

pc config : 
ip : 192.168.10.2
default : 192.168.10.1
subnet : 255.255.255.0


router config : 
Router> enable
Router# configure terminal
Router(config)# interface FastEthernet0/0
Router(config-if)# ip address 192.168.10.1 255.255.255.0
Router(config-if)# no shutdown
Router(config-if)# exit
Router(config)# enable secret griet1234
Router(config)# no ip domain-lookup
Router(config)# line console 0
Router(config-line)# password 1234
Router(config-line)# login
Router(config-line)# exit
Router(config)# line vty 0 4
Router(config-line)# password g1234
Router(config-line)# login
Router(config-line)# end


=======================================================================================


task 7a: (Static Routing)

two router , two switchs and 4 pcs

     ip 	subnet default
pc1:10.0.0.1 255.0.0.0 10.0.0.3
pc2:10.0.0.2 255.0.0.0 10.0.0.3
pc3:30.0.0.1 255.0.0.0 30.0.0.2
pc4:30.0.0.1 255.0.0.0 30.0.0.2


router1 : 20.0.0.1
router2 : 20.0.0.2


router1 config : 

Router>en
Router#configure terminal
Router(config)#interface fa0/0
Router(config-if)#ip address 10.0.0.3 255.0.0.0
Router(config-if)#no shutdown
Router(config-if)#
Router(config-if)#interface se2/0
Router(config-if)#ip address 20.0.0.2 255.0.0.0
Router(config-if)#no shut
Router(config-if)#exit

router2 config:

Router>en
Router#configure terminal
Router(config)#interface fa0/0
Router(config-if)#ip address 30.0.0.2 255.0.0.0
Router(config-if)#no shutdown
Router(config-if)#
Router(config-if)#interface se2/0
Router(config-if)#ip address 20.0.0.1 255.0.0.0
Router(config-if)#no shut
Router(config-if)#exit

=======================================================================================

task7b : 


so same as 7a.

two router , two switchs and 4 pcs

     ip 	subnet default
pc1:10.0.0.1 255.0.0.0 10.0.0.3
pc2:10.0.0.2 255.0.0.0 10.0.0.3
pc3:192.168.1.2 255.0.0.0 192.168.1.1
pc4:192.168.1.3 255.0.0.0 192.168.1.1


router1 : 20.0.0.1
router2 : 20.0.0.2


router 1 config:

write memory
en
config terminal
router rip 
version 2
network 10.0.0.0
network 20.0.0.0
no auto summary
exit

router 2 config:

write memory
en
config terminal
router rip # router ospf 1
version 2 # remove this for ospf
network 192.168.1.0 
network 20.0.0.0
no autosummary
exit

same do ospf

=======================================================================================
task 8a :

Switch(config)#vlan 10
Switch(config-vlan)#name project
Switch(config-vlan)#int f0/1
Switch(config-if)#switchport mode access
Switch(config-if)#switchport access vlan 10

output : ping ___

task 8b :

=======================================================================================

task 9a : both static nat and dynamic nat

static : 
	ip		default
pc 	10.0.0.2   	10.0.0.1
server  20.0.0.2   	20.0.0.1


Router>en
Router#configure terminal


Router(config)#interface 
Router(config)#interface fa0/0
Router(config-if)#ip address 10.0.0.1 255.0.0.0
Router(config-if)#no shutdown
Router(config-if)#ip nap inside 
Router(config-if)#exit

Router(config)#interface 
Router(config)#interface fa1/0
Router(config-if)#ip address 20.0.0.1 255.0.0.0
Router(config-if)#no shutdown
Router(config-if)#ip nap outside  
Router(config-if)#exit

==============================
dynamic:
	ip 	default gateway subnetmask
pc1 10.0.0.100   10.0.0.10 	255.0.0.0
pc2 10.0.0.101   10.0.0.10 	255.0.0.0
pc3 10.0.0.102   10.0.0.10 	255.0.0.0


server 155.4.12.1 1555.4.12.3 255.255.255.0

ip address 10.0.0.10 255.0.0.0
no shutdown
ip nat inside
exit

interface fa1/0
ip address 155.4.12.1 255.255.0.0
no shutdown
ip nat outside
exit

access-list 1 permit 10.0.0.0 0.0.0.255

ip nat pool newpool 155.4.12.1 155.4.12.3 netmask 255.255.255.0
ip nat inside source list 1 pool newpool

ip route 0.0.0.0 0.0.0.0 155.4.12.5
end

show ip nat translations

=======================================================================================
task 9b : pat and nat table entries


two laptops, one switch and router and server

	ip		default 	subnet 
laptop 	192.168.10.1  	192.168.10.3	255.255.255.0
lap2	192.168.10.2	192.168.10.3   	255.255.255.0
server  10.0.0.2   	10.0.0.1	255.0.0.0


enable
configure terminal

interface fa0/0
ip address 192.168.10.3 255.255.255.0
no shutdown
exit

interface fa1/0
ip address 10.0.0.1 255.0.0.0
no shutdown
exit

interface fa0/0
ip nat inside
exit

interface fa1/0
ip nat outside
exit

access-list 1 permit 192.168.10.3 0.0.0.255

ip nat inside source list 1 interface fa1/0 overload
end

test : show ip nat translations

=======================================================================================
task10a:

2pcs,switch,router,switch,3pcs

one network : 10.0.0.1
one network : 20.0.0.1

subnet for both : 255.0.0.0

enable
configure terminal

ip dhcp pool lan1
network 10.0.0.0 255.0.0.0
default-router 10.0.0.1
dns-server 8.8.8.8

ip dhcp pool lan2
network 20.0.0.0 255.0.0.0
default-router 20.0.0.1
dns-server 8.8.8.8

ip dhcp excluded-address 10.0.0.1
ip dhcp excluded-address 20.0.0.1
end
write memory

again in same cmd

configure terminal

interface fa0/0
ip address 10.0.0.1 255.0.0.0
no shutdown
exit

interface fa1/0
ip address 20.0.0.1 255.0.0.0
no shutdown
exit

end

test:show ip dhcp binding
=======================================================================================
task10b:

one pc and one switch

telnet config:(switch)
enable 
configure terminal

interface vlan 10
ip address 10.0.0.2 255.0.0.0
no shut
exit

configure terminal
username mani password sharan

ling vty 0 15
login local
transport input telnet
end

test : telnet 10.0.0.2 from pc cli

ssh config:

configure terminal
hostname myswitch
ip domain-name mydomain
username myname1 password mypass1

line vty 0 15
login local
transport input ssh
exit

crypto key generate rsa

test : ssh -l myname 10.0.0.2
=======================================================================================
task11:
subnetmask : 255.255.255.0
dns : 192.168.1.1
ip.address : 192.168.1.2
pc, router with two server(http , dns)

NO CODE
(html code)

for 11b:

use ipconfig
and check macaddress,ipv4 and subnet and network interfaces 

use ipconfig /all

=======================================================================================




