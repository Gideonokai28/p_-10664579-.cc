// 10664579_project work
//Student and Staff Database Management System
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>


using namespace std;
int main()
{
    FILE *fp, *ft;
    char another, choice;

    struct student_staff
    {
        char first_name[50], last_name[50],staff_first_name[50],staff_last_name[50];
        char course_code[100];
        char grade[100];
        
    };

    struct student_staff e;
    char xfirst_name[50], xlast_name[50],xstaff_first_name[50],xstaff_last_name[50];
    long int recsize;

    fp=fopen("users.txt","rb+");

    if (fp == NULL)
    {
        fp = fopen("users.txt","wb+");

        if (fp==NULL)
        {
            puts("Cannot open file");
            return 0;
        }
    }


    recsize = sizeof(e);

    while(1)
    {system("color 7C");
        system("cls");

        cout << "\t\t!!!!!!!!!!>>>> STUDENT AND STAFF DATABASE MANAGEMENT SYSTEM  OF GILCAN UNIVERSITY>>>>>!!!!!!!!!!!!";
        cout <<"\n\n                                          ";
        cout << "\n\n";
        cout << "\n \t\t\t 1. Add      Student Record";
        cout << "\n \t\t\t 2. Display  Students Records";
        cout << "\n \t\t\t 3. Modify   Student  Records";
        cout << "\n \t\t\t 4. Delete   Student  Records";
        cout << "\n \t\t\t 5. Add      Staff    Records";
        cout << "\n \t\t\t 6. Modify   Staff    Records";
        cout << "\n \t\t\t 7. delete   Staff    Records";
        cout << "\n \t\t\t 8. Exit   System";
        cout << "\n\n";
        cout << "\t\t\t please select your choice :=> ";
        fflush(stdin);
        choice = getche();
        switch(choice)
        {
        case '1' :system("color BC");                               //  student section(add,edit and delete Student information)
            fseek(fp,0,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y')
            {
                system("cls");
                cout << "Enter the Firt Name : ";
                cin >> e.first_name;
                cout << "Enter the Last Name : ";
                cin >> e.last_name;
                cout << "Enter the Course code    : ";
                cin >> e.course_code;
                cout << "Enter the grade  : ";
                cin>> e.grade;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
        case '2':system("color 7C");
            system("cls");
            rewind(fp);
            cout << "=== View of Records in the Database ===";
            cout << "\n";
            while (fread(&e,recsize,1,fp) == 1)
            {
                cout << "\n";
                cout <<"\n" <<"first name: "<< e.first_name <<   setw(10)  <<"     last name: "<< e.last_name;
                cout << "\n";
                cout <<"\n" <<"course: "<<e.course_code <<       setw(8)  <<"      Grade: "<< e.grade;
            }
            cout << "\n\n";
            system("pause");
            break;

        case '3' :
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student : ";
                cin >> xlast_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.last_name,xlast_name) == 0)
                    {
                        cout << "Enter new the Firt Name : ";
                        cin >> e.first_name;
                        cout << "Enter new the Last Name : ";
                        cin >> e.last_name;
                        cout << "Enter new the Course    : ";
                        cin >> e.course_code;
                        cout << "Enter new the grade  : ";
                        cin >> e.grade;
                        fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout<<"record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;


        case '4':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the student to delete : ";
                cin >> xlast_name,xfirst_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.last_name,xlast_name) != 0)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }

            break;
            case '5':                               //Entering Staff section(add,edit and delete Staff information)
            	 fseek(fp,1,SEEK_END);
            another ='Y';
            while(another == 'Y' || another == 'y'){
			
            	system("cls");
                cout << "Enter the Firt Name : ";
                cin >> e.staff_first_name;
                cout << "Enter the Last Name : ";
                cin >> e.staff_last_name;
                fwrite(&e,recsize,1,fp);
                cout << "\n Add Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
                    break;
        case '6':
        	 system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the staff : ";
                cin >> xstaff_last_name;

                rewind(fp);
                while (fread(&e,recsize,1,fp) == 1)
                {
                    if (strcmp(e.staff_last_name,xstaff_last_name) == 1)
                    {
                        cout << "Enter new the Firt Name : ";
                        cin >> e.staff_first_name;
                        cout << "Enter new the Last Name : ";
                        cin >> e.staff_last_name;
                        fseek(fp, - recsize, SEEK_CUR);
                        fwrite(&e,recsize,1,fp);
                        break;
                    }
                    else
                        cout<<"record not found";
                }
                cout << "\n Modify Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
            break;
            case '7':
            system("cls");
            another = 'Y';
            while (another == 'Y'|| another == 'y')
            {
                cout << "\n Enter the last name of the staff to delete : ";
                cin >> xstaff_last_name;

                ft = fopen("temp.dat", "wb");

                rewind(fp);
                while (fread (&e, recsize,1,fp) == 1)

                    if (strcmp(e.staff_last_name,xstaff_last_name) != 1)
                    {
                        fwrite(&e,recsize,1,ft);
                    }
                fclose(fp);
                fclose(ft);
                remove("users.txt");
                rename("temp.dat","users.txt");

                fp=fopen("users.txt","rb+");

                cout << "\n Delete Another Record (Y/N) ";
                fflush(stdin);
                another = getchar();
            }
           
         //exiting the software
        case '8':
            fclose(fp);
            cout << "\n\n";
            cout << "\t\t     THANK YOU FOR USING THIS SOFTWARE SEE YOU AGAIN";
            cout << "\n\n";
            exit(0);
        }
    }


    system("pause");
    return 0;
}

