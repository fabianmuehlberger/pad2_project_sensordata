/**
 * Header file fue eine wiederverwendbare Liste
 * @author    Markus Bader
 * @date      2020-05-05
**/

#ifndef DEMO_LIST_H
#define DEMO_LIST_H

/**
 * List entry
 **/
struct Entry{
    /// Pointer zum naechsten Knoten oder NULL beim letzten Knoten
    struct Entry *next;      
    /// Pointer zu den daten
    void *data;
};

/**
 * Fuegt ein element vorne an einer Liste an
 * @param head Pointer zum aktuellen Listenanfang bevor ein Element eingefuehgt wird
 * @param data pointer to the allocated new object
 * @return neuer head der List oder NULL bei Problemen
 **/
struct Entry* add(struct Entry* head, void *data);

/**
 * Gibt alle Eintraege der Liste aus
 * @param list Pointer zum aktuellen Listenanfang
 * @param print_data function pointer to a function which is able to print the data object
 **/
void print(const struct Entry* list, void (*print_data)(void*));

/**
 * Loeschte alle Eintraege der Liste und gibt den Speicher frei
 * @param list Pointer zum aktuellen Listenanfang
 * @param free_data function pointer to a function which is able to relase the data object
 **/
void clear(struct Entry* list, void (*free_data)(void*));

/**
 * List eine Namensliste
 * @param filename
 * @param read_data reads a single data line
 * @return neuer head der List oder NULL bei Problemen
 **/
struct Entry* read(const char *filename, void* (*read_data)(FILE*));

#endif // DEMO_LIST_H
