#include<stdio.h>
#include<string.h>

typedef struct 
{
    int roll;
    char name[20];
    float mark[5];
    float avg;
    char gpa;
}student;

//student s[100];

void view(student s[100],int n){
    
    puts("Roll Name   Avg        GPA");
    for(int i = 0; i <n; i++){
    printf("%d    %s    %f   %c\n",(s+i)->roll, (s+i)->name, (s+i)->avg, (s+i)->gpa);}
}
student s[100];
char calgpa(float a){
    if(a>=80 && a<=100)return 'a';
    if(a>=71 && a<=79)return 'b';
    if(a>=61 && a<=70)return 'c';
    if(a>=41 && a<=60)return 'd';
    if(a>=0 && a<=40)return 'f';
}

int main(){
    int n;
    scanf("%d", &n);
    student s[200];
    for(int i = 0; i < n; i++){
        scanf("%d", &((s + i)->roll));
        scanf("%s", (s+i)->name);
        
        float sum=0;
        for(int j=0;j<5;j++){
            
            scanf("%f",&(s+i)->mark[j]);
            sum+=((s+i)->mark[j]);
        }
        (s+i)->avg=sum/5.0;
        (s+i)->gpa=calgpa((s+i)->avg);
        //printf("%c",(s+i)->gpa);
    }
    
    
        view(s,n);
    
    return 0;
}
