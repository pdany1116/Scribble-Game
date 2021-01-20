//---------------------------------------------------------------------------

#ifndef ClasaJocH
#define ClasaJocH
#define nr_cuvinte 71
#define nr_runde 7
#include "ClasaFiguri.h"
#include "ClasaPozitie.h"

#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CGRID.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <fstream>
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
class GameScribble{
public:
        TPicture *PanzaAlba;
        Pozitie *poz;
        Figuri *fig;
        bool mousedown;
        int turn;
        int cl_scor, srv_scor;

        GameScribble();

        void InitButtons();
        void InitComponents();
        void RandomCuvant();
        void Play();
};
#endif
