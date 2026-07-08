#include <iostream>
#include <string>

using namespace std;

int main()
{
string s1="As time by...", s2="goes ";
cout << "Original: " << s1 << endl;

int pos_by=s1.find("by");

s1.insert(pos_by,s2);
cout << "s2 insertada: "<< s1 << endl;

s1.erase(pos_by);
cout << "Erased from by : "<< s1 << endl;


int pos_time=s1.find("time");
string s3="Bill";
s1.replace(pos_time,4,s3);
cout << "Replacement done : "<< s1 << endl;


    return 0;
}