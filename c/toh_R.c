//SHIVAMBU DEV PANDEY
//23BCS123 
//CSE B
//LAB 
//PROGRAM 
//
//

/*
Description:

*/


#include <stdio.h>
void toh(int disk, char src, char dest, char aux){
    if(disk==1){
        printf("\nmove disk %d from %c to %c", disk , src, dest );
    }
    else{
        toh(disk -1 ,src, aux,dest);
        printf("\nmove disk %d from %c to %c", disk , src, dest );
        toh(disk -1 ,aux, dest, src);

    }

}
int main(){
    int num; 
    printf("enter a number: ");
    scanf("%d",&num);
    toh(num,'S','D','A');


    return 0;
}