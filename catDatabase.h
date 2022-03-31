///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.h
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdbool.h>  // For the bool datatype
#include <stddef.h>   // For the size_t datatype
#include "config.h"
#define MAX_CAT_NAME (50)   /// This defines the size of the cat's name string

enum Gender { UNKNOWN_GENDER=0, MALE, FEMALE } ;
enum Breed { UNKNOWN_BREED=0, MAINE_COON, MANX, SHORTHAIR, PERSIAN, SPHYNX, SIAMESE };
enum Color { BLACK=0, WHITE, RED, BLUE, GREEN, PINK } ;

typedef float Weight ; //Typedef declaration of float->weight//

typedef unsigned long NumCats; //Typedef declaration of unsigned long ->NumCats

struct Catinfo {
    char name[MAX_CAT_NAME] ;
    enum Gender gender ;
    enum Breed breed ;
    bool isFixed ;
    Weight weight;
    enum Color collarColor1 ;
    enum Color collarColor2 ;
    unsigned long long license ;
};
extern struct Catinfo cats[MAX_CATS] ;

extern NumCats numCats ;  /// This points to the next available cat we can add to database



extern void initializeDatabase() ;

extern bool isFull() ;

extern bool validateDatabase();

extern bool isIndexValid( const NumCats index );

extern bool isNameValid( const char* name );

extern bool isWeightValid( const Weight weight );

extern void wipeCat( const NumCats index );

extern bool swapCat( const NumCats a, const NumCats b );
