#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
//!Write the appropriate getter and setter functions for these member variables. Also write stream operator for
//!output. Show output in some reasonable manner.
class PersonData{
    protected:
    string first_name;
    string last_name;
    string email;
    unsigned int house_no;
    char block;
    string city;
    public:
    void set_first_name(string first_name){ this->first_name=first_name;}
    string get_first_name(){return first_name;}
    void set_last_name(string last_name){this->last_name=last_name;}
    string get_last_name(){return last_name;}
    void set_email(string email){this->email=email;}
    string get_email(){return email;}
    void set_house_no(unsigned int house_no){this->house_no=house_no;}
    unsigned int get_house_no(){return house_no;}
    void set_block(char block){
        if(!(block<'A'||block>'Z')) this->block=block;
        else cout<<"Enter Valid Block";
        }
    char get_block(){return block;}
    void set_city(string city){
        city.erase(remove(city.begin(), city.end(), ' '), city.end());
        this->city=city;}
    string get_city(){return city;}
    
};
class CustomerData:public PersonData{
    protected:
    static unsigned int counter;
    int customer_number;
    bool Email_allowed_or_not;
    public:
    CustomerData(){customer_number=counter++;}
    int get_customer_no(){return customer_number;}
    bool get_Email_allowed_or_not(){return Email_allowed_or_not;}
    void set_Email_allowed_or_not(bool Email_allowed_or_not){this->Email_allowed_or_not=Email_allowed_or_not;}
};
unsigned int CustomerData::counter=1;
ostream & operator << (ostream &out, PersonData x){
    out<<"Name :"<<x.get_first_name()<<' '<<x.get_last_name()<<endl;
    out<<"Email :"<<x.get_email()<<endl;
    out<<"House No:"<<x.get_house_no()<<endl;
    out<<"Block :"<<x.get_block()<<endl;
    out<<"City :"<<x.get_city()<<endl;
    return out;
}
ostream & operator << (ostream &out, CustomerData &x){
    out<<(PersonData)x;
    out<<"Customer No :-"<<x.get_customer_no()<<endl;
    out<<"Email allowed? :";
    if(x.get_Email_allowed_or_not()==true) out<<"Yes\n";
    else out<<"No\n";
    return out;
}
istream & operator >> (istream &in,CustomerData &c){ 
    string x;int y;char z;
    cout<<"Enter First Name ";in>>x;c.set_first_name(x);
    cout<<"Enter Last Name ";in>>x;c.set_last_name(x);
    cout<<"Enter Email ";in>>x;c.set_email(x);
    cout<<"Enter House No. ";in>>y;c.set_house_no(y);
    cout<<"Enter Block ";in>>z;c.set_block(z);
    cout<<"Enter City ";in>>x;c.set_city(x);
    return in; 
} 
int main(){
    string x;
    CustomerData Jojo[5];
    cin>>Jojo[4];
    cout<<Jojo[4];
    cout<<endl;
    cout<<"Do you wish to be on the mailing list.Y/N ";
    cin>>x;
    if(x.compare("Y")==0)     Jojo[4].set_Email_allowed_or_not(true);
    else if (x.compare("N")==0) Jojo[4].set_Email_allowed_or_not(false);
    cout<<endl;
    cout<<Jojo[4]; 
}