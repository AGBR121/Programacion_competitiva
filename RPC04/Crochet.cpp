#include<bits/stdc++.h>
using namespace std;

int dayIndex(string day){
    if(day == "Mon") return 0;
    if(day == "Tue") return 1;
    if(day == "Wed") return 2;
    if(day == "Thu") return 3;
    if(day == "Fri") return 4;
    if(day == "Sat") return 5;
    return 6; // Sun
}

int main(){
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    string day1 = s1.substr(0, 3);
    int h1 = stoi(s1.substr(4, 2));
    int m1 = stoi(s1.substr(7, 2));

    string day2 = s2.substr(0, 3);
    int h2 = stoi(s2.substr(4, 2));
    int m2 = stoi(s2.substr(7, 2));

    int total1 = dayIndex(day1) * 24 * 60 + h1 * 60 + m1;
    int total2 = dayIndex(day2) * 24 * 60 + h2 * 60 + m2;

    int diff = total2 - total1;
    if(diff < 0) diff += 7 * 24 * 60; 

    int days    = diff / (24 * 60);
    int hours   = (diff % (24 * 60)) / 60;
    int minutes = diff % 60;

    vector<string> parts;
    if(days > 0)
        parts.push_back(to_string(days) + (days == 1 ? " day" : " days"));
    if(hours > 0)
        parts.push_back(to_string(hours) + (hours == 1 ? " hour" : " hours"));
    if(minutes > 0)
        parts.push_back(to_string(minutes) + (minutes == 1 ? " minute" : " minutes"));

    if(parts.size() == 3)
        cout << parts[0] << ", " << parts[1] << ", " << parts[2];
    else if(parts.size() == 2)
        cout << parts[0] << " and " << parts[1];
    else if(parts.size() == 1)
        cout << parts[0];

    cout << endl;
    return 0;
}