TASK 1A :





\#include <stdio.h>



int main() {

&#x20;   int a\[100], b\[120];

&#x20;   int n, i, j = 0, count = 0;



&#x20;   printf("Enter frame length: ");

&#x20;   scanf("%d", \&n);



&#x20;   printf("Enter input frame (0s and 1s only): ");

&#x20;   for (i = 0; i < n; i++)

&#x20;       scanf("%d", \&a\[i]);



&#x20;   for (i = 0; i < n; i++) {

&#x20;       b\[j++] = a\[i];



&#x20;       if (a\[i] == 1) {

&#x20;           count++;



&#x20;           if (count == 5) {

&#x20;               b\[j++] = 0;

&#x20;               count = 0;

&#x20;           }

&#x20;       } else {

&#x20;           count = 0;

&#x20;       }

&#x20;   }



&#x20;   printf("After stuffing the frame is: ");

&#x20;   for (i = 0; i < j; i++)

&#x20;       printf("%d", b\[i]);



&#x20;   printf("\\n");

&#x20;   return 0;

}



=======================================================================================



Task 1b :







\#include <stdio.h>

\#include <string.h>



int main() {

&#x20;   char a\[100], b\[220];

&#x20;   int i = 0, j = 0;



&#x20;   printf("Enter string: ");

&#x20;   scanf("%99s", a);



&#x20;   strcpy(b, "DLESTX");

&#x20;   j = strlen(b);



&#x20;   while (a\[i] != '\\0') {

&#x20;       if (strncmp(\&a\[i], "DLE", 3) == 0) {

&#x20;           strcpy(\&b\[j], "DLE");

&#x20;           j += 3;

&#x20;       }



&#x20;       b\[j++] = a\[i++];

&#x20;   }



&#x20;   strcpy(\&b\[j], "DLEETX");



&#x20;   printf("Frame after stuffing: %s\\n", b);



&#x20;   return 0;

}





=======================================================================================





Task1c:





\#include <stdio.h>

\#include <string.h>



int main() {

&#x20;   int n, i, j;

&#x20;   printf("Enter no of frames: ");

&#x20;   scanf("%d", \&n);



&#x20;   int frames\[n];

&#x20;   char string\[n]\[50];



&#x20;   for (i = 0; i < n; i++) {

&#x20;       printf("Enter frame %d max\_size: ", i + 1);

&#x20;       scanf("%d", \&frames\[i]);

&#x20;   }



&#x20;   printf("Enter the content for each frame:\\n");



&#x20;   for (i = 0; i < n; i++) {

&#x20;       do {

&#x20;           printf("Enter content for frame %d: ", i + 1);

&#x20;           scanf("%49s", string\[i]);



&#x20;           if (strlen(string\[i]) > frames\[i])

&#x20;               printf("String exceeds maximum size! Enter again.\\n");



&#x20;       } while (strlen(string\[i]) > frames\[i]);

&#x20;   }



&#x20;   for (i = 0; i < n; i++) {

&#x20;       int cnt = 0;



&#x20;       for (j = 0; string\[i]\[j] != '\\0'; j++)

&#x20;           cnt++;



&#x20;       printf("Character count in frame %d is: %d\\n",

&#x20;              i + 1, cnt);

&#x20;   }



&#x20;   return 0;

}





=======================================================================================



Task2a :







\#include <stdio.h>

\#include <stdlib.h>

\#include <time.h>



int main() {

&#x20;   int i = 1, j = 1, n = 10, x;



&#x20;   srand(time(NULL));

&#x20;   printf("No. of frames is %d\\n", n);



&#x20;   while (n > 0) {

&#x20;       printf("\\nSending frame %d", i);

&#x20;       x = rand() % 10;



&#x20;       if (x == 0) {

&#x20;           printf("\\nFrame delayed. Resending frame %d", i);

&#x20;           x = rand() % 10;

&#x20;       }



&#x20;       printf("\\nACK for frame %d\\n", j);



&#x20;       n--;

&#x20;       i++;

&#x20;       j++;

&#x20;   }



&#x20;   printf("\\nEnd of Stop-and-Wait protocol\\n");

&#x20;   return 0;

}



