///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file updateCats.h
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once

#include <stdbool.h>

#include "catDatabase.h"

extern bool updateCatName( const NumCats index, const char* name ) ;
extern bool fixCat( const NumCats index ) ;
extern bool updateCatWeight( const NumCats index, const Weight weight ) ;
extern bool updateCatCollar1( const NumCats index, const enum Color color ) ;
extern bool updateCatCollar2( const NumCats index, const enum Color color ) ;

extern bool validateCatCollar1( const NumCats index, const enum Color color ) ;

extern bool validateCatCollar2( const NumCats index, const enum Color color ) ;

extern bool updateCatLicense( const NumCats index, const unsigned long long license );