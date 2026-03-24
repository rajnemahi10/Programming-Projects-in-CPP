#include <iostream>
#include <vector>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;
class Student{
public:
    char* name;
    char* hostel;
    
    //self implemented strtok
    char *strtok(char *str, char *sep)
    {
        static char *m;
        static int sepSize;

        if (str == NULL)
        {
            int i = 0;
            for (; i < sepSize; i++)
            {
                m++;
            }

            char *temp = strstr(m, sep);
            if (temp == NULL)
                return NULL;

            sepSize = strlen(sep) - 1;
            *temp = '\0';
            return m;
        }

        m = str;
        char *temp = strstr(m, sep);
        if (temp == NULL)
            return NULL;

        sepSize = strlen(sep) - 1;
        *temp = '\0';
        return str;
    }
    

};
int main()
{
    vector<Student> students;
    char data[]="Aarav Sharma:Hostel-A:Ishita Verma:Hostel-B:Rohan Mehta:Hostel-C:Sneha Iyer:Hostel-A";
    char *ptr=data; 
    char col[]=":";
    char *sep=col;
    char*c=strtok(ptr,sep);

    while(c!=NULL)
    {
        Student s1;
        s1.name=strdup(c);
        c=strtok(NULL,sep);//stores pointer to where it ended last time
        if(c==NULL)// if a student doesn't have a hostel
            break;
        s1.hostel=strdup(c);
        students.push_back(s1);
        c=strtok(NULL,sep);

    }


    //to generate a random sequence of students of size N
    int sz=students.size();
    int N;
    for(int i=0;i<N;i++)
    {
        int x=rand()%sz;
        cout<<students[x].name<<":"<< students[x].hostel<<endl;
    }
    //freeing
    for(int i=0;i<students.size();i++)
    {
        free(students[i].name);
        free(students[i].hostel);
    }


}

