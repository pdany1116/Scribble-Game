//---------------------------------------------------------------------------

#ifndef SourceH
#define SourceH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "CGRID.h"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include "ClasaJoc.h"
#include <ScktComp.hpp>
#include <iostream>
using namespace std;

//---------------------------------------------------------------------------
class TInterfata : public TForm
{
__published:	// IDE-managed Components
        TButton *Exit;
        TButton *Start;
        TImage *Panza;
        TSpeedButton *Galetusa;
        TSpeedButton *Guma;
        TSpeedButton *Cerc;
        TSpeedButton *Dreptunghi;
        TCColorGrid *Culori;
        TMemo *Raspunsuri;
        TEdit *Raspuns;
        TPanel *Cuvant;
        TTrackBar *Marime;
        TSpeedButton *Creion;
        TButton *Clear;
        TServerSocket *srvSocket;
        TTimer *Timer1;
        TImage *Background;
        TButton *HowToPlay;
        void __fastcall ExitClick(TObject *Sender);
        void __fastcall StartClick(TObject *Sender);
        void __fastcall PanzaMouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall PanzaMouseUp(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
        void __fastcall PanzaMouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall ClearClick(TObject *Sender);
        void __fastcall RaspunsKeyPress(TObject *Sender, char &Key);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall srvSocketClientRead(TObject *Sender,
          TCustomWinSocket *Socket);
        void __fastcall HowToPlayClick(TObject *Sender);

private:	// User declarations

public:     // User declarations
        GameScribble *Joc;	
        String SendLinie;
        String SendGuma;
        String SendGaletusa;
        String SendCerc;
        String SendDreptunghi;
        __fastcall TInterfata(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TInterfata *Interfata;
//---------------------------------------------------------------------------
#endif
