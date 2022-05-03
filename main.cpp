///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file main.cpp
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "config.h"
#include "catDatabase.h"
#include "addCats.h"
#include "reportCats.h"
#include "updateCats.h"
#include "deleteCats.h"

int main() {
    printf( "Starting %s\n", PROGRAM_TITLE );

    initializeDatabase();

    addCat( "Loki", MALE, PERSIAN, true, 8.5, BLACK, WHITE, 101 ) ;
    addCat( "Milo", MALE, MANX, true, 7.0, BLACK, RED, 102 ) ;
    addCat( "Bella", FEMALE, MAINE_COON, true, 18.2, BLACK, BLUE, 103 ) ;
    addCat( "Kali", FEMALE, SHORTHAIR, false, 9.2, BLACK, GREEN, 104 ) ;
    addCat( "Trin", FEMALE, MANX, true, 12.2, BLACK, PINK, 105 ) ;
    addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLACK, 106 ) ;

    addCat( "Somsak", MALE, SIAMESE, true, 3.0, BLACK, BLACK, 101 ) ; //custom test cat

#ifdef DEBUG

    // Test for empty name
                assert( addCat( "", UNKNOWN_GENDER, SHORTHAIR, false, 19.0, BLACK, WHITE, 101 ) == BAD_CAT ) ;
                // Test for max name
                assert( addCat( MAX_NAME1, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, RED, 107 ) != BAD_CAT ) ;
                // Test for name too long
                assert( addCat( ILLEGAL_NAME, UNKNOWN_GENDER, SHORTHAIR, false, 19.0, WHITE, BLUE, 108 ) == BAD_CAT ) ;
                // Test for duplicate cat name
                assert( addCat( "Chili", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, GREEN, 109 ) == BAD_CAT ) ;
                // Test for weight <= 0
                assert( addCat( "Neo", UNKNOWN_GENDER, SHORTHAIR, false, 0, WHITE, PINK, 110 ) == BAD_CAT ) ;



                // Test for printCat( -1 );
                printCat( -1 );
                // Test for out of bounds
                printCat( 2000 );

                // Test finding a cat...
                assert( findCat( "Bella" ) == 2 ) ;
                // Test not finding a cat
                assert( findCat( "Bella's not here" ) == BAD_CAT ) ;


                // Test addCat details
                size_t testCat = addCat( "Oscar", UNKNOWN_GENDER, SHORTHAIR, false, 1.1, RED, BLACK, 111 ) ;
                assert( testCat != BAD_CAT );
                assert( testCat < MAX_CATS );


                // Test setting a large name
                assert( updateCatName( testCat, MAX_NAME2 ) == true ) ;
                printCat( testCat ) ;

                // Test setting an out-of-bounds name
                assert( updateCatName( testCat, ILLEGAL_NAME ) == false ) ;
                printCat( testCat ) ;

                // Test setting an illegal cat weight
                assert( updateCatWeight( testCat, -1 ) == false ) ;assert( updateCatWeight( testCat, -1 ) == false ) ;

#endif

    printAllCats();

    int kali = findCat( "Kali" ) ;
    printCat( kali ) ;
    assert( updateCatName( kali, "Capulet" ) == true ) ;
    assert( updateCatWeight( kali, 9.9 ) == true ) ;
    assert( fixCat( kali ) == true ) ;
    assert( updateCatCollar1( kali, GREEN ) == true ) ;
    assert( updateCatCollar2( kali, GREEN ) == true ) ;
    assert( updateCatLicense( kali, 201 ) == true ) ;
    assert(validateCatCollar1( kali, BLACK) == true ) ;
    assert(validateCatCollar2(kali, BLACK) == true ) ;
    printCat( kali ) ;

    printAllCats();

    deleteAllCats() ;
    printAllCats();

    printf( "Done with %s\n", PROGRAM_TITLE );

    return( EXIT_SUCCESS );
}
