#include<bits/stdc++.h>
using namespace std;




class Student{
public:
    int reg_course=0;
    vector<string> courses;
    vector<int> slots;
    string roll;

    Student(){}
    Student(string rollNumber){
        roll = rollNumber;
    }


    bool operator==(Student &givenStudent){
        return roll == givenStudent.roll;
    }
};

class Course{
public:

    int slot,maxCap;
    vector<string> students;
    string course;

    Course(){}
    Course(string name){
        course = name;
    }


    bool operator==(Course &givenCourse){
        return course == givenCourse.course;
    }
};


bool sortSt(const Student &a1, const Student &a2){
    return a1.roll < a2.roll;
}

bool sortCr(const Course &a1, const Course &a2){
    return a1.course < a2.course;
}






int main(){
    ios_base::sync_with_stdio(false);

    int nc,ns,limit,nt;
    cin>>nc>>ns>>limit>>nt;

    cin.tie(0);
    cout.tie(0);
//making cin and cout faster 

    Course *clist = new Course[nc];
    Student *slist = new Student[ns];

    for(int i=0;i<nc;i++){
        cin>>clist[i].course>>clist[i].slot>>clist[i].maxCap;
    }



    for(int i=0;i<ns;i++){
        cin>>slist[i].roll;
    }

    sort(clist,clist+nc,sortCr);
    sort(slist,slist+ns,sortSt);


    for (int iter=1; iter<=nt; iter++) {
        
        char ch;
        cin>>ch;
        
        if(ch == 'D'){

            string rollNumber,curCourse;
            cin>>rollNumber>>curCourse;

            Student givenStudent(rollNumber);Course chr(curCourse);
            Student *pickedStudent = lower_bound(slist,slist+ns,givenStudent,sortSt);
            Course *cour = lower_bound(clist,clist+nc,chr,sortCr);

            if(!binary_search(pickedStudent->courses.begin(),pickedStudent->courses.end(),curCourse)){
                cout<<"fail" << endl;
            }

            else{
                pickedStudent->courses.erase(lower_bound(pickedStudent->courses.begin(),pickedStudent->courses.end(),curCourse));
                pickedStudent->slots.erase(lower_bound(pickedStudent->slots.begin(),pickedStudent->slots.end(),cour->slot));
                cour->students.erase(lower_bound(cour->students.begin(),cour->students.end(),rollNumber));
                cout<<"success"<< endl;
            }
        }

        else if(ch == 'R'){
            string rollNumber,curCourse;
            cin>>rollNumber>>curCourse;

            Student givenStudent(rollNumber);Course chr(curCourse);
            Student *pickedStudent = lower_bound(slist,slist+ns,givenStudent,sortSt);
            Course *cour = lower_bound(clist,clist+nc,chr,sortCr);

            bool check1=(pickedStudent->courses.size()>=limit || cour->maxCap!=-1 && cour->students.size()>=cour->maxCap);
            bool check2=binary_search(pickedStudent->courses.begin(),pickedStudent->courses.end(),curCourse);
            bool check3=binary_search(pickedStudent->slots.begin(),pickedStudent->slots.end(),cour->slot);
            if( check1 || check2  || check3 ){
                cout<<"fail" << endl;
            }

            else{
                pickedStudent->courses.insert(lower_bound(pickedStudent->courses.begin(),pickedStudent->courses.end(),curCourse),curCourse);
                pickedStudent->slots.insert(lower_bound(pickedStudent->slots.begin(),pickedStudent->slots.end(),cour->slot),cour->slot);
                cour->students.insert(lower_bound(cour->students.begin(),cour->students.end(),rollNumber),rollNumber);
                cout<<"success" << endl;
            }
        }

        else{
            string options;
            getline(cin,options);
            options = options.substr(1,options.size()-1);
            if(options.size()==9){
                Student givenStudent(options);
                Student *pickedStudent = lower_bound(slist,slist+ns,givenStudent,sortSt);
                for(int i=0;i<pickedStudent->courses.size();i++) cout<<pickedStudent->courses[i]<<" ";
                cout<<endl;
            }
            else if(options.size()==19){
                string roll1=options.substr(0,9),roll2=options.substr(10,9);
                Student st1(roll1),st2(roll2);
                Student *crStudent1 = lower_bound(slist,slist+ns,st1,sortSt);
                Student *crStudent2 = lower_bound(slist,slist+ns,st2,sortSt);
                for(int i=0;i<crStudent1->courses.size();i++){
                    if(binary_search(crStudent2->courses.begin(),crStudent2->courses.end(),crStudent1->courses[i])){
                        cout<<crStudent1->courses[i]<<" ";
                    }
                }
                cout<<endl;
            }

            else if(options.size()==6){
                Course chr(options);
                Course *cour = lower_bound(clist,clist+nc,chr,sortCr);
                for(int i=0;i<cour->students.size();i++) cout<<cour->students[i]<<" ";
                cout<<endl;
            }
            
            else{
                string Course01=options.substr(0,6),Course02=options.substr(7,6);
                Course iCourse1(Course01),iCourse2(Course02);


                Course *cour2 = lower_bound(clist,clist+nc,iCourse2,sortCr);
                Course *cour1 = lower_bound(clist,clist+nc,iCourse1,sortCr);

                for(int i=0;i<cour1->students.size();i++){
                    if(binary_search(cour2->students.begin(),cour2->students.end(),cour1->students[i])){
                        cout<<cour1->students[i]<<" ";
                    }
                }
                cout<<endl;
            }
        }
    }
}