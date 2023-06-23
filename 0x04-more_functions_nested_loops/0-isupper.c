#include "main.h"

/**
  * _isuper - uppercase letters
  * @c: char to check
  *
  * Return: 0 or 1
  */

iny _isuper(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else
		return (0);
}
