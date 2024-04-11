#include <stdio.h>
#define MALE 1
#define FEMALE 0
#define SINGLE 0
#define MARRIED 1
#define DIVORCED 2
#define WIDOWED 3
struct student1{
    char name[16];
    int gender;
    int marriage;
    int grade;
    int age;
};
struct stu_info{
    unsigned int gender:1;
    unsigned int marriage:2;
    unsigned int grade:3;
    unsigned int age:7;
};
struct student2{
    char name[16];
    struct stu_info info;
};
char *gender[]={"Female","Male"};
char *marriage[]={"Single","Married","Divorced","Widowed"};

int main(){
    struct student1 s1={"Lao Wang",MALE,DIVORCED,5,30};
    struct student2 s2={"Gui Hua",{FEMALE,SINGLE,1,19}};
    printf("sizeof(s1):%ld\n",sizeof(s1));
    printf("sizeof(s2):%ld\n",sizeof(s2));
    printf("sizeof(stu_info):%ld\n",sizeof(struct stu_info));
    printf("student1 %s,%s,%s,%d,%d\n",
            s1.name,gender[s1.gender],marriage[s1.marriage],
            s1.grade,s1.age);
    printf("student2 %s,%s,%s,%d,%d\n",
            s2.name,gender[s2.info.gender],marriage[s2.info.marriage],
            s2.info.grade,s2.info.age);
    return 0;       
}