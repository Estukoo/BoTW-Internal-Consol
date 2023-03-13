#include <Windows.h>

namespace Menu_P1 {
    void InitializeContext(HWND hwnd);
    void Render( );

    inline float WIDTH = 300.0f;
    inline float HEIGHT = 58.0f;
    inline const char* TITLE = "BoTW Couch Extra Infos - P1";
    inline bool bShowMenu = true;
} // namespace Menu_P1

namespace Menu_P2 {
    void InitializeContext(HWND hwnd);
    void Render( );

    inline float WIDTH = 300.0f;
    inline float HEIGHT = 58.0f;
    inline const char* TITLE = "BoTW Couch Extra Infos - P2";
    inline bool bShowMenu = true;
} // namespace Menu_P2
