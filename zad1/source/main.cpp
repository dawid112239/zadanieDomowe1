#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR szCmdLine, int iCmdShow) {

  int dolnyZakres = 1;
  int gornyZakres = 40;
  int liczba;
  bool znaleziono = false;
  int id;
  MessageBox(0, "Wybierz liczbe z zakresu 1-40. Wcisnij OK aby rozpoczac gre", "Aplikacja", MB_OK);
  while (!znaleziono) {
    liczba = (dolnyZakres + gornyZakres) / 2;
    id = MessageBox(0,"Czy twoja liczba jest wieksza od","Aplikacja",MB_YESNO | MB_ICONQUESTION);
    if (id == IDYES) {
      dolnyZakres = liczba;
     }
    else {
      gornyZakres = liczba;
    }
    if (((dolnyZakres+1) == gornyZakres) && (id==IDYES)) {
      MessageBox(0, "Jezeli mnie nie oszukiwales to twoja liczba to %gornyZakres", "Aplikacja", MB_OK | MB_ICONINFORMATION);
      znaleziono = true;
    }
    if ((dolnyZakres == (gornyZakres+1)) && (id==IDNO)) {
      MessageBox(0, "Jezeli mnie nie oszukiwales to twoja liczba to %dolnyZakres", "Aplikacja", MB_OK | MB_ICONINFORMATION);
      znaleziono = true;
    }
  }

  return 0;
}