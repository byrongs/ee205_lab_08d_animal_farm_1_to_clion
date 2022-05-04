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
