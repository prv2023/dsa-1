#include <stdio.h>

void TOH( int n, char origin, char aux, char destination){
    if(n==1){
        printf("Moving Disk 1 from Tower %c to Tower %c\n", origin, destination);
        return ;
    }
    TOH( n-1, origin,  destination, aux);
    printf("Moving Disk %d from Tower %c to Tower %c\n", n, origin, destination);
    TOH(n-1,aux,origin,destination);
}
int main(){
    int n;
    printf("Enter the number of disks: \n");
    scanf("%d",&n);
    TOH(n,'A','B','C');
}