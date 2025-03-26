#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#include <ctype.h>



typedef struct 
{
    int roll;
    char name[20];
    float marks[5];
    float avg;
    char gpa;
}student;

student s[100];




int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %s",&s[i].roll,s[i].name);
        float sum=0;
        for(int j=0;j<n;i++){
            scanf("%f",s[i].marks[j]);
            sum+=s[i].marks[j];
        }
        s[i].avg=sum/5.0;
        s[i].gpa=calgpa(s[i].avg);
    }
    return 0;
}




























// #include<stdio.h>
// #include<string.h>

// typedef struct{
//     char name[40];
//     int num;
//     int mark[5];
//     float avg;
// } student;

// int main(){
//     int n;
//     scanf("%d", &n);
//     student s[200];
//     for(int i = 0; i < n; i++){
//         scanf("%s", (s+i)->name);
//         scanf("%d", &((s + i)->num));
//         float sum=0;
//         for(int j=0;j<5;j++){
            
//             scanf("%d",&(s+i)->mark[j]);
//             sum+=((s+i)->mark[j]);
//         }
//         (s+i)->avg=sum/5.0;
//     }
//     for(int i = 0; i < n-1; i++){
//         for(int j = i+1; j < n; j++){
//             if((s+i)->avg> (s+j)->avg){
//                 student temp;
//                 temp = *(s+i);
//                 *(s+i) = *(s+j);
//                 *(s+j) = temp;
//             }
//         }
//     }
//     for(int i = n-1; i >=0; i--){
//         printf("%s %f\n", (s+i)->name, (s+i)->avg);
//     }
//     return 0;
// }
