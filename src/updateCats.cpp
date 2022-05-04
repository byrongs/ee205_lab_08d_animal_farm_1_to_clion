///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.cpp
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "updateCats.h"

#include <stdio.h>
#include <string.h>  // For memset and strncpy


#include "updateCats.h"
#include "config.h"
#include "reportCats.h"
#include "catDatabase.h"
#include "addCats.h"

#define CHECK_INDEX( index )    if( !isIndexValid( index) ) {                                           \
                                        fprintf(stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ; \
                                        return false;                                                   \
        }

bool updateCatName( const NumCats index, const char* name ) {
    if( !isIndexValid( index ) ) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
        return false;
    }

    if( !isNameValid( name )) {
        return false;
    }

    memset( cats[index].name, 0, MAX_CAT_NAME ) ;  // Zero out the old cat's name
    strncpy( cats[index].name, name, MAX_CAT_NAME-1 );

    return true;
}


bool fixCat( const NumCats index ) {
    if(  !isIndexValid( index ) ) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
        return false;
    }


    cats[index].isFixed = true;

    return true;
}


bool updateCatWeight( const NumCats index, const Weight weight ) {
    if( !isIndexValid( index ) ) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
        return false;
    }
    if( !isWeightValid( weight)) {
        return false;
    }
    cats[index].weight = weight;
    return true;
}


bool updateCatCollar1( const NumCats index, const enum Color color ) {
    CHECK_INDEX( index )
    cats[index].collarColor1 = color ;
    return true;
}

bool updateCatCollar2( const NumCats index, const enum Color color ) {
    CHECK_INDEX( index )
    cats[index].collarColor2 = color;
    return true;
}

bool updateCatLicense( const NumCats index, const unsigned long long license ) {
    CHECK_INDEX( index )
    cats[index].license = license ;
    return true;
}

bool validateCatCollar1(const NumCats index, const enum Color color) {
    CHECK_INDEX( index )
    if(cats[index].collarColor1 == cats[index].collarColor2) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
    }
    return true;
}

bool validateCatCollar2(const NumCats index, const enum Color color) {
    CHECK_INDEX( index )
    if(cats[index].collarColor2 == cats[index].collarColor1) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
    }
    return true;
}

