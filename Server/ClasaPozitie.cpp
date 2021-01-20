//---------------------------------------------------------------------------
#pragma hdrstop
#include "ClasaPozitie.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
Pozitie::Pozitie()
{
        X=0;
        Y=0;
}

void Pozitie::setX(int x)
{
        this->X=x;
}

void Pozitie::setY(int y)
{
        this->Y=y;
}

int Pozitie::getX()
{
        return this->X;
}

int Pozitie::getY()
{
        return this->Y;
}

