/**
 *  @file   token.cpp
 *  @brief  This source code contains the 'Token' class that will keep track of the operator precedence of the
 *          calculator.
 * 
 *  This source code will contain the necessary attributes and methods to keep track of the correct order to solve
 *  the operations.
 * 
 *  @author Richmond Ryan L. Teng
 *  @date   15/04/2026
 *  @bug    No known bugs.
 */

typedef enum _TokenType
{
	TOKEN_NUM,
  TOKEN_OPR,
  TOKEN_DOT,
  TOKEN_END
} TokenType;

typedef struct _Token
{
	TokenType type;
	union
	{
		float number;
		char operation;
	};
} Token;