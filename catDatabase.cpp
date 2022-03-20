///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file catDatabase.cpp
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "catDatabase.h"
#include <string.h>
#include <assert.h>
#include <stdio.h>

#include "catDatabase.h"

/// This is the actual cat database

struct Catinfo cats[MAX_CATS]; //array

size_t numCats = 0 ;

/// Zeros out a cat's information from the database

void wipeCatInternal( const size_t index ) {
    memset( &cats[index], 0, sizeof( struct Catinfo )) ;

}




/// Zeros out a cat's information from the database
void wipeCat( const size_t index ) {
    assert( isIndexValid( index ));

    wipeCatInternal( index );
}

void initializeDatabase() {
    numCats = 0;  // Zero out the cats in the database

    memset( &cats, 0, sizeof( cats ) ) ;
}


bool isFull() {
    validateDatabase() ;  // Make sure things are healthy first

    if( numCats >= MAX_CATS ) {  // The database is full
        return true ;
    }

    return false;
}

extern bool validateDatabase() {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
    assert( numCats >= 0 );  // Make sure numCats isn't corrupt (negative)
#pragma GCC diagnostic pop

    return true ;
}


/// Verify the index is a valid value for this database
extern bool isIndexValid( const size_t index ) {
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wtype-limits"
    if( index < 0 ) {
        fprintf( stderr, "%s: %s(): Index is < 0\n", PROGRAM_NAME, __FUNCTION__ ) ;
        return false;
    }
#pragma GCC diagnostic pop

    if( index >= numCats ) {
        fprintf( stderr, "%s: %s(): index [%lu] is >= the number of cats in the database [%lu]\n", PROGRAM_NAME, __FUNCTION__, index, numCats ) ;
        return false;
    }

    return true;
}

/// verify valid names


bool isNameValid( const char* name ) {
    if( name == NULL ) {
        fprintf( stderr, "%s: The cat's name can't be NULL.\n", PROGRAM_NAME ) ;
        return false ;
    }

    if( strlen( name ) <= 0 ) { // The name is empty...
        fprintf( stderr, "%s: The cat's name can't be empty.\n", PROGRAM_NAME ) ;
        return false ;
    }

    if( strlen( name ) > MAX_CAT_NAME - 1 ) { // The name is too large...
        fprintf( stderr, "%s: Cat name [%s] is too long.  The maximum allowed length is [%d]\n", PROGRAM_NAME, name, MAX_CAT_NAME - 1 );
        return false;
    }
    return true;
}


/// verify weight is valid

bool isWeightValid( const float weight ) {
    if( weight <= 0 ) {
        fprintf( stderr, "%s: Cat's weight is [%f].  It must be > 0\n", PROGRAM_NAME, weight ) ;
        return false ;

    }

    return true;
}


///swap cats in indexes

bool swapCat( const size_t a, const size_t b ) {
    if( !isIndexValid( a ) ) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
        return false;
    }

    if( !isIndexValid( b ) ) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
        return false;
    }

    if( a == b ) {
        return true ;
    }

    //swapping a and b
    struct Catinfo oldCat ;

    memcpy( &oldCat, &cats[a], sizeof( struct Catinfo ) );
    memcpy( &cats[a], &cats[b], sizeof( struct Catinfo ) );
    memcpy( &cats[b], &oldCat, sizeof( struct Catinfo ) );


    return true;
}