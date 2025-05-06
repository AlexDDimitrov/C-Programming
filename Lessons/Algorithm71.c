#include<stdio.h>
#include<string.h>

void main()
{
    char s[100],s1[100],s2[100];
    char *p;
    int br=0;
    printf("s=");fgets(s,100,stdin);
    if(p=strchr(s,'\n'))*p='\0';
    
    //search and replace
    char spom[100];
    int len1=strlen(s1);
    int len2=strlen(s2);

    p=s;
    if(strlen(s1)>0)
     while(p=strstr(p,s1))
     {
        strcpy(spom,p+len1);
        strcpy(p,s2);
        strcat(s,spom);
        p=p+len2;
     }
    printf("\n%s",s);
}