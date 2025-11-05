#include<stdio.h>
int main(){
    int n,i;
    printf("enter size");
    scanf("%d",&n);
    int arr[n],sumo=0,sume=0;
    printf("enter elements");
    for(i=0;i<n;i++){
        scanf("%d",& arr[i]);
    }
    // for(i=0;i<n;i++){
    //     printf("%d",arr[i]);
    
    for(i=0;i<n;i++){ 
        if(i%2==0){
            sume=sume+ arr[i] ;
        }
        else{
            sumo=sumo+arr[i];
        }
     }
          printf("sum of numbers in even position is: %d\n",sume);
          printf("sum of numbers in odd position is: %d\n",sumo);
    return 0;

}