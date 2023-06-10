
#include<stdio.h> 
#include<stdlib.h> 
int main() 
{ 
FILE *fp1,*fp2; 
char ch,data; 
int choice, status; 
do{ 
printf("\nFile Handling Operations"); 
printf("\nPress 1 to create a file"); 
printf("\nPress 2 to open a file"); 
printf("\nPress 3 to write data into a file"); 
printf("\nPress 4 to read a file"); 
printf("\nPress 5 to append data to a file"); 
printf("\nPress 6 to copy a file"); 
printf("\nPress 7 to rename a file"); 
printf("\nPress 9 to exit"); 
printf("\nEnter your choice"); 
scanf("%d",&choice); 
switch(choice) 
{ 
case 1: fp1 = fopen("testfile.txt", "w"); 
if (fp1 == NULL) 
{ 
printf("Error creating file\n"); 
} 
printf("File created successfully\n"); 
fclose(fp1); 
break; 
 
case 2: fp1 = fopen("testfile.txt", "r"); 
if (fp1 == NULL) 
{ 
printf("Error opening file\n"); 
} 
printf("File opened successfully\n"); 
break; 
 
case 3: fp1 = fopen("testfile.txt", "w"); // opening a file named test.txt 
if (fp1 == NULL) 
{ 
printf("Error!"); 
} 
fprintf(fp1, "Welcome to C programming\n"); 
fprintf(fp1, "This is a sample program\n"); 
printf("Data written successfully\n"); 
fclose(fp1); 
break; 
 
case 4: fp1 = fopen("testfile.txt", "r"); // opening a file named test.txt 
if (fp1 == NULL) 
{ 
printf("Error!"); 
} 
printf("The contents of file are :\n"); 
while ((ch = fgetc(fp1)) != EOF) 
{ 
printf("%c", ch); 
} 
fclose(fp1); 
break; 
 
case 5:fp1=fopen("testfile.txt","a"); //opening file test.txt 
if(fp1==NULL) 
{ 
printf("Error!"); 
} 
fputs("This data is appended to existing data\n",fp1); 
printf("Data appended successfully\n"); 
fclose(fp1); 
break; 
 
case 6: fp1 = fopen("testfile.txt", "r"); //opening file test.txt 
if (fp1 == NULL) 
{ 
printf("Error!"); 
} 
fp2 = fopen("test_copy.txt", "w"); //creating file test_copy.txt 
if (fp2 == NULL) 
{ 
printf("Error!"); 
} 
while((ch = fgetc(fp1)) != EOF) 
{ 
fputc(ch, fp2); 
} 
printf("File copied successfully\n"); 
fclose(fp1); 
fclose(fp2); 
break; 
 
case 7: status = rename("testfile.txt", "test_renamed.txt"); //renaming file test.txt to test_renamed.txt 
if (status == 0) 
{ 
printf("File renamed successfully\n"); 
} 
else 
{ 
printf("Unable to rename the file\n"); 
} 
break; 
case 9: exit(0); 
break; 
default: printf("Enter valid choice"); 
} 
}while(choice<10); 
}