#include<stdio.h>
int main(){
    char *s[5] = {"Bahubali","Katappa","Ballaldev","Rajmatha","Devsena"};
    char **ptr[5] = {s+1,s+2,s,s+4,s+3}; 
    char ***p = ptr;
    printf("%s",**p++);
    printf("%s",*(p[-2])+3);
    printf("%s",**++p);
    printf("%s",*--*++p+3);
    printf("%s",p[-1][-1]+1);
    printf("%c",s[1][2]);
    printf("%c",***++p + 2);
    return 0;
}