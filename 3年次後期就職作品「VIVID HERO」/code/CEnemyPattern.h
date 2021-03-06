//-------------------------------------------------------------------------
//
//	File:CEnemyPatternΜwb_[t@C[CEnemyPattern.h]
//	Author:DO
//
//-------------------------------------------------------------------------
#ifndef _CENEMYPATTERN_H_
#define _CENEMYPATTERN_H_

//-----------------------------------
//CN[ht@C
//-----------------------------------
#include "main.h"
#include "CScene.h"

//-----------------------------------
//NXέv
//-----------------------------------
class CEnemyPattern
{
public:
	CEnemyPattern(){}
	virtual ~CEnemyPattern() = 0{}

	virtual void Update(CScene *pEnemy) = 0;
};


#endif
