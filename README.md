# prayertime

This is a small C++ project I made that uses math and your coordinates to calculate prayer times.

## How it works

Uses this command to get your location via your IP:

```bash
curl -s ipinfo.io | grep loc
```

Then it calculates the prayer times via trigonometry based on your location.

## How to compile

To compile, you need a C++ compiler, such as GCC or Clang. This is the command I run to compile it myself:

```bash
g++ -std=c++20 pray.cpp -o Prayercalculator
```

To run it, type the path of the compiled binary and press Enter. If it's in the same directory (folder) as you are, run it with a `./` before it. For example:

```bash
./Prayercalculator
```

If it's in Downloads, do:

```bash
~/Downloads/Prayercalculator
```

I have a bunch of flags you can use: use the first letter of each prayer to get an individual prayer time, such as `-F` for Fajr only.

## Example output

```
Fajr:         HH:MM AM/PM
Sunrise:      HH:MM AM/PM
Zuhr:         HH:MM PM/AM
Asr:          HH:MM PM/AM
Maghrib:      HH:MM PM/AM
Isha:         HH:MM PM/AM
```