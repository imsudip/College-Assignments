#include<stdio.h>

struct Student
{
    char name[100];
    int roll;
    float marks[5];
    float avgMarks;
    float fullMarks;

};

struct Student  determineAvgAndFull(struct Student s){
    float full=0;
    for (int i = 0; i < 5; i++)
    {
        full+=s.marks[i];
    }
    s.fullMarks=full;
    s.avgMarks = full/5;
    return s;
}

struct Student takeStudentInput(){
    struct Student s;
    printf("Enter The name of the Student : ");
    scanf(" %[^\n]",s.name);
    printf("Enter the roll : ");
    scanf("%d",&s.roll);
    for (int i = 0; i < 5; i++)
    {
        printf("Enter the marks of subject %d : ",i+1);
        scanf("%f",&s.marks[i]);
    }
    s=determineAvgAndFull(s);
    return s;
}

void sortStudents(struct Student s[],int n){
    int i,j;
    struct Student temp;
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (s[i].fullMarks > s[j].fullMarks)
            {
                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }
}

void printAll(struct Student s[],int n){
    printf("Name                          |Roll |Full  |Avg  \n");
    for (int i = 0; i < n; i++)
    {
        printf("%30s|%5d|%3.2f|%3.2f\n",s[i].name,s[i].roll,s[i].fullMarks,s[i].avgMarks);
    }
    
}

int main(){
    struct Student s[200];
    int n;
    printf("Enter the total number of students: ");
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
       s[i]=takeStudentInput();
    }
    sortStudents(s,n);
    printAll(s,n);
    return 0;
}