=======================================================================================



Task2b:







\#include <stdio.h>



int main() {

&#x20;   int total\_frames, windowsize, sent = 0, ack = 0, i;

&#x20;   int frame\_start = 0;



&#x20;   printf("Enter the total number of frames: ");

&#x20;   scanf("%d", \&total\_frames);



&#x20;   printf("Enter the window size: ");

&#x20;   scanf("%d", \&windowsize);



&#x20;   if (windowsize <= 0 || total\_frames <= 0 ||

&#x20;       windowsize > total\_frames) {

&#x20;       printf("Invalid input.\\n");

&#x20;       return 1;

&#x20;   }



&#x20;   while (sent < total\_frames) {

&#x20;       for (i = 0; i < windowsize \&\&

&#x20;                   frame\_start + i < total\_frames; i++) {

&#x20;           printf("Frame %d has been transmitted.\\n",

&#x20;                  frame\_start + i);

&#x20;       }



&#x20;       printf("Enter last ACK received (%d to %d): ",

&#x20;              frame\_start, frame\_start + i - 1);

&#x20;       scanf("%d", \&ack);



&#x20;       if (ack < frame\_start || ack > frame\_start + i - 1) {

&#x20;           if (ack >= total\_frames) {

&#x20;               printf("All frames acknowledged.\\n");

&#x20;               break;

&#x20;           }

&#x20;           printf("Invalid acknowledgment.\\n");

&#x20;       } else {

&#x20;           printf("Acknowledgment %d received.\\n", ack);

&#x20;           frame\_start = ack + 1;

&#x20;           sent = frame\_start;

&#x20;       }

&#x20;   }



&#x20;   return 0;

}







=======================================================================================



task2c :





\#include <stdio.h>

\#include <stdbool.h>



\#define MAX\_FRAMES 10



int main() {

&#x20;   int n, w, start = 0, i, ack;

&#x20;   bool ack\_received\[MAX\_FRAMES] = {false};



&#x20;   printf("Enter total frames (max 10): ");

&#x20;   scanf("%d", \&n);

&#x20;   printf("Enter window size: ");

&#x20;   scanf("%d", \&w);



&#x20;   if (n <= 0 || n > MAX\_FRAMES || w <= 0 || w > n) {

&#x20;       printf("Invalid input.\\n");

&#x20;       return 1;

&#x20;   }



&#x20;   while (start < n) {

&#x20;       int end = start + w;

&#x20;       if (end > n) end = n;



&#x20;       for (i = start; i < end; i++)

&#x20;           if (!ack\_received\[i])

&#x20;               printf("Frame %d transmitted.\\n", i);



&#x20;       for (i = start; i < end; i++) {

&#x20;           if (!ack\_received\[i]) {

&#x20;               printf("Enter ACK for frame %d (-1 if missing): ", i);

&#x20;               scanf("%d", \&ack);



&#x20;               if (ack == i)

&#x20;                   ack\_received\[i] = true;

&#x20;           }

&#x20;       }



&#x20;       for (i = start; i < end; i++) {

&#x20;           if (!ack\_received\[i]) {

&#x20;               printf("Retransmitting frame %d.\\n", i);

&#x20;               printf("Enter ACK for frame %d: ", i);

&#x20;               scanf("%d", \&ack);



&#x20;               if (ack == i)

&#x20;                   ack\_received\[i] = true;

&#x20;           }

&#x20;       }



&#x20;       while (start < n \&\& ack\_received\[start])

&#x20;           start++;

&#x20;   }



&#x20;   printf("All frames acknowledged.\\n");

&#x20;   return 0;

}



=======================================================================================



task3a :





\#include <stdio.h>

\#include <limits.h>



\#define V 9



int minDistance(int dist\[], int sptSet\[]) {

&#x20;   int min = INT\_MAX, min\_index = -1;



&#x20;   for (int v = 0; v < V; v++) {

&#x20;       if (!sptSet\[v] \&\& dist\[v] <= min) {

&#x20;           min = dist\[v];

&#x20;           min\_index = v;

&#x20;       }

&#x20;   }

&#x20;   return min\_index;

}



