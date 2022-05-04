///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.cpp
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "reportCats.h"

#include <stdio.h>
#include <string.h>  /// For strncmp
#include <assert.h>
#include "reportCats.h"
#include "catDatabase.h"

void printCat( const NumCats index ) {
    if( !isIndexValid( index ) ) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
        return;
    }

    printf( "cat index = [%lu]  name=[%s]  gender=[%s]  breed=[%s]  isFixed=[%d]  weight=[%f] color1=[%s] color2=[%s] license=[%lld]\n"
            ,index
            ,cats[index].name
            ,genderName( cats[index].gender )
            ,breedName( cats[index].breed )
            ,cats[index].isFixed
            ,cats[index].weight
            ,colorName( cats[index].collarColor1)
            ,colorName( cats[index].collarColor2)
            ,cats[index].license
    ) ;       }

void printAllCats() {
#ifdef DEBUG
    printf( "numCats = [%lu]\n", numCats );
#endif

    for( NumCats i = 0 ; i < numCats ; i++ ) {
        printCat( i );
    }
}


NumCats findCat( const char* name ) {
    if( name == NULL ) {
        return BAD_CAT ;
    }


    for( NumCats i = 0 ; i < numCats ; i++ ) {
        if( strncmp( name, cats[i].name, MAX_CAT_NAME ) == 0 ) {  // Found a match!
            return i;
        }
    }

    return BAD_CAT ;
}




const char* genderName( const enum Gender gender ) {
    switch( gender ) {
        case UNKNOWN_GENDER: return "UNKNOWN" ;
        case MALE: return "MALE" ;
        case FEMALE: return "FEMALE";
    }

    assert( false ) ;
    return NULL;
}


const char* breedName( const enum Breed breed ) {
    switch( breed ) {
        case UNKNOWN_BREED: return "UNKNOWN" ;
        case MAINE_COON: return "MAINE COON" ;
        case MANX: return "MANX" ;
        case SHORTHAIR: return "SHORTHAIR" ;
        case PERSIAN: return "PERSIAN" ;
        case SPHYNX: return "SPHYNX" ;
        case SIAMESE: return "SIAMESE" ;
    }
    assert( false ) ;
    return NULL;
}


const char* colorName ( const enum Color color ) {
    switch( color ) {
        case BLACK: return "BLACK" ;
        case WHITE: return "WHITE" ;
        case RED: return "RED" ;
        case BLUE: return "BLUE" ;
        case GREEN: return "GREEN" ;
        case PINK: return "PINK" ;
    }
    assert( false ) ;
    return NULL;
}