/**
 *  @file   vector.ino
 *  @brief  This source code contains the 'Vector' class that will make static arrays easier to modify and access.
 * 
 *  This source code will contain the necessary attributes and methods to remove, add, and shift elements of the
 *  array.
 * 
 *  @author Richmond Ryan L. Teng
 *  @date   15/04/2026
 *  @bug    No known bugs.
 */

#include <stdint.h>

#define CAPACITY 128

class Vector
{
  public:
    uint8_t size;
};

class IntVector : public Vector
{
  public:
    int array[CAPACITY];
};

class OperatorVector : public Vector
{
  public:
    
}