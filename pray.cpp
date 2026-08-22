#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <string>
#include <format>



int main(int argc, char* argv[]) {
    time_t now = time(0);
    tm* local = localtime(&now);

    int month = local->tm_mon + 1;  // just the month
    int day   = local->tm_mday;     // just the day
    
    
FILE* pipe = popen("curl -s ipinfo.io | grep loc", "r");  
char buffer[128];
std::string result = "";
 (fgets(buffer, sizeof(buffer), pipe) != NULL);
{     
    result += buffer;                                     
}
pclose(pipe);

// extract just the coordinates
int start = result.find("\"loc\": \"") + 8;
int end = result.find("\"", start);
std::string coords = result.substr(start, end - start); // "24.8608,67.0104"

// now split by comma
int commaPos = coords.find(",");
std::string lat = coords.substr(0, commaPos); 
std::string lon = coords.substr(commaPos + 1);

    double latitude = stod(lat);
    double longtitude = stod(lon);

//pi:
double pi = 3.14159265358979;
    //months
    int months[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int dayofyear = day;
    for (int i = 0; i < month - 1; i++) {
    dayofyear += months[i];
    }

    //solar declination
    double nn = 360.0/365 * (dayofyear - 81);
    double rad = nn * (3.14159265358979 / 180.0);
    double declination = sin(rad);
    double solardeclination = 23.45 * declination;
    
    //EoT
    double eot = 9.87 * sin(2 * rad) - 7.53 * cos(rad) - 1.5 * sin(rad); 
    
    //Duhr
    double duhr = 12 - (eot/60) - (longtitude - 75) / 15;
    double duhrdec;
    double decimal = modf(duhr, &duhrdec);
    //decimal = 0.574..
    //duhrdec = 12
    int zzzz = int(duhrdec);
    int zuhrmin = decimal * 60;
    std::string zuhrminStr;
    std::string zzzzStr;
    std::string zuhrAMPM;
    if(zzzz < 10) {
        zzzzStr = "0" + std::to_string(zzzz);
    }
    else {
        zzzzStr = std::to_string(zzzz);
    }
    if(zzzz < 12) {
        zuhrAMPM = "AM";
    }
    else {
        zuhrAMPM = "PM";
    }
    if(zuhrmin < 10) {
           zuhrminStr = "0" + std::to_string(zuhrmin);
    }
    else {
        zuhrminStr = std::to_string(zuhrmin);
    }
    std::string zuhrtime = zzzzStr + ":" + zuhrminStr + " " + zuhrAMPM;

    //fajr:::
    double fajr = (sin(-18.0 * pi/180.0) - sin(latitude * pi/180.0) * sin(solardeclination * pi/180.0)) / (cos(latitude * pi/180.0) * cos(solardeclination * pi/180.0));
    double fajr1 = acos(fajr) * (180.0 / pi);
    double fajrtime = duhr - (fajr1 / 15.0);
    double fajrdec;
    double decimalfajr = modf(fajrtime, &fajrdec);
    int fajrmin = decimalfajr * 60;
    int ffff = int(fajrdec);
    std::string ffffStr;
    std::string fajrminStr;
    if(ffff < 10) {
        ffffStr = "0" + std::to_string(ffff);
    }
    else {
        ffffStr = std::to_string(ffff);
    }
    if(fajrmin < 10) {
        fajrminStr = "0" + std::to_string(fajrmin);
    }
    else {
        fajrminStr = std::to_string(fajrmin);
    }
    std::string fajrTIME = ffffStr + ":" + fajrminStr + " AM";

    //isha:::
    double ishatime = duhr + (fajr1 / 15.0);
    double ishadec;
    double decimalisha = modf(ishatime, &ishadec);
    int ishadec1 = ishadec - 12;
    int ishamin = decimalisha * 60;
    int iiii = int(ishadec1);
    std::string iiiiStr;
    std::string ishaminStr;
    if(iiii < 10) {
        iiiiStr = "0" + std::to_string(iiii);
    }
    else {
        iiiiStr = std::to_string(iiii);
    }
    if(ishamin < 10) {
     ishaminStr = "0" + std::to_string(ishamin);
    }
    else {
        ishaminStr = std::to_string(ishamin);
    }
    std::string ishaTIME = iiiiStr + ":" + ishaminStr + " PM";

    //maghrib
    double maghrib = (sin(-0.833 * pi/180.0) - sin(latitude * pi/180.0) * sin(solardeclination * pi/180.0)) / (cos(latitude * pi/180.0) * cos(solardeclination * pi/180.0));
    double maghrib1 = acos(maghrib) * (180.0 / pi);
    double maghribtime = duhr + (maghrib1 / 15.0);
    double maghribdec;
    double decimalmaghrib = modf(maghribtime, &maghribdec);
    int maghribdec1 = maghribdec - 12;
    int maghribmin = decimalmaghrib * 60;
    std::string mmmmStr;
    std::string maghribminStr;
    int mmmm = int(maghribdec1);
    if(mmmm < 10) {
        mmmmStr = "0" + std::to_string(mmmm);
    }
    else {
        mmmmStr = std::to_string(mmmm);
    }
    if(maghribmin < 10) {
        maghribminStr = "0" + std::to_string(maghribmin);
    }
    else {
        maghribminStr = std::to_string(maghribmin);
    }
    std::string maghribTIME = mmmmStr + ":" + maghribminStr + " PM";    
    
    //sunrise, similiar to maghrib
    double sunrisetime = duhr - (maghrib1 / 15.0);
    double sunrisedec;
    double decimalsunrize = modf(sunrisetime, &sunrisedec);
    int sunrisemin = decimalsunrize * 60;
    int ssss = int(sunrisedec);
    std::string ssssStr;
    std::string sunriseminStr;
    if(ssss < 10) {
        ssssStr = "0" + std::to_string(ssss);
    }
    else {
        ssssStr = std::to_string(ssss);
    }
    if(sunrisemin < 10) {
        sunriseminStr = "0" + std::to_string(sunrisemin);
    }
    else {
        sunriseminStr = std::to_string(sunrisemin);
    }
    std::string sunriseTIME = ssssStr + ":" + sunriseminStr + " AM"; 

    //asr
    double asrangle = atan(1.0 / (2.0 + tan((latitude - solardeclination) * pi/180.0))) * (180.0 / pi);
    double asr = (sin(asrangle * pi/180.0) - sin(latitude * pi/180.0) * sin(solardeclination * pi/180.0)) / (cos(latitude * pi/180.0) * cos(solardeclination * pi/180.0));
    double asr1 = acos(asr) * (180.0 / pi);
    double asrtime = duhr + (asr1 / 15.0);
    int hours = (int)asrtime - 12;
    int minutes = (int)((asrtime - (int)asrtime) * 60);
    std::string hoursStr;
    std::string minStr;
    if(hours < 10) {
        hoursStr = "0" + std::to_string(hours);
    }
    else {
        hoursStr = std::to_string(hours);
    }
    if(minutes < 10) {
        minStr = "0" + std::to_string(minutes);
    }
    else {
        minStr = std::to_string(minutes);
    }
    std::string asrTIME = hoursStr + ":" + minStr + " PM";

// 

if (argc == 1) {
std::cout << "Fajr:         " << fajrTIME << '\n' 
          << "Sunrise:      " << sunriseTIME << '\n' 
          << "Zuhr:         " << zuhrtime << '\n' 
          << "Asr:          " << asrTIME << '\n' 
          << "Maghrib:      " << maghribTIME << '\n' 
          << "Isha:         " << ishaTIME << '\n';
}
else {
    std::string arg = argv[1];   

    if (arg == "-z") {
    std::cout << zuhrtime;
 }
 else if (arg == "-f") {
    std::cout << fajrTIME;
 }
 else if (arg == "-a") {
    std::cout << asrTIME;
 }
else if (arg == "-m") {
    std::cout << maghribTIME;
 }
else if (arg == "-s") {
    std::cout << sunriseTIME;
 }
 else if (arg == "-i") {
    std::cout << ishaTIME;
 }
 else if (arg == "-h") {
        std::cout << "You reached help." 
          << '\n' << "Use the first letter of each prayer with a dash" 
          << '\n' << " to get it's individual time. such as -z for"
          << '\n' << "Zuhr. (not capital). Use no flag for all prayers." << '\n';  }
 else {
        std::cout << "You gave a wrong flag so You reached help." 
          << '\n' << "Use the first letter of each prayer with a" 
          << '\n' << "dash to get it's individual time. such as"
          << '\n' << "-z for Zuhr. (not capital)" << '\n'; 
 }
 }
return 0;
}
