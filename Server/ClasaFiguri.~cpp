//---------------------------------------------------------------------------


#pragma hdrstop
#include "Source.h"
#include "ClasaFiguri.h"
#include "ClasaJoc.h"
#pragma package(smart_init)
//---------------------------------------------------------------------------
Figuri::Figuri()
{
        xaj=0;
        yaj=0;
        intMarime=1;
        intColIndex=0;
}

void Figuri::Umplere()
{
        Interfata->Panza->Canvas->Brush->Color=Interfata->Culori->ForegroundColor;
        intColIndex=Interfata->Culori->ForegroundIndex;

        Interfata->Panza->Canvas->FloodFill(Interfata->Joc->poz->getX(),
                                            Interfata->Joc->poz->getY(),
                                            Interfata->Panza->Canvas->Pixels[Interfata->Joc->poz->getX()][Interfata->Joc->poz->getY()],
                                            fsSurface);
}

void Figuri::Dreptunghi()
{
        Interfata->Panza->Canvas->Brush->Style=bsClear;
        Interfata->Panza->Canvas->Rectangle(this->getXaj(),
                                            this->getYaj(),
                                            Interfata->Joc->poz->getX(),
                                            Interfata->Joc->poz->getY());

        String strxaj=IntToStr(this->getXaj());
        String stryaj=IntToStr(this->getYaj());
        Interfata->SendDreptunghi+=strxaj;
        Interfata->SendDreptunghi+=';';
        Interfata->SendDreptunghi+=stryaj;
        Interfata->SendDreptunghi+=';';

        String strx=IntToStr(Interfata->Joc->poz->getX());
        String stry=IntToStr(Interfata->Joc->poz->getY());
        Interfata->SendDreptunghi+=strx;
        Interfata->SendDreptunghi+=';';
        Interfata->SendDreptunghi+=stry;
        Interfata->SendDreptunghi+=';';
}

void Figuri::Cerc()
{
        Interfata->Panza->Canvas->Arc(this->getXaj(),
        this->getYaj(),
        Interfata->Joc->poz->getX(),
        Interfata->Joc->poz->getY(),
        Interfata->Joc->poz->getX(),
        Interfata->Joc->poz->getY(),
        Interfata->Joc->poz->getX(),
        Interfata->Joc->poz->getY());

        String strxaj=IntToStr(this->getXaj());
        String stryaj=IntToStr(this->getYaj());
        Interfata->SendCerc+=strxaj;
        Interfata->SendCerc+=';';
        Interfata->SendCerc+=stryaj;
        Interfata->SendCerc+=';';

        String strx=IntToStr(Interfata->Joc->poz->getX());
        String stry=IntToStr(Interfata->Joc->poz->getY());
        Interfata->SendCerc+=strx;
        Interfata->SendCerc+=';';
        Interfata->SendCerc+=stry;
        Interfata->SendCerc+=';';
}

void Figuri::InitPen()
{
        Interfata->Panza->Canvas->Pen->Color=Interfata->Culori->ForegroundColor;
        intColIndex=Interfata->Culori->ForegroundIndex;

        Interfata->Panza->Canvas->Pen->Width=Interfata->Marime->Position;
        intMarime=Interfata->Marime->Position;

        Interfata->Panza->Canvas->MoveTo(Interfata->Joc->poz->getX(),
                                         Interfata->Joc->poz->getY());
}

void Figuri::InitGuma()
{
        Interfata->Panza->Canvas->Pen->Color=clWhite;
        Interfata->Panza->Canvas->Pen->Width=Interfata->Marime->Position+10;
        intMarime=Interfata->Marime->Position+10;

        Interfata->Panza->Canvas->MoveTo(Interfata->Joc->poz->getX(),
                                         Interfata->Joc->poz->getY());
}

void Figuri::Desen()
{
       Interfata->Joc->fig->InitPen();
       if(Interfata->Cerc->Down)
       {
               Cerc();
       }
       else if(Interfata->Dreptunghi->Down)
       {
               Dreptunghi();
       }
}

void Figuri::setXaj(int x0)
{
        xaj=x0;
}

void Figuri::setYaj(int y0)
{
       yaj=y0;
}

int Figuri::getXaj()
{
        return xaj;
}

int Figuri::getYaj()
{
        return yaj;
}

