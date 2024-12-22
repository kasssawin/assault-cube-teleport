// ACteleport.cpp : Definiuje eksportowane funkcje dla biblioteki DLL.
//

#include "pch.h"
#include "framework.h"
#include "ACteleport.h"


// To jest przykład wyeksportowanej zmiennej
ACTELEPORT_API int nACteleport=0;

// To jest przykład wyeksportowanej funkcji.
ACTELEPORT_API int fnACteleport(void)
{
    return 0;
}

// To jest konstruktor wyeksportowanej klasy.
CACteleport::CACteleport()
{
    return;
}
