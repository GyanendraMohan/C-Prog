#include<stdio.h>
int main(){
    char *s[5]={"Qatar", "Dubai", "Bangkok", "California", "Texas"};
    char **ptr[5] = {s, s+3,s+1,s+4,s+2};
    char ***p = ptr;
    printf("%s\n",**p++);
    printf("%s", *--*++p+3);
    return 0;
}