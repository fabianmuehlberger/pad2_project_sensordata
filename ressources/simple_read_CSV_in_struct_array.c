/* Einlesen einer Datei in ein struct Array und Speichern der Daten
   Der benötigte Speicher wird dynamisch allokiert */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUFLEN 1024

struct Record         // Values Temp und Press in Hex
{
    double timestamp; // Zeitstempel in Sekunden (LINUX)
    int TEMP_OUT_L;  // Temperatur LSB   (°F)
    int TEMP_OUT_H;  // Temperatur MSB
    int PRESS_OUT_XL;// Druck LSB       (hPa)
    int PRESS_OUT_L; // Druck Mid Part
    int PRESS_OUT_H; // Druck MSB
};


void print_struct_array(struct Record *temp_Record, int numb_Records)     // Ausgabe von numb_Records
{
    for (int numb = 1; numb<numb_Records; numb++)
    {
        printf(" %f, %d, %d, %d, %d, %d \n",temp_Record[numb-1].timestamp,temp_Record[numb-1].TEMP_OUT_L,temp_Record[numb-1].TEMP_OUT_H,temp_Record[numb-1].PRESS_OUT_XL,temp_Record[numb-1].PRESS_OUT_L,temp_Record[numb-1].PRESS_OUT_H);
    }
}

struct Record *read_source(char *filename_read)          // Einlesen der Daten und Speichern in struct Array
{

    char line[BUFLEN];

    char field_delim[] = ";";
    char *p_field_search;                               // pointer für die Funktion strtok

    int numb = 1;                                       // number of Record

    struct Record *temp_Record = malloc(sizeof(struct Record));    // Speicher für das erste Feld im Array
    if (temp_Record == NULL)
    {
        printf("No memory available");
        exit(-1);
    }

    FILE *open_file = fopen(filename_read, "r");
    if (NULL==open_file)
    {
        printf("could not open %s",open_file);
        exit(-1);
    }
    while (fgets(line, BUFLEN, open_file)!=NULL)                       // zeilenweises Einlesen - ACHTUNG auf line Delimiter im Source File
    {
        printf("%s",line);
        temp_Record = realloc(temp_Record,numb*sizeof(struct Record));      // vergrößern des Speichers bei jedem Record
        if (temp_Record == NULL)
        {
            printf("No memory available");
            exit(-1);
        }

        p_field_search = strtok(line,field_delim);                           // 1. Feld in line
        temp_Record[numb-1].timestamp = atof(p_field_search);

        p_field_search = strtok(NULL,field_delim);
        temp_Record[numb-1].TEMP_OUT_L = (int)strtol(p_field_search, NULL, 16);

        p_field_search = strtok(NULL,field_delim);
        temp_Record[numb-1].TEMP_OUT_H = (int)strtol(p_field_search, NULL, 16);

        p_field_search = strtok(NULL,field_delim);
        temp_Record[numb-1].PRESS_OUT_XL = (int)strtol(p_field_search, NULL, 16);

        p_field_search = strtok(NULL,field_delim);
        temp_Record[numb-1].PRESS_OUT_L = (int)strtol(p_field_search, NULL, 16);

        p_field_search = strtok(NULL,field_delim);
        temp_Record[numb-1].PRESS_OUT_H = (int)strtol(p_field_search, NULL, 16);

        numb++;
    }


    fclose(open_file);

    temp_Record = realloc(temp_Record,numb*sizeof(struct Record));
    temp_Record[numb-1].timestamp = 0.0;                            // sicherstellen, dass am Ende des Arrays 0.0 im timestamp steht

    print_struct_array(temp_Record, numb);
    return(temp_Record);
}

void write_struct_array(struct Record *temp_Record, char *filename_write, int numb_Records)
{
    FILE *open_file = fopen(filename_write, "w+");
    if (NULL==open_file)
    {
        printf("could not open %s",open_file);
        exit(-1);
    }

    for (int numb = 1; numb<=numb_Records; numb++)
    {
        fprintf(open_file,"%f;%x;%x;%X;%X;%X\n",temp_Record[numb-1].timestamp,temp_Record[numb-1].TEMP_OUT_L,temp_Record[numb-1].TEMP_OUT_H,temp_Record[numb-1].PRESS_OUT_XL,temp_Record[numb-1].PRESS_OUT_L,temp_Record[numb-1].PRESS_OUT_H);
    }
    fclose(open_file);
}

int count_Records(struct Record *All_Records)
{
    int i = 0;
    while(All_Records[i].timestamp > 0.0)       // ACHTUNG!! setzt voraus, dass wirklich 0.0 im letzten timestamp steht
    {
        i++;
    }
    return i;
}

int main()
{
    char filename_read[] = "Test_Data_45_LPS25_02.csv";     // Datei zum Einlesen
    char filename_write[] = "write_test.txt";    // Datei zum Schreiben

    struct Record *All_Records;                  // Pointer auf Startadresse des Arrays

    All_Records = read_source(filename_read);    // Einlesen der Daten

    int numb_Records = count_Records(All_Records);    // Zählen der Records

    print_struct_array(All_Records, numb_Records);    // Ausgabe von numb_Records des Arrays

    write_struct_array(All_Records, filename_write, numb_Records);   // Schreiben der Daten in neue Datei

    free(All_Records);                                // Speicher freigeben

    return 0;
}
