# Themenkreis 1: Auswertung von Sensor-Rohdaten.

**Gruppe:** 2

**Github repo:** https://github.com/fabianmuehlberger/pad2_project

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

## Projekt Ziel
Ziel ist eine Konsolen Aplikaton, die Sensordaten des Senshats, aus einer CSV Datei liest und diese daten auswertet. Es soll mithilfe der Daten ein Bewegungsprofil erstellt werden. Die daten sollen per Konsolen befehl ausgegeben werden können und auch visualisiert werden. 

## Tests

[test_main](../build/bin/test_main.exe) zeigt alle Source Files im Projekt. (cmake: build first)

## Libraries:

### Header Files:

[my_file_io.h](../common/include/my_file_io/my_file_io.h) 

[my_validation.h](../common/include/my_validation/my_validation.h)

[my_graphics.h](../common/include/my_graphics/my_graphics.h)

### Source Files:
[my_file_io.c](../common/src/my_file_io/my_file_io.c)

[my_graphics.c](../common/src/my_graphics/my_graphics.c)

[my_validation.c](../common/src/my_validation/my_validation.c)

## Rohdaten
[Data_sheet](../ressources/datasheet_LSM9DS1.pdf) Datenblatt des LSM9DS1

[test_data](../ressources/Test_Data_20k_IMU-LSM9DS1.csv) CSV Rohdaten 



## Projektmanagement

Projektfortschritt ist im Dokument [Protokoll](../documentation/protokoll.md) nachzulesen


## Projekt Struktur

 ```
-/build
    -/bin (executeables, dll´s)
    -/cmakeFile,
    -/more cmake files...

-/commom
    -/demo (Folder For all main.c files)
    -/include (Headers)
    -/src (Source Files)

-/documentation (Project Documentation)
    -/project_management (Prokject Management)

-/ressources (Daten , Datenblätter)

````

