#include<stdio.h>
int count=1;
void tower(int n, char from, char to, char other) 
{
    
    if(n==1){
        printf("\nStep %d Move disk 1 from %c to %c",count++,from,to);
        return;
    }
    tower(n-1,from,other,to);
    printf("\nStep %d Move disk %d from %c to %c",count++, n, from, to);
    tower(n-1,other,to,from);
}

int main(){
    int n;
    printf("Enter Disk no.");
    scanf("%d",&n);
    tower(n,'A','C','B');
    return 0;
}