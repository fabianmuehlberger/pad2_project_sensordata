# Themenkreis 1: Auswertung von Sensor-Rohdaten.

**Gruppe:** 2

**Github repo:** https://github.com/fabianmuehlberger/pad2_project_sensordata

**Dokument stand:** 19.05.2020

## Projektteilnehmer:

* Lucas Schmirl
* Shengen Gao
* Fabian Mühlberger

## Hardware:
Raspberry-Pi, Sense Hat

LSM9DS1 - iNEMO inertial module:
* 3D accelerometer,
* 3D gyroscope, 
* 3D magnetometer

## Projekt Ziel:
Ziel ist eine Konsolen Aplikaton, die Sensordaten des Senshats, aus einer CSV Datei liest und diese daten auswertet. Es soll mithilfe der Daten ein Bewegungsprofil erstellt werden. Die daten sollen per Konsolen befehl ausgegeben werden können und auch visualisiert werden. 

## Tests:

[test_main](../build/bin/test_main.exe)   
  * zeigt alle Source Files im Projekt. 
  * Überprüfung der Lese und Schreibe Funktionen mithilfe eines Testfiles

## Libraries:

### Header Files:

[my_file_io.h](../common/include/my_file_io.h)  
Funktionen zum einlesen und Verarbeten der csv Sensordaten  

[my_validation.h](../common/include/my_validation.h)  
Check der Zeilen der Daten auf Vollständigkeit
  * Überprüfung auf ```\n``` jedes Zeilenendes
  * Anzahld der Seperationstokens ```;``` 
  * Überprüfung der Werte auf Plausibilität

[my_graphics.h](../common/include/my_graphics.h)  
Ausgabe und darstellung der Daten auf der Konsole

[my_helpers.h](../common/include/my_graphics.h)  
Hilfreiche standard Funktionalitäten

[my_structure.h](../common/include/my_graphics.h)  
Datenstrukuren 

### Source Files:
[my_file_io.c](../common/src/my_file_io.c)

[my_validation.c](../common/src/my_validation.c)

[my_graphics.c](../common/src/my_graphics.c)

[my_helpers.c](../common/src/my_validation.c)

[my_structure.c](../common/src/my_validation.c)

## Rohdaten:
[Data_sheet](../ressources/datasheet_LSM9DS1.pdf) Datenblatt des LSM9DS1

[test_data](../ressources/Test_Data_20k_IMU-LSM9DS1.csv) CSV Rohdaten 

## Strategie:

#### File Lesen:

## Aufwandsabschätzung:




## Projektmanagement

Projektfortschritt ist im Dokument [project_update](../documentation/project_update.md) nachzulesen


## Code Conventions:

[GNU Style Convention:](https://developer.gnome.org/programming-guidelines/stable/c-coding-style.html.en)

Item | Convention | 
---------|----------
 Struct    |          ```TitleCase```
 Struct Members | ```lower_case``` or ```lowerCase```
 Functions | ```TitleCase``` or ```pfx_TitleCase``` (pfx = two or three letter module prefix)
 Trivial variables  | ```i``` or ```x```, etc...
 Local variables | ```lower_case``` or ```lowerCase```


## Projekt Struktur

 ```
./build (cmake generated files)
    ./bin (executeables, dll´s)
    ./cmakeFile,
    ./more cmake files...

./commom
    ./demo (Folder For all main.c files)
    ./include (Headers)
    ./src (Source Files)

./documentation (Project Documentation)
    ./project_management (usefull stuff for the Project)

./ressources (Daten , Datenblätter)

```

