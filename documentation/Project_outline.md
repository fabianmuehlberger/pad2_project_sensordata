# Themenkreis 1: Auswertung von Sensor-Rohdaten.

## Projektteilnehmer:

* Lucas Schmirl
* Shengen Gao
* Fabian Mühlberger

## Hardware:
Raspberry-Pi, Sense Hat

## Used sensor:
LSM9DS1 - iNEMO inertial module:
* 3D accelerometer,
* 3D gyroscope, 
* 3D magnetometer

## Projektmanagement:

Alle Mitarbeiter sind am Projekt gleichberechtigt und mit ihrer Leistung für die Erfüllung verantwortlich.

Der zeitliche Ablauf sieht vor, dass bis zum 14.5.2020 die Hauptparameter des Projektes definiert sind. Ebenso soll die Dateistruktur in seinen Grundzügen festgelegt sein, da dies, neben der Funktionalität, ein wesentlicher Faktor für die Erfüllung der Projektvorgaben ist.
Eine weitere Abschätzung der Milestones ist zum derzeitigen Stand nicht möglich und wird mitgeilt sobald eine realistische Zeiteinschätzung möglich ist.

Die Programmier-Aufgaben werden je nach Bedarf und fachlicher Kompetenz der Mitarbeiter verteilt und obliegen den drei Mitarbeitern gleichermaßen.

Eine genauere Untersuchung der vorliegenden Rohdaten war bis zum derzeitigen Datum nicht möglich. Deshalb sind sowohl Änderungen an den Projektspezifikationen als auch die Methode der Umsetzung nicht ausgeschlossen.

## Gemeinschafts-Funktionsbibliothek:
Um ein gemeinschaftliches Arbeiten zu ermöglichen wird Git bzw. GitHub verwendet. Durch die Versionskontrolle wird sichergestellt, dass alle Mitarbeiter parallel an verschiedenen Aufgaben arbeiten können.

Um ein Kompilieren der source Files zu erleichtern und plattformübergreifend arbeiten zu können ist das Projekt zusätzlich als CMake Projekt konzipiert.

Die Projektstruktur beinhaltet sowohl alle CMake Daten, Projekt-Ressourcen, Dokumentation als auch zusätzliche Libraries die vom Team erstellt werden.

## Funktionsweise:
Angedacht ist eine Test Applikation, welche Beschleunigung- und Magnetometer Daten an ein Visualisierungsprogramm übermittelt und grafisch aufbereitet. Dies ist jedoch nur als stretch Goal gedacht falls es die zeitlichen Ressourcen ermöglichen.

Das Programm liest die Sensordaten des LSM9DS1 und speichert diese in einer Struktur.

Es soll aus den Gyroskop-, Beschleunigungs- und Magnetometer-daten ein Bewegungsprofil erstellt werden.

Falls die Daten eine entsprechende Auswertung zulassen, soll ein Weg-Zeit Profil der Daten erstellt werden.

Ausgewählt werden die Funktionen über ein simples Konsolen Menü.

## Tests:
Die Daten werden durch Hilfs Funktionen auf Plausibilität geprüft, um eventuelle “Ausreißer” zu erkennen.

Falls möglich soll auch eine manuelle Überprüfung der Daten stattfinden. Dies soll als Referenz-Modus dienen.
* Der Sensor wird physisch positioniert und alle Werte werden genullt.
* Dem System wird ein Koordinaten-Nullpunkt (3D) definiert.
* Die Messwerte werden in Bezug zum Koordinaten-Nullpunkt dargestellt.
 
## Dokumentation 
Die Dokumentation wird mithilfe eines simplen markdown Files (.md) erzeugt. Geplant ist eine Beschreibung der wesentlichen Funktionen in der Dokumentation um einen Überbick über Programm und Funktionen zu bieten.  Grundsätzlich wird die Beschreibung der Funktionen in den Funktionsprotoypen stattfinden.

## File Struktur

|Order |Inhalt  |
|--|--|
|/.build	|von CMake gebuildeten Projektdatein  |
|/dist 		|fertige execute Files | 
|/doc 		|Dokumentation |
|/recources |Rohdaten  
|/src		|source Files, Libraries






