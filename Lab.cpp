#include <cmath>
#include <cstdio>
#include <iomanip>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Time12Hours{
    int hours, minutes, seconds;
    char half;
    
    public:
    //Constructors
    Time12Hours(char dem){
        set_hour(1);
        set_minutes(0);
        set_seconds(0);
        set_half(dem);
    }
    Time12Hours(char dem, int h){
        set_hour(h);
        set_minutes(0);
        set_seconds(0);
        set_half(dem);
    }
    Time12Hours(char dem, int h, int m){
        set_hour(h);
        set_minutes(m);
        set_seconds(0);
        set_half(dem);
    }
    Time12Hours(char dem, int h, int m, int s){
        set_hour(h);
        set_minutes(m);
        set_seconds(s);
        set_half(dem);
    }
    
    //Copy Constructor
    Time12Hours(const Time12Hours &t){
        set_hour(t.hours);
        set_minutes(t.minutes);
        set_seconds(t.seconds);
        set_half(t.half);
    }
    
    //Setters
    void set_hour(int hour){
        if(hour>=1 && hour<=12){
            hours=hour;
        }
    }
    void set_minutes(int min){
        if(min>=0 && min<=59){
            minutes = min;
        }
    }
    void set_seconds(int sec){
        if(sec>=0 && sec<=59){
            seconds = sec;
        }
    }
    void set_half(char dem){
        if(dem=='A' || dem=='P'){
            half = dem;
        }
    }
        
    //Misc
    void increment_hours(int incr){
        if((incr+hours)>12){
            hours = (incr + hours)-12;
            if(half=='A'){
                half = 'P';
            }else{
                half = 'A';
            }
        }else{
            hours = incr + hours;
        }
    }
    
    void increment_minutes(int incr){
        if((incr+minutes)>=60){
            minutes = (incr + minutes) - 60;
            increment_hours(1);
        }else{
            minutes = incr + minutes;
        }
    }
    
    void increment_seconds(int incr){
        if((incr+seconds)>=60){
            seconds = (incr + seconds) - 60;
            increment_minutes(1);
        }else{
            seconds = incr + seconds;
        }
    }  
    
    void show(){
        cout<<hours<<":"
            <<setw(2)<<setfill('0')<<minutes<<":"
            <<setw(2)<<setfill('0')<<seconds<<" "
            <<half<<"M"<<endl;
    }
};

Time12Hours creator(){
    int hr, min, sec, sel;
    char dem;
    
    cin >> sel;
    if(sel==1){
        cin >> dem;
        Time12Hours t(dem);
        return t;
    }
    if(sel==2){
        cin >> dem >> hr;
        Time12Hours t(dem, hr);
        return t;
    }
    if(sel==3){
        cin >> dem >> hr >> min;
        Time12Hours t(dem, hr, min);
        return t;
    }
    if(sel==4){
        cin >> dem >> hr >> min >> sec;
        Time12Hours t(dem, hr, min, sec);
        return t;
    }
    return NULL;
}

int main() {
    Time12Hours t1 = creator(); t1.show();
    Time12Hours t2 = creator(); t2.show();    
    Time12Hours t3 = creator(); t3.show();
    Time12Hours t4 = creator(); t4.show();
    
    int sel, sel2, sel3;
    cin >> sel;
    for(int i=0; i<sel; i++){
        cin>>sel2;
        if(sel2==1){
            cin>>sel2>>sel3;
            if(sel2==1) t1.increment_hours(sel3);
            else if(sel2==2) t1.increment_minutes(sel3);
            else if(sel2==3) t1.increment_seconds(sel3);
            t1.show();
            
        }else if(sel2==2){
            cin>>sel2>>sel3;
            if(sel2==1) t2.increment_hours(sel3);
            else if(sel2==2) t2.increment_minutes(sel3);
            else if(sel2==3) t2.increment_seconds(sel3);  
            t2.show();
            
        }else if(sel2==3){
            cin>>sel2>>sel3;
            if(sel2==1) t3.increment_hours(sel3);
            else if(sel2==2) t3.increment_minutes(sel3);
            else if(sel2==3) t3.increment_seconds(sel3); 
            t3.show();
            
        }else if(sel2==4){
            cin>>sel2>>sel3;
            if(sel2==1) t4.increment_hours(sel3);
            else if(sel2==2) t4.increment_minutes(sel3);
            else if(sel2==3) t4.increment_seconds(sel3); 
            t4.show();
        }
    }
    
    return 0;
}