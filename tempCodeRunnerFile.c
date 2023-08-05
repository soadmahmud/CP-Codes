#include<stdio.h>

int main ()
{
    int ara[]={1,2,3,4,5,6,7,8,9,11,22,33,44,55,66,77,88,99,100,101,110,111};
    int low_index = 1;
    int high_index = 111;
    int mid_index = ((low_index + high_index)/2);

    int n=100;

    for(;low_index<=high_index;){
        if(n == mid_index){
            break;
        }
        if(n < ara[mid_index]){
                high_index = mid_index -1;
        }
        else{
            low_index = mid_index +1;
        }
    }
    if(low_index>high_index){
        printf("%d is not in the ara\n",n);
    }
    else{
        printf("%d is in the ara\n",n);
    }
    return 0;
}
