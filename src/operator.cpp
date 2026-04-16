/**
 *  @file   operator.ino
 *  @brief  This source code contains the 'Operator' class that will keep track of the operator precedence of the
 *          calculator.
 * 
 *  This source code will contain the necessary attributes and methods to keep track of the correct order to solve
 *  the operations.
 * 
 *  @author Richmond Ryan L. Teng
 *  @date   15/04/2026
 *  @bug    No known bugs.
 */

#include <stdint.h>
 
class Operator 
{
  public:
    char symbol = '#';
    uint8_t leftIndex = -1;
    uint8_t rightIndex = -1;
    uint8_t priority;
}