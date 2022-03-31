///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file addCats.cpp
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   19_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "addCats.h"
#include <string.h>   // For strcpy
#include <stdio.h>

#include "config.h"
#include "catDatabase.h"
#include "addCats.h"
bool isCatInDatabase( const char* name ) {
    for( size_t i = 0 ; i < numCats ; i++ ) {
        if( strncmp( cats[i].name, name, MAX_CAT_NAME ) == 0 ) {
            return true;
        }
    }

    return false; //name not found
}




///Adding a cat to database



unsigned int addCat( const char* name
        ,const enum Gender gender
        ,const enum Breed breed
        ,const bool isFixed
        ,const float weight
        ,const enum Color collarColor1
        ,const enum Color collarColor2
        ,const unsigned long long license
) {
    if( isFull() ) {  // The database is full
        return BAD_CAT ;
    }

    if( isCatInDatabase( name ) ) {
        fprintf( stderr, "%s: Cat name [%s] is already in the database.\n", PROGRAM_NAME, name ) ;
        return BAD_CAT ;
    }

    if( !isWeightValid( weight )) {
        return BAD_CAT ;
    }


    // Add cat

    NumCats catIndex = numCats;

    strncpy( cats[catIndex].name, name, MAX_CAT_NAME ) ;
    cats[catIndex].gender = gender  ;
    cats[catIndex].breed = breed   ;
    cats[catIndex].isFixed = isFixed ;
    cats[catIndex].weight = weight  ;
    cats[catIndex].collarColor1 = collarColor1 ;
    cats[catIndex].collarColor2 = collarColor2 ;
    cats[catIndex].license = license ;


#ifdef DEBUG
    printf( "%s: Added cat [%s] as [%lu]\n", PROGRAM_NAME, name, catIndex );
#endif


    numCats += 1;

    return catIndex;
}