void printSolution(int dist\[]) {

&#x20;   printf("Vertex\\tDistance from Source\\n");

&#x20;   for (int i = 0; i < V; i++)

&#x20;       printf("%d\\t%d\\n", i, dist\[i]);

}



void dijkstra(int graph\[V]\[V], int src) {

&#x20;   int dist\[V], sptSet\[V];



&#x20;   for (int i = 0; i < V; i++) {

&#x20;       dist\[i] = INT\_MAX;

&#x20;       sptSet\[i] = 0;

&#x20;   }



&#x20;   dist\[src] = 0;



&#x20;   for (int count = 0; count < V - 1; count++) {

&#x20;       int u = minDistance(dist, sptSet);

&#x20;       if (u == -1) break;



&#x20;       sptSet\[u] = 1;



&#x20;       for (int v = 0; v < V; v++) {

&#x20;           if (!sptSet\[v] \&\& graph\[u]\[v] \&\&

&#x20;               dist\[u] != INT\_MAX \&\&

&#x20;               dist\[u] + graph\[u]\[v] < dist\[v]) {

&#x20;               dist\[v] = dist\[u] + graph\[u]\[v];

&#x20;           }

&#x20;       }

&#x20;   }



&#x20;   printSolution(dist);

}



int main() {

&#x20;   int graph\[V]\[V] = {

&#x20;       {0,4,0,0,0,0,0,8,0},

&#x20;       {4,0,8,0,0,0,0,11,0},

&#x20;       {0,8,0,7,0,4,0,0,2},

&#x20;       {0,0,7,0,9,14,0,0,0},

&#x20;       {0,0,0,9,0,10,0,0,0},

&#x20;       {0,0,4,0,10,0,2,0,0},

&#x20;       {0,0,0,14,0,2,0,1,6},

&#x20;       {8,11,0,0,0,0,1,0,7},

&#x20;       {0,0,2,0,0,0,6,7,0}

&#x20;   };



&#x20;   dijkstra(graph, 0);

&#x20;   return 0;

}



=======================================================================================



Task3b :





\#include <stdio.h>



struct node {

&#x20;   unsigned dist\[20];

&#x20;   unsigned from\[20];

} rt\[10];



int main() {

&#x20;   int dmat\[20]\[20], n, i, j, k, count;



&#x20;   printf("Enter the number of nodes: ");

&#x20;   scanf("%d", \&n);



&#x20;   printf("Enter the cost matrix:\\n");



&#x20;   for (i = 0; i < n; i++) {

&#x20;       for (j = 0; j < n; j++) {

&#x20;           scanf("%d", \&dmat\[i]\[j]);



&#x20;           if (i == j)

&#x20;               dmat\[i]\[j] = 0;



&#x20;           rt\[i].dist\[j] = dmat\[i]\[j];

&#x20;           rt\[i].from\[j] = j;

&#x20;       }

&#x20;   }



&#x20;   do {

&#x20;       count = 0;



&#x20;       for (i = 0; i < n; i++) {

&#x20;           for (j = 0; j < n; j++) {

&#x20;               for (k = 0; k < n; k++) {

&#x20;                   if (rt\[i].dist\[j] >

&#x20;                       dmat\[i]\[k] + rt\[k].dist\[j]) {



&#x20;                       rt\[i].dist\[j] =

&#x20;                           dmat\[i]\[k] + rt\[k].dist\[j];



&#x20;                       rt\[i].from\[j] = k;

&#x20;                       count++;

&#x20;                   }

&#x20;               }

&#x20;           }

&#x20;       }

&#x20;   } while (count != 0);



&#x20;   for (i = 0; i < n; i++) {

&#x20;       printf("\\nRouting table for router %d:\\n", i + 1);



&#x20;       for (j = 0; j < n; j++) {

&#x20;           printf("Node %d via %d Distance = %u\\n",

&#x20;                  j + 1,

&#x20;                  rt\[i].from\[j] + 1,

&#x20;                  rt\[i].dist\[j]);

&#x20;       }

&#x20;   }



&#x20;   return 0;

}





