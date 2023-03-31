// Write a program to read a text file, convert each
// character to uppercase and write it to another file.

#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
int main(){
    FILE *f1 = fopen("file1.txt","r");
    FILE *f2 = fopen("file2.txt","w");
    char c;
    while ((c=fgetc(f1))!=EOF)
    {
        fputc(toupper(c),f2);
    }
    fclose(f1);
    fclose(f2);
    return 0;
}