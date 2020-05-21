# Project Update

## Strategien:
Folgend werden die Strategien und Lösungsansätze beschrieben.

#### Files:

* Config File gibt die Struktur des CSV Files an.
  * Spaltennamen
  * Datentypen pro Spalte
  * länge je Spalte
* Speicherung der Daten (2 Möglichkeiten):
  * Erstellung einer Struktur für die Datenmenge, oder (falls daten zu groß) erstellung eines teils der Datenstruktur
  * Erstellung eines Neuen CSV Files mit zusätzlichen Daten wie Zeilennummer, Fehler, Beschriftung, etz. und ein späteres bearbeiten zu erleichtern.
* CSV FIle wird zeilenweise von einem Parser gelesen. 
  

#### Validation:

* Überprüfung des CSV FILES 
  * Zeilen Anzahl.
  * Datenmenge (bites).
* Überprüfung einer Zeile:
  * Check auf:  ```'\n'```
  * Zählen der Seperationszeichen pro Zeile: ```;```
* Überprüfung der Felder mit Hilfe des Config Files ```file_config```
  * Menge an Zeichen 
  * Datentyp
  * Lesbar

#### Error handling:

* Schreiben eines Log Files: Enthält alle Zeilen in denen Fehler gefunden werden. 
  * Zeilennummer
  * Fehlerart
  * Spalte
  

