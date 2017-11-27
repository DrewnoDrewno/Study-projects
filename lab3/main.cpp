#include <iostream>
#include <sstream>
//#include <iostream.h>
using namespace std;
enum DayOfWeek
{
    sunday=0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday,
    saturday

};
class Data
{
public:

    Data(int year,int month, int day):Year(year),Month(month),Day(day)
    {}
    DayOfWeek DayInWords()
    {
        int days(0);
        for(int y(1582), m(1), d(1); y!=Year || m!=Month || d!=Day;) //piatek
        {
            if(m==1)
            {
                if(d==31)
                {
                    days++;
                    m++;
                    d=1;
                    continue;
                }
                days++; //to w forze?
                d++;

            }

            if(m==2)
            {

                if(y%4!=0 || (y%100==0 && y%400!=0))
                {

                    if(d==28)
                    {
                        days++;
                        m++;
                        d=1;continue;
                    }
                }
                if(y%4==0)
                {
                    if(d==29)
                    {
                        days++;
                        m++;
                        d=1;continue;
                    }
                }
                days++;
                d++;
            }

            if(m==3)
            {
                  if(d==31)
                {
                    days++;
                    m++;
                    d=1;continue;
                }
                days++;
                d++;

            }

            if(m==4)
            {
                if(d==30)
                {
                    days++;
                    m++;
                    d=1;continue;
                }
                days++;
                d++;

            }

            if(m==5)
            {
                if(d==31)
                {
                    days++;
                    m++;
                    d=1;continue;
                }
                days++;
                d++;

            }

            if(m==6)
            {
                if(d==30)
                {
                    days++;
                    m++;
                    d=1;continue;
                }
                days++;
                d++;

            }

            if(m==7)
            {
                if(d==31)
                {
                    days++;
                    m++;
                    d=1;continue;
                }
                days++;
                d++;

            }

            if(m==8)
            {
                if(d==31)
                {
                    days++;
                    m++;
                    d=1;continue;
                }
                days++;
                d++;

            }

            if(m==9)
            {
                if(d==30)
                {
                    days++;
                    m++;
                    d=1;continue;
                }
                days++;
                d++;

            }

            if(m==10)
            {
                if(d==31)
                {
                    days++;
                    m++;
                    d=1;continue;
                }
                days++;
                d++;
            }

            if(m==11)
            {
                if(d==30)
                {
                    days++;
                    m++;
                    d=1;continue;
                }
                days++;
                d++;

            }

            if(m==12)
            {
                if(d==31)
                {
                    days++;
                    m=1;
                    d=1;
                    y++;
                    continue;
                }
                days++;
                d++;
            }
        }
        int DayInWord=(days+5)%7;
        return (DayOfWeek)DayInWord;
       /*
       //pomy�ka,tu mysla�em �e ma zwr�ci� dzie� tygodnia s�ownie a nie jako enum :)
        switch(DayInWord)
        {
        case monday:
            cout<<"Monday"<<endl;
            break;

        case tuesday:
            cout<<"Tuesday"<<endl;
            break;

        case wednesday:
            cout<<"Wednesday"<<endl;
            break;

        case thursday:
            cout<<"Thursday"<<endl;
            break;

        case friday:
            cout<<"Friday"<<endl;
            break;

        case saturday:
            cout<<"Saturday"<<endl;
            break;

        case sunday:
            cout<<"Sunday"<<endl;
            break;
        }
        */
    }

    int WriteDay()
    {
        return Day;
    }

    int WriteMonth()
    {
        return Month;
    }

    int WriteYear()
    {
        return Year;
    }
    string format()
    {
        string hstring;
        stringstream hstream;
        string help;
        hstream<<Year;
        help=hstream.str();
        hstring+=help+" ";
        hstream.str("");
        switch(Month)
        {
        case 1:
            help="January ";
            break;

        case 2:
            help="February ";
            break;

        case 3:
            help="March ";
            break;

        case 4:
            help="April ";
            break;

        case 5:
            help="May ";
            break;

        case 6:
            help="June ";
            break;

        case 7:
            help="July ";
            break;

        case 8:
            help="August ";
            break;

        case 9:
            help="September ";
            break;

        case 10:
            help="October ";
            break;

        case 11:
            help="November ";
            break;

        case 12:
            help="December ";
            break;
        }

        hstring+=help;
        hstream<<Day;

        if(Day<10) hstring+='0';

        help=hstream.str();
        hstring+=help;
        return hstring;

    }
private:
    int Year,Month,Day;
};

bool IncorrectDay(int d,int m,int y)
{
            if(d<1)return 1;

            if(m==1)
            {
                if(d>31)
                {
                    return 1;
                }
            }

            if(m==2)
            {
                if(y%4!=0 || (y%100==0 && y%400!=0))
                {

                    if(d>28)
                    {
                     return 1;
                    }
                }
                if(y%4==0)
                {
                    if(d>29)
                    {
                       return 1;
                    }
                }
            }

            if(m==3)
            {
                  if(d>31)
                {
                    return 1;
                }
            }

            if(m==4)
            {
                if(d>30)
                {
                    return 1;
                }
            }

            if(m==5)
            {
                if(d>31)
                {
                    return 1;
                }
            }

            if(m==6)
            {
                if(d>30)
                {
                    return 1;
                }
            }

            if(m==7)
            {
                if(d>31)
                {
                    return 1;
                }
            }

            if(m==8)
            {
                if(d>31)
                {
                   return 1;
                }
            }

            if(m==9)
            {
                if(d>30)
                {
                   return 1;
                }
            }

            if(m==10)
            {
                if(d==31)
                {
                    return 1;
                }
            }

            if(m==11)
            {
                if(d>30)
                {
                   return 1;
                }
            }

            if(m==12)
            {
                if(d>31)
                {
                    return 1;
                }
            }
            return 0;
}
int main()
{
    int dday;
    int dyear;
    int dmonth;
    cout<<"Enter the year:"<<endl;
    cin>>dyear;
    while(cin.fail() || dyear<1582)
    {
        cout<<"Enter the correct year(above 1599):"<<endl;
        cin.clear();
        while(cin.get() != '\n');
        cin>>dyear;
    }
    while(cin.get() != '\n');

    cout<<"Enter a month:"<<endl;
    cin>>dmonth;
    while(cin.fail() || dmonth>12 || dmonth<1)
    {
        cout<<"Enter the correct month:"<<endl;
        cin.clear();
        while(cin.get()!='\n');
        cin>>dmonth;
    }
    while(cin.get()!='\n');

    cout<<"Enter the day"<<endl;
    cin>>dday;
    while(cin.fail() || IncorrectDay(dday,dmonth,dyear) )
    {
        cout<<"Enter the correct day:"<<endl;
        cin.clear();
        while(cin.get()!='\n');
        cin>>dday;
    }
    while(cin.get()!='\n');

    Data data(dyear,dmonth,dday);
    cout<<data.DayInWords()<<endl;
    cout<<data.format();
    return 0;
}
