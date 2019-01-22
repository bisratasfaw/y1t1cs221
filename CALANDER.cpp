#include <iostream>
#include <iomanip>
#include <string>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
int main()
{
    int year,weekEndGr=0,weekEndEt=0;
    cout<<"enter the year for the calnder you want to see: ";
    cin>>year;
    const string mon[12]={"JANUARY","FEBRUARY","MARCH","APRIL","MAY","JUNE","JULY","AUGUST","SEPTEMBER","OCTOBER","NOVEMBER","DECEMBER"};
    const string mon2[12]={"tahsas/tir","tir/yekatit","yekatit/megabit","megabit/miyazya","miyaziya/ginbot","ginbot/sene","sene/hamle","hamle/nehase","nehase/pagume/meskerem","meskerem/tikimt","tikemt/hidar","hidar/tahsas"};
    const string dy[]={"SUN","MON","TUE","WED","THU","FRI","SAT"};
    int emd[]={30,30,30,30,30,30,30,30,30,30,30,30,5};
    int gmd[]={31,28,31,30,31,30,31,31,30,31,30,31,0};
    if (year%4==0&&year%100!=0||year%400==0){
        emd[12]=6;
        gmd[1]=29;
    }
    for (int i=0;i<13;i++){
        cout<<"\n\n"<<mon[i]<<"-----------------------------"<<mon2[i]<<endl;
        cout<<fixed<<setprecision(2)<<showpoint<<endl;
        cout<<setfill('-')<<setw(49)<<""<<setfill(' ')<<endl;
        for (int p=0;p<7;p++){
            cout<<"|"<< setw(4)<<dy[p]<<" ";
    }
        cout<<fixed<<setprecision(2)<<showpoint<<endl;
        cout<<setfill('-')<<setw(49)<<""<<setfill(' ')<<endl;
        for(int j=1, k=1;j<=gmd[i],k<=emd[i];j++,k++){
            cout<<setw(2)<<' '<<j;
            weekEndGr++;{
            if (weekEndGr>6){
                cout<<endl;
                weekEndGr=0;
            }}
            cout<<setw(2)<<' '<<k;
            weekEndEt++;
            if(weekEndEt>6)
                cout<<endl;
                weekEndEt=0;


        }
    }

        cout<<fixed<<setprecision(2)<<showpoint<<endl;
        cout<<setfill('-')<<setw(49)<<""<<setfill(' ')<<endl;

    cout<<endl;
}
