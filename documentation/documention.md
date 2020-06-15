# Themenkreis 1: Auswertung von Sensor-Rohdaten.

**Gruppe:** 2

**Github repo:** https://github.com/fabianmuehlberger/pad2_project_sensordata

**Dokument stand:** 15.06.2020

- [Themenkreis 1: Auswertung von Sensor-Rohdaten.](#themenkreis-1-auswertung-von-sensor-rohdaten)
  - [Projektteilnehmer:](#projektteilnehmer)
  - [Hardware:](#hardware)
  - [Projekt Ziel:](#projekt-ziel)
  - [Projekmanagement:](#projekmanagement)
    - [Milesstones:](#milesstones)
    - [Erreichte Milestones:](#erreichte-milestones)
    - [File Lesen:](#file-lesen)
    - [Error Handling:](#error-handling)
  - [Externe Libraries/ Datenstrukturen:](#externe-libraries-datenstrukturen)
  - [Compilieren und Ausführen:](#compilieren-und-ausführen)
    - [Header Files:](#header-files)
    - [Source Files:](#source-files)
  - [Rohdaten:](#rohdaten)
  - [Code Conventions:](#code-conventions)
  - [Projekt Struktur](#projekt-struktur)

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

## Projekmanagement:

Um die Zusammenarbeit zu optimieren wurde beschlossen das Projekt als Github Projekt zu realisieren. Es wurden intern regeln vereinbahrt wie mit pushed, merges etz. umzugehen ist.  
Die Codebase wurde als CMAKE Projekt komzipiert und aufgebaut. Hierzu wurde ein Basisprojekt von Hr. Bader verwendet das and die Bedürfnisse des Projektes angepasst wurde. Wesentlich war für das Team war eine simple CMake Struktur, in die Weitere Source- und Headerfiles eingebunden werden konnten.  

### Milesstones:

 **Daten lesen:** Daten einlesen, aufbereiten und speichern
    * plausibiliätsprüfung 
    * Fehlerbehandlung / Bereinigung
* **Libraries:** Erstellen der Librarys 
* **Terminal Menü:** Simples Terminal Menü um einen Datenpunkt per Konsole auszugeben
* **Analyse:** Analyse der Daten. Datenpunkte über einen zeitraum zusammenführen und    vergleichen,
    * Erstellung eines Bewegungsprofils.
    * erstellung eines Weg-Zeit Diagramms
    * Beschleunigungs-Zeit Diagramms
* **(Stretch goal)** *muss erst auf machbarkeit geprüft werden* :Visualisierung der daten mithilfe von 
    * graphics.h  oder
    * OpenGL

### Erreichte Milestones:
[x] Daten Lesen, Aufbereiten und Speichern.  
[x] Plausibilitaetspruefung (Teilweise, exemplarisch).  
[x] Fehlerbehandlung (Schreiben eines Error Logs).
[x] Terminal Menü (exemplarisch).
[x] Libraries: Headerfiles und Sourcefieles wurden erstellt ud die Funktionen nach funktionalitaet getrennt aufgeteilt.

### File Lesen:
* Daten werden aus dem source.csv File geladen und durchlaufen Tests. 
* Die Daten werden in raw_data.csv gespeichert. Es wird eine Zeilennummer und ein Hinweis auf eventuelle Fehler hinzugefügt.
* aus raw_data.csv werden die daten erneut gelanden und verarbeitet
  * umwandlung von Hex in Dec
  * Verrechnung der Datensaetze um eine hoehere genauigkeit zu erreichen.
 
### Error Handling:
Schreiben eines error_log.csv Files:  
Zeilennummer | Fehlercode | Fehlertext
---------|----------|---------
 5 | 1 | Fehlender Seperationstoken

 Es werden folgende Tests durchgeführt:
  * Überprüfung auf ```\n``` jedes Zeilenendes
  * Anzahld der Seperationstokens ```;``` 

* *aus zeitmangel wurden keine sinnbringenden Test geschrieben*


## Externe Libraries/ Datenstrukturen:
* Die umrechnung der daten wurde von [ozzmaker](http://ozzmaker.com/) übernommen, umgeschrieben und für unsere zwaeke veraendert.
* Die Grundlegende Projektstruktur wurde von Hr. Bader zur verfügung gestellt. 

## Compilieren und Ausführen:
1. Git Repository Clonen oder Downloaden
2. Mit Cmake (min required Version 2.6) projekt builden. 
3. Die Ausführbare Datei befindet sich in .\build\bin\main_main.exe
4. Je nachdem wo das .exe File ausgeführt wird muss in der Main routine des programms der richtige Pfad gesetzt werden. Hierzu wurden 2 Versionen vorbereitet.  
    ```char errorLogFileName[NAMELEN] = "source_data.csv";```  
    ```char sourceFileName[NAMELEN] = "..\\..\\ressources\\source_data.csv";```   
    Die Formatierung des Pfades kann auch vom Betriebssystem abhaengig sein.

### Header Files:

[my_file_io.h](../common/include/my_file_io.h)
Funktionen zum einlesen und Verarbeten der csv Sensordaten  

[my_validation.h](../common/include/my_validation.h)
Check der Zeilen der Daten auf Vollständigkeit
 
[my_graphics.h](../common/include/my_graphics.h) Ausgabe und darstellung der Daten auf der Konsole

[my_helpers.h](../common/include/my_graphics.h) Hilfreiche standard Funktionalitäten

[my_structure.h](../common/include/my_graphics.h) Datenstrukuren für Rohdaten und Ausgewertete Daten 

### Source Files:
[my_file_io.c](../common/src/my_file_io.c)

[my_validation.c](../common/src/my_validation.c)

[my_graphics.c](../common/src/my_graphics.c)

[my_helpers.c](../common/src/my_validation.c)

[my_structure.c](../common/src/my_validation.c)

## Rohdaten:
[Data_sheet](../ressources/datasheet_LSM9DS1.pdf) Datenblatt des LSM9DS1

[test_data](../ressources/Test_Data_20k_IMU-LSM9DS1.csv) CSV Rohdaten 


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

