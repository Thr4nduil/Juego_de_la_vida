/***************************************************************************//**
  @file     gol.h
  @brief    Header for Game of Life back-end
  @author   Nicolás Magliola
 ******************************************************************************/

#ifndef _GOL_H_
#define _GOL_H_

/*******************************************************************************
 * INCLUDE HEADER FILES
 ******************************************************************************/

/*******************************************************************************
 * CONSTANT AND MACRO DEFINITIONS USING #DEFINE
 ******************************************************************************/

enum { DEAD, ALIVE };


/*******************************************************************************
 * ENUMERATIONS AND STRUCTURES AND TYPEDEFS
 ******************************************************************************/

/*******************************************************************************
 * VARIABLE PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/*******************************************************************************
 * FUNCTION PROTOTYPES WITH GLOBAL SCOPE
 ******************************************************************************/

/**
 * @brief Creates a world of width (x) and height (y).
 * All cells are set to DEAD or ALIVE
 * @param x World's width
 * @param y World's height
 * @return If creation was success (true / false)
*/
int gol_CreateWorld ( int x, int y );


/**
 * @brief Returns the width (x) of the world
 * @return World's width
*/
int gol_GetWorldWidth ( void );


/**
 * @brief Returns the height (y) of the world
 * @return World's height
*/
int gol_GetWorldHeight ( void );


/**
 * @brief Returns the state ( DEAD or ALIVE ) of the cell at (x,y)
 * @param x Coordinate X [0, width-1]
 * @param y Coordinate Y [0, height-1]
 * @return Cell's state ( DEAD or ALIVE )
*/
int gol_GetCellState ( int x, int y );


/**
 * @brief Sets the state ( DEAD or ALIVE ) of the cell at (x,y)
 * @param x Coordinate X [0, width-1]
 * @param y Coordinate Y [0, height-1]
 * @param state Cell's state ( DEAD or ALIVE )
*/
void gol_SetCellState ( int x, int y, int state );


/**
 * @brief Updates world state to next generation according to
 * game's rules
*/
void gol_EvolveWorld ( void );


/**
 * @brief Destroy the created world
 * @return If initialization was success (true / false)
*/
int gol_DestroyWorld ( void );



/*******************************************************************************
 ******************************************************************************/

#endif // _GOL_H_





