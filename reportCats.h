///////////////////////////////////////////////////////////////////////////////
///         University of Hawaii, College of Engineering
/// @brief  ee205_lab_08d_animal_farm_1_to_clion - EE 205 - Spr 2022
///
/// @file reportCats.h
/// @version 1.0
///
/// @author @Byron Soriano <@byrongs@hawaii.edu>
/// @date   20_Mar_2022
///////////////////////////////////////////////////////////////////////////////

#pragma once
#include "catDatabase.h"
extern void   printCat( const size_t index ) ;
extern void   printAllCats() ;
extern size_t findCat( const char* name ) ;  /// @returns the index or BAD_CAT

extern const char* genderName( const enum Gender gender ) ;

extern const char* breedName( const enum Breed breed ) ;

extern const char* colorName (const enum Color color ) ;
