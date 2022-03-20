///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  Project - EE 205 - Spr 2022
///
/// @file deleteCats.cpp
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include "deleteCats.h"
#include <stdio.h>
#include <stdbool.h>

#include "deleteCats.h"
#include "catDatabase.h"

bool deleteCat( const size_t index ) {
    if( !isIndexValid( index ) ) {
        fprintf( stderr, "%s: %s(): Bad cat!\n", PROGRAM_NAME, __FUNCTION__ ) ;
        return false;
    }

    if( numCats == 0 ) {
        return true;
    }

    swapCat( index, numCats-1 ) ;

    wipeCat( numCats-1);

    numCats -= 1;

#ifdef DEBUG
    printf( "%s: %s: Cat [%lu] has been deleted.  There are [%lu] in the database.\n", PROGRAM_NAME, __FUNCTION__, index, numCats );
#endif
    return true;
}

bool deleteAllCats() {
    while( numCats != 0 ) {
        deleteCat( 0 );
    }

#ifdef DEBUG
    printf(  "%s: %s: All cats have been deleted\n", PROGRAM_NAME, __FUNCTION__ );
#endif

    return true;

}