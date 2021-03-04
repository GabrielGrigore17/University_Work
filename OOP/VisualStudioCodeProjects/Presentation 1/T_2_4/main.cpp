#include <ctime>
#include <iostream>
using namespace std;

void time_to_string(long long number_of_miliseconds){
    time_t now = time(0);
    now = number_of_miliseconds/1000;
    now += 315532800;
    tm *ltm = localtime(&now);
    cout << "" << 1900 + ltm->tm_year;
    cout << "-"<< 1 + ltm->tm_mon;
    cout << "-"<< ltm->tm_mday;
    cout << " "<< 5+ltm->tm_hour << ":";
    cout << 30+ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;

}
string time_to_string(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    
    cout << "" << 1900 + ltm->tm_year;
    cout << "-"<< 1 + ltm->tm_mon;
    cout << "-"<< ltm->tm_mday;
    cout << " "<< 5+ltm->tm_hour << ":";
    cout << 30+ltm->tm_min << ":";
    cout << ltm->tm_sec << endl;
}

int main()
{
    time_t now = time(0);
    cout<<endl;
    now -= 315532800; //number of seconds from 1970-1-1 00:00:00 to 1980-1-1 00:00:00
    cout<<now*1000<<" este numarul de de milisecunde masurate de la 1980-1-1 00:00:00."<<endl<<endl;

    time_to_string(now*1000);
    
    cout<<endl<<endl;

    cout<<time_to_string();


	return 0;
}