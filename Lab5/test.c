#include <stdio.h>

int main(){
    struct A
    {
        char name[20];
        int age;
    };
    struct A s1 = {"A",10}, s2={"B",12};
   
   if(s1==s2){
    printf("same\n");
   }
    
    return 0;
}