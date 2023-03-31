// Write a program to add the contents of one file at
// the end of another file.

#include<stdio.h>
#include<stdlib.h>
int main(){
    FILE *f1 = fopen("file1.txt","r");
    FILE *f2 = fopen("file2.txt","a");
    char c;
    while ((c=fgetc(f1))!=EOF)
    {
        fputc(c,f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}