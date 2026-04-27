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

#ifndef VECTOR_H
#define VECTOR_H

#include <stdint.h>
#include "token.h"

#define MAX_CAPACITY 64

template <typename T, uint8_t CAPACITY>
class BaseVector
{
  public:
    T elements[CAPACITY];
    uint8_t size = 0;

    // A separate .tpp file wasn't used as the function definitions are not significantly big.
    int search(int key)
    {
      for (int i = 0; i < this->size; i++)
      {
        if (this->elements[i] == key)
          return i;
      }

      return -1;
    }

    void remove(int index)
    {
      while (index < this->size - 1)
      {
        this->elements[index] = this->elements[index + 1];
      }

      index++;
    };

    int add(T element)
    {
      this->elements[this->elements.size] = element;
      this->size++;

      return this->size - 1;
    }
};

class TokenVector : public BaseVector<Token, MAX_CAPACITY>{};

#endif