=======================================================================================





task4b :





\#include <stdio.h>

\#include <stdlib.h>

\#include <math.h>



int gcd(int a, int b) {

&#x20;   while (b != 0) {

&#x20;       int temp = b;

&#x20;       b = a % b;

&#x20;       a = temp;

&#x20;   }

&#x20;   return a;

}



long long mod\_exp(long long base, long long exponent,

&#x20;                 long long modulus) {

&#x20;   long long result = 1;



&#x20;   while (exponent > 0) {

&#x20;       if (exponent % 2 == 1)

&#x20;           result = (result \* base) % modulus;



&#x20;       base = (base \* base) % modulus;

&#x20;       exponent /= 2;

&#x20;   }



&#x20;   return result;

}



int main() {

&#x20;   long long p, q, n, phi, e, d;

&#x20;   long long encrypted, decrypted, message;



&#x20;   printf("Enter a prime number p: ");

&#x20;   scanf("%lld", \&p);



&#x20;   printf("Enter another prime number q: ");

&#x20;   scanf("%lld", \&q);



&#x20;   n = p \* q;

&#x20;   phi = (p - 1) \* (q - 1);



&#x20;   e = 2;

&#x20;   while (gcd(e, phi) != 1)

&#x20;       e++;



&#x20;   printf("Chosen e = %lld\\n", e);



&#x20;   d = 1;

&#x20;   while ((e \* d) % phi != 1)

&#x20;       d++;



&#x20;   printf("Public Key (n = %lld, e = %lld)\\n", n, e);

&#x20;   printf("Private Key (n = %lld, d = %lld)\\n", n, d);



&#x20;   do {

&#x20;       printf("Enter message (integer less than %lld): ", n);

&#x20;       scanf("%lld", \&message);

&#x20;   } while (message < 0 || message >= n);



&#x20;   encrypted = mod\_exp(message, e, n);

&#x20;   printf("Encrypted message: %lld\\n", encrypted);



&#x20;   decrypted = mod\_exp(encrypted, d, n);

&#x20;   printf("Decrypted message: %lld\\n", decrypted);



&#x20;   return 0;

}



=======================================================================================



task 5:



5a - 4pcs and hub - switch
5b - 4pcs and switch



4 pcs	subnet mask



10.0.0.1 255.255.255.0



10.0.0.2 255.255.255.0

10.0.0.3 255.255.255.0



10.0.0.4 255.255.255.0





5b :

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



&#x20;    ip 	subnet default

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



&#x20;    ip 	subnet default

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



output : ping \_\_\_



task 8b :



=======================================================================================



task 9a : both static nat and dynamic nat



static :

&#x09;ip		default

pc 	10.0.0.2   	10.0.0.1

server  20.0.0.2   	20.0.0.1





Router>en

Router#configure terminal





Router(config)#interface

Router(config)#interface fa0/0

Router(config-if)#ip address 10.0.0.1 255.0.0.0

Router(config-if)#no shutdown

Router(config-if)#ip nat inside

Router(config-if)#exit



Router(config)#interface

Router(config)#interface fa1/0

Router(config-if)#ip address 20.0.0.1 255.0.0.0

Router(config-if)#no shutdown

Router(config-if)#ip nat  outside

Router(config-if)#exit



==============================

dynamic:

&#x09;ip 	default gateway subnetmask

pc1 10.0.0.100   10.0.0.10 	255.0.0.0

pc2 10.0.0.101   10.0.0.10 	255.0.0.0

pc3 10.0.0.102   10.0.0.10 	255.0.0.0





server 155.4.12.1 155.4.12.3 255.255.255.0



ip address 10.0.0.10 255.0.0.0

no shutdown

ip nat inside

exit



interface fa1/0

ip address 155.4.12.1 255.255.255.0

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



&#x09;ip		default 	subnet

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



pc, router with two server(http , dns)



NO CODE
(html code)



for 11b:



use ipconfig

and check macaddress,ipv4 and subnet and network interfaces



use ipconfig /all



=======================================================================================

