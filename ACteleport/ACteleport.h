// Następujący blok ifdef jest standardowym sposobem tworzenia makr, które powodują, że eksportowanie
// z biblioteki DLL jest prostsze. Wszystkie pliki w obrębie biblioteki DLL są kompilowane z ACTELEPORT_EXPORTS
// symbol zdefiniowany w wierszu polecenia. Symbol nie powinien być zdefiniowany w żadnym projekcie
// które korzysta z tej biblioteki DLL. W ten sposób każdy inny projekt, którego pliki źródłowe dołączają ten plik, widzi
// funkcje ACTELEPORT_API w postaci zaimportowanej z biblioteki DLL, podczas gdy biblioteka DLL widzi symbole
// zdefiniowane za pomocą tego makra jako wyeksportowane.
#ifdef ACTELEPORT_EXPORTS
#define ACTELEPORT_API __declspec(dllexport)
#else
#define ACTELEPORT_API __declspec(dllimport)
#endif

// Ta klasa została wyeksportowana z pliku dll
class ACTELEPORT_API CACteleport {
public:
	CACteleport(void);
	// TODO: w tym miejscu dodaj metody.
};

extern ACTELEPORT_API int nACteleport;

ACTELEPORT_API int fnACteleport(void);
