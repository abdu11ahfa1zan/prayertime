# prayertime
This is a small c++ project i made that uses math and your coordinates to calculate prayer times.
## How it works:
uses this command: 
curl -s ipinfo.io | grep loc
to get your location via your IP. then it calculates the prayertimes via trigonometry based on your location.

## how to compile:
to compile, you need a c++ compiler, such as gcc or clang. this is the command i run to compile it myself:
g++ -std=c++20 pray.cpp -o Prayercalculator
to run it, type the path of the compiled binary and click enter. if it is in the same directory (folder) as you are, run it with a ./ before it. For example:
./Prayercalculator
if its in Downloads, do:
~/Downloads/Prayercalculator
i have a bunch of flags you can use: 
use the first letter of each prayer to get individual prayertime, such as -F for Fajr only. 

## This is the example output:
Fajr:         HH:MM AM/PM
Sunrise:      HH:MM AM/PM
Zuhr:         HH:MM PM/AM
Asr:          HH:MM PM/AM
Maghrib:      HH:MM PM/AM
Isha:         HH:MM PM/AM