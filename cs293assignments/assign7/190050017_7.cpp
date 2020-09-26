#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Student{
public:
    string roll;
    int reg_course=0;
    vector<string> courses;
    vector<int> slots;
    Student(){}
    Student(string r){
        roll = r;
    }
    bool operator==(Student &st){
        return roll == st.roll;
    }
};

class Course{
public:
    string course;
    int slot,max_reg;
    vector<string> students;
    Course(){}
    Course(string c){
        course = c;
    }
    bool operator==(Course &co){
        return course == co.course;
    }
};

bool cmp(const Student &a, const Student &b){
    return a.roll < b.roll;
}

bool cmp1(const Course &a, const Course &b){
    return a.course < b.course;
}


int main(){
    ios_base::sync_with_stdio(false);
    int nc,ns,max_course,t;cin>>nc>>ns>>max_course>>t;cin.tie(0);cout.tie(0);
    Student *s = new Student[ns];
    Course *c = new Course[nc];
    for(int i=0;i<nc;i++){
        cin>>c[i].course>>c[i].slot>>c[i].max_reg;
    }
    sort(c,c+nc,cmp1);
    for(int i=0;i<ns;i++){
        cin>>s[i].roll;
    }
    sort(s,s+ns,cmp);
    while(t--){
        char ch;cin>>ch;
        if(ch == 'R'){
            string r,cou;cin>>r>>cou;
            Student st(r);Course chr(cou);
            Student *stu = lower_bound(s,s+ns,st,cmp);
            Course *cour = lower_bound(c,c+nc,chr,cmp1);
            if((cour->max_reg!=-1 && cour->students.size()>=cour->max_reg) || stu->courses.size()>=max_course || binary_search(stu->courses.begin(),stu->courses.end(),cou) || binary_search(stu->slots.begin(),stu->slots.end(),cour->slot)){
                cout<<"fail\n";
            }
            else{
                stu->courses.insert(lower_bound(stu->courses.begin(),stu->courses.end(),cou),cou);
                stu->slots.insert(lower_bound(stu->slots.begin(),stu->slots.end(),cour->slot),cour->slot);
                cour->students.insert(lower_bound(cour->students.begin(),cour->students.end(),r),r);
                cout<<"success\n";
            }
        }
        else if(ch == 'D'){
            string r,cou;cin>>r>>cou;
            Student st(r);Course chr(cou);
            Student *stu = lower_bound(s,s+ns,st,cmp);
            Course *cour = lower_bound(c,c+nc,chr,cmp1);
            if(!binary_search(stu->courses.begin(),stu->courses.end(),cou)){
                cout<<"fail\n";
            }
            else{
                stu->courses.erase(lower_bound(stu->courses.begin(),stu->courses.end(),cou));
                stu->slots.erase(lower_bound(stu->slots.begin(),stu->slots.end(),cour->slot));
                cour->students.erase(lower_bound(cour->students.begin(),cour->students.end(),r));
                cout<<"success\n";
            }
        }
        else{
            string str;
            getline(cin,str);
            str = str.substr(1,str.size()-1);
            if(str.size()==9){
                Student st(str);
                Student *stu = lower_bound(s,s+ns,st,cmp);
                for(int i=0;i<stu->courses.size();i++) cout<<stu->courses[i]<<" ";
                cout<<"\n";
            }
            else if(str.size()==6){
                Course chr(str);
                Course *cour = lower_bound(c,c+nc,chr,cmp1);
                for(int i=0;i<cour->students.size();i++) cout<<cour->students[i]<<" ";
                cout<<"\n";
            }
            else if(str.size()==19){
                string r1=str.substr(0,9),r2=str.substr(10,9);
                Student st1(r1),st2(r2);
                Student *stu1 = lower_bound(s,s+ns,st1,cmp);
                Student *stu2 = lower_bound(s,s+ns,st2,cmp);
                for(int i=0;i<stu1->courses.size();i++){
                    if(binary_search(stu2->courses.begin(),stu2->courses.end(),stu1->courses[i])){
                        cout<<stu1->courses[i]<<" ";
                    }
                }
                cout<<"\n";
            }
            else{
                string c1=str.substr(0,6),c2=str.substr(7,6);
                Course chr1(c1),chr2(c2);
                Course *cour1 = lower_bound(c,c+nc,chr1,cmp1);
                Course *cour2 = lower_bound(c,c+nc,chr2,cmp1);
                for(int i=0;i<cour1->students.size();i++){
                    if(binary_search(cour2->students.begin(),cour2->students.end(),cour1->students[i])){
                        cout<<cour1->students[i]<<" ";
                    }
                }
                cout<<"\n";
            }
        }
    }
}