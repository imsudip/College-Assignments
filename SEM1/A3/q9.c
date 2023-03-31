// Write a program to perform the following
// operations on a binary mode file storing student
// information(name, roll, marks, DOB): (1) create
// the file (2) add a new record (3) delete a record
// specified by the roll number (4) modify the marks
// of each student by adding grace marks of 10 if the
// original marks is less than 50 and greater than 40

#include <stdio.h>
#include <stdlib.h>

struct student
{
   char name[30];
   int roll;
   float marks;
   char dob[10];
};
typedef struct student Student;

Student takeStudentInput()
{
   Student s;
   printf("Enter the name of the student : ");
   scanf(" %[^\n]", s.name);
   printf("Enter the roll : ");
   scanf("%d", &s.roll);
   printf("Enter the marks : ");
   scanf("%f", &s.marks);
   printf("Enter the DOB : ");
   scanf(" %[^\n]", s.dob);
   return s;
}

void addStudent(FILE *fp)
{
   Student s;
   s = takeStudentInput();
   fseek(fp, 0, SEEK_END);
   fwrite(&s, sizeof(Student), 1, fp);
}

void deleteStudent(FILE *fp)
{
   int roll;
   printf("Enter the roll of the student to be deleted : ");
   scanf("%d", &roll);
   Student s[1000];
   int i = 0;
   fseek(fp, 0, SEEK_SET);
   while (fread(&s[i], sizeof(Student), 1, fp))
   {
      i++;
   }
   int n = i;
   int flag = 0;
   for (i = 0; i < n; i++)
   {
      if (s[i].roll == roll)
      {
         flag = 1;
         s[i].roll = -1;
         break;
      }
   }
   if (flag == 0)
   {
      printf("Student not found...\n");
      return;
   }

   fseek(fp, 0, SEEK_SET);
   for (i = 0; i < n; i++)
   {
         fwrite(&s[i], sizeof(Student), 1, fp);
 
   }

   printf("Record deleted successfully\n");
}

void addGrace(FILE *fp)
{
   Student s[1000];
   int i = 0;
   fseek(fp, 0, SEEK_SET);
   while (fread(&s[i], sizeof(Student), 1, fp))
   {
      i++;
   }
   int n = i;
   for (i = 0; i < n; i++)
   {
      if (s[i].marks < 50 && s[i].marks > 40)
      {
         s[i].marks += 10;
      }
   }

   fseek(fp, 0, SEEK_SET);
   for (i = 0; i < n; i++)
   {
      fwrite(&s[i], sizeof(Student), 1, fp);
   }

   printf("Grace marks added successfully\n");
}

void printAll(FILE *fp)
{
   Student s;
   fseek(fp, 0, SEEK_SET);
   printf("Name                          |Roll |Marks |DOB \n");
   while (fread(&s, sizeof(Student), 1, fp))
   {
      if (s.roll != -1)
      {
         printf("%30s|%5d|%3.2f|%s\n", s.name, s.roll, s.marks, s.dob);
      }
   }
}

int main()
{
   FILE *fp;
   int choice;
   fp = fopen("student.dat", "rb+");
   if (fp == NULL)
   {
      fp = fopen("student.dat", "wb+");
      if (fp == NULL)
      {
         printf("Cannot open file");
         exit(0);
      }
   }
   while (1)
   {
      printf("1. Add a new record\n");
      printf("2. Delete a record\n");
      printf("3. Modify a record\n");
      printf("4. Print all records\n");
      printf("5. Exit\n");
      printf("Enter your choice : ");
      scanf("%d", &choice);
      switch (choice)
      {
      case 1:
         addStudent(fp);
         break;
      case 2:
         deleteStudent(fp);
         break;
      case 3:
         addGrace(fp);
         break;
      case 4:
         printAll(fp);
         break;
      case 5:
         exit(0);
      }
   }
   fclose(fp);
   return 0;
}