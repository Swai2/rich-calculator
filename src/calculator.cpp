/**
 *  @file   calculator.cpp
 *  @brief  This source code contains the method definitions for the 'Calculator' class.
 * 
 *  This file contains the necessary function definitions of the classes written in
 *  calculator.h. The primary goal of these methods are to output the correct answer to the
 *  equation input by the user in the calculator.
 * 
 *  @author Richmond Ryan L. Teng
 *  @date   19/04/2026
 *  @bug    No known bugs.
 */

#include "Arduino.h"
#include "calculator.h"

void Calculator::loadDigit(char digit)
{
  if (this->isTypingDecimal)
  {
		// ASCII conversion; '0' = 48, '1' = 49...
		this->currWholePart = this->currWholePart * 10 + (digit - '0');
  } 
  else
  {
		this->currFractionPart += ((digit - '0') * this->decimalMultiplier);
		this->decimalMultiplier /= 10;
	}
}

void Calculator::executeOperation(int tokenIndex)
{
	Token currToken = this->tokens.elements[tokenIndex];
	Token leftToken = this->tokens.elements[tokenIndex - 1];
	Token rightToken = this->tokens.elements[tokenIndex + 1];

	if (currToken.type == TokenType::OPR)
	{
		if (rightToken.type == TokenType::OPR)
		{
			switch (rightToken.operation)
			{
				case '+': break;
				case '-': minusCtr++; break;
				case '*': case '/': this->status = StatusCode::SYNTAX_ERROR; break;
			}
		}
	}
	else
	{
		Token temp = { .type = TokenType::NUM };

		if (this->minusCtr % 2 == 1)
		{
			rightToken.number = -rightToken.number;
		}

		switch (currToken.operation)
		{
			case '+': temp.number = leftToken.number + rightToken.number; break;
			case '-': temp.number = leftToken.number - rightToken.number; break;
			case '*': temp.number = leftToken.number * rightToken.number; break;
			case '/': 
				if (fabs(rightToken.number - 0.0f) < __FLT_EPSILON__) 
					this->status = StatusCode::MATH_ERROR;
				else
					temp.number = leftToken.number / rightToken.number; break;
		}

		this->tokens.elements[tokenIndex - 1] = temp;
		this->tokens.remove(tokenIndex + 1);
	}

	this->tokens.remove(tokenIndex);
}

void Calculator::storeNumber()
{
	Token temp = {
		.type = TokenType::NUM,
		{.number = this->currWholePart + this->currFractionPart}
	};

	this->tokens.add(temp);

	this->currWholePart = 0;
	this->currFractionPart = 0.0f;
}

bool Calculator::isFinished()
{
	return !(this->status == StatusCode::ONGOING);
}

void Calculator::input(char key)
{
	if (key >= '0' && key <= '9')
		this->loadDigit(key);
	else if (key == '.')
		this->isTypingDecimal = true;
	else if (key == '=')
	{
		if (this->status == StatusCode::ONGOING)
			this->status = StatusCode::SAFE_TERMINATION;

		this->storeNumber();
	}
	else
	{
		Token temp = {
			.type = TokenType::OPR,
			{.operation = key}
		};

		this->isTypingDecimal = false;
		this->storeNumber();
		this->tokens.add(temp);
	}
}

float Calculator::output()
{
	for (int i = 0; i < this->tokens.size; i++)
	{
		if (this->tokens.elements[i].type == TokenType::OPR)
		{
			
		}
	}
}