/**
 * Header file fue eine wiederverwendbare Liste
 * @author    Markus Bader
 * @date      2020-05-05
**/

#ifndef DEMO_PERSON_H
#define DEMO_PERSON_H

#include <stdio.h>


/**
 * Struktur um einen Freund abzubilden
 **/
struct Person{
    /// Name des Freundes
    char *name;               
    /// Alter des Freundes
    int alter;                
};


/**
 * Creates and allocates a Person
 * @param name Name des neuen Feundes
 * @param alter Alter des neuen Freundes
 * @return pointer to the new Person or NULL on problems
 **/
struct Person* allocate_person(const char *name, int alter);

/**
 * prints a person
 * @param data pointer to the person
 **/
void print_person(void* data);


/**
 * releases the allocated memory related to a person
 * @param data pointer to an allocated person object
 **/
void free_person(void* data);

/**
 * reads a single line of a file to extract a person
 * @param file file pointer
 * @return pointer to the new Person or NULL on problems or eof
 **/
void* fscanf_person(FILE *file);


#endif // DEMO_PERSON_H
