#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

/*
Bruk Berhane Asfaw GC9242
Section A Group 2
*/

int main()
{
    int year,weekEndGr,weekDay,ethiopian_day=23,maxED=30,pagume=5,cnt=1,v,ans;
    do{
        cout<<"\nEnter the year for the calnder you want to check: ";
        cin>>year;

        const string mon_greg[12]={"January","Febuary","March","April","May","June",
        "July","August","September","October","November","December"};///
        const string mon_ethio[12]={"Tahsas/Tir","Tir/Yekatit","Yekatit/Megabit","Megabit/Miyazya",
        "Miyaziya/Ginbot","Ginbot/Sene","Sene/Hamle","Hamle/Nehase",
        "Nehase/Pagume/Meskerem","Meskerem/Tikimt","Tikemt/Hidar","Hidar/Tahsas"};
        const string days[]={"Sun","Mon","Tue","Wed","Thu","Fri","Sat"};
        //The end of each gregorian month in an array
        int gmd[]={31,28,31,30,31,30,31,31,30,31,30,31};
        
        //Formula to calculate leap years
        if (year%4==0&&year%100!=0||year%400==0){
            gmd[1]=29;
            ethiopian_day=22;
            pagume=6;
        }
        
        //Getting the starting day of the year
        weekDay = (((year - 1) * 365) + ((year - 1) / 4) - ((year - 1) / 100) + ((year) / 400) + 1) % 7;
        weekEndGr=weekDay;
        
        //This for loop will loop the display table 12 times for each month
        for(int i=0;i<12;i++){
            cout<<"\n\n";
                
            //Conditions for months and their appropriate years
            if (i <= 7)
                cout<< setw(0) << right << mon_greg[i] << year << setw(30) << right << mon_ethio[i] << " " << year - 8 << endl;
            else if(i == 8)
                cout<< setw(0) << right << mon_greg[i] << year << setw(30) << right << mon_ethio[i] << " " << year-8 << " / " << year - 7 << endl;
            else
                cout<<setw(0)<<right<<mon_greg[i]<<year<<setw(30)<<right<<mon_ethio[i]<<year-7<<endl;
                
            //Outputs a straight line
            cout<<setfill('-')<<setw(56)<<""<<setfill(' ')<<endl;
        
            //The loop that shows the weekdays
            for(int j=0;j<7;j++){
                cout<<setw(4)<<days[j]<<setw(4)<<'|';
                if (j==6)
                    cout<<endl;
            }
            
            cout<<setfill('-')<<setw(56)<<""<<setfill(' ')<<endl;
            
            //Sets the first date for the month (meaning places the day on the appropriate weekday)
            for(int d=0;d<weekDay;d++){
                cout<<setw(8)<<"|";
            }
            
            //Shows the Gregorian date with the Ethiopian date beside it
            for (int k=1;k<=gmd[i];k++){
            
                //Showing the gregorian and Ethiopian cals
                cout<<setw(2)<<k<<"  "<<setw(2)<<ethiopian_day<<setw(2)<<'|';
            
                //Increasing the starting date of the Ethiopian calendar until the Gregorian month is complete
                ethiopian_day++;
            
                //Checks if the Ethiopian month is complete and changes it to a new month accordingly
                if (ethiopian_day==31){
                    cnt++;
                    ethiopian_day=1;}
            
                if(cnt==10&&ethiopian_day>pagume){
                        ethiopian_day=2;cnt++;
                }
            
                weekEndGr++;
            
                //Condition that works while making sure the week is only 7 days
                while(weekEndGr>6){
                    cout<<endl;
                    cout<<setfill('-')<<setw(56)<<""<<setfill(' ')<<endl;
                    weekEndGr=0;
                }
           
                //For starting next month's day on the right DoW
                weekDay=weekEndGr;
           
            }
           
           //To set the width of the days
            v=weekDay*8;
           
            cout<<endl;
            //Outputting a straightline whlst checking the width of the weekday
            cout<<setfill('-')<<setw(v)<<""<<setfill(' ')<<endl;
           
            //These conditions check the month and display the appropriate holiday
            if(i==0)
                cout<<setw(45)<<left<<"TAHSAS 29 Gena"<<setw(20)<<right<<"January 7 Ethiopian Chrismas"<<endl<<setw(45)<<left<<"TIR 11 Temket"<<setw(20)<<right<<"January 19 Ethiopian Epiphany"<<endl;
            else if(i==2)
                cout<<setw(45)<<left<<"YEKATIT 23 Adwa"<<setw(20)<<right<<"March 2 - Victory of Adwa"<<endl;
            else if (i==3)
                cout<<setw(45)<<left<<"MEGABIT 28 Sekelet"<<setw(20)<<right<<"April 6 Ethiopian Good Friday"<<endl<<setw(45)<<left<<"MEGABIT 30 Tensase"<<setw(20)<<right<<"April 8 Ethiopian Easter"<<endl;
            else if (i==4)
                cout<<setw(45)<<left<<"MIYAZIA 23 Yelabaderoch Ken"<<setw(20)<<right<<"May 1 International Labour Day"<<endl<<setw(45)<<left<<"MIYAZIYA 27 Yedel Beal"<<setw(20)<<left<<"May 5 Ethiopian Patriots Day"<<endl<<
                setw(45)<<left<< "Ginbot 20 Yederg Aserar Yewedekebet"<<setw(20)<<right<<"May 29 Overthrow of the Deurge Regime"<<endl;
            else if (i==5)
                cout<<setw(45)<<left<<"Sene 8 Remedan"<<setw(20)<<right<<"June 15 Eid Al Fitr"<<endl;
            else if (i==7)
                cout<<setw(45)<<left<<"Nehase 15 Arefa"<<setw(20)<<right<<"August 21 Eid Al Adha"<<endl;
            else if (i==8)
                cout<<setw(45)<<left<<"Meskerem 1 Zemen Melewecha"<<setw(20)<<right<<"September 11 Ethiopian New Year"<<endl<<setw(45)<<left<<"Meskerem 17 Meskel"<<setw(20)<<right<<"September 27 Finding of the True Cross"<<endl;
            else if (i==11)
                cout<<setw(45)<<left<<"Hidar 11 Mawlid"<<setw(20)<<right<< "December 20 Mawlid"<<endl;
        }
        
        //Prompt to continue or not.
        cout << "Do you want to input another date? \n'1' for yes, '0' for no: ";
        cin >> ans;
    }
    while(ans!=0||(ans!=0&&year<0)||year<0);

    return weekDay;
}
