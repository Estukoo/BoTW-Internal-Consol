#include "menu.hpp"
#include "../console/console.hpp"
#include "../mem/address.h"

#include "../dependencies/imgui/imgui.h"
#include "../dependencies/imgui/imgui_impl_win32.h"

namespace ig = ImGui;

namespace Menu_P1 {
    void InitializeContext(HWND hwnd) {
        if (ig::GetCurrentContext( ))
            return; 

        ig::CreateContext( );
        ImGui_ImplWin32_Init(hwnd);

        ImGuiIO& io = ig::GetIO( );
        io.IniFilename = io.LogFilename = nullptr;
    }

    void Render( ) {
        if (!bShowMenu)
            return;

#if P1
        addr->calcAddresses();  

        ig::SetNextWindowPos(ImVec2(0, 0), ImGuiCond_Always);
        ig::SetNextWindowSize(ImVec2(WIDTH, HEIGHT), ImGuiCond_Always);

        ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
        ig::Begin(TITLE, nullptr, flags);

        if (cInfos_P1->Health) {
            unsigned int heatlth = addr->mem->ReadMemory<unsigned int>(cInfos_P1->Health);

            ig::Text("Health ");
            ig::SameLine();
            ig::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.988f, 0.207f, 0.125f, 1.0f));
            ig::ProgressBar((float)heatlth / 120);
            ig::PopStyleColor();
        }

        if (cP1->Stamina) { 
            float stamina = addr->mem->ReadMemory<float>(cP1->Stamina);

            ig::Text("Stamina");
            ig::SameLine();
            ig::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.0, 1.0f, 0.141f, 0.447f));
            ig::ProgressBar(stamina/3000.0f);
            ig::PopStyleColor();
        }

        ig::End();
#endif
    }
} // namespace Menu_P1


namespace Menu_P2 {
    void InitializeContext(HWND hwnd) {
        if (ig::GetCurrentContext( ))
            return;

        ig::CreateContext( );
        ImGui_ImplWin32_Init(hwnd);

        ImGuiIO& io = ig::GetIO( );
        io.IniFilename = io.LogFilename = nullptr;
    }

    void Render( ) {
        if (!bShowMenu)
            return;

#if P2
        addr->calcAddresses();

        ig::SetNextWindowPos(ImVec2(ig::GetIO().DisplaySize[0] - WIDTH, ig::GetIO().DisplaySize[1] / 2), ImGuiCond_Always);
        ig::SetNextWindowSize(ImVec2(WIDTH, HEIGHT), ImGuiCond_Always);

        ImGuiWindowFlags flags = ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar;
        ig::Begin(TITLE, nullptr, flags);

        if (cInfos_P2->Health) {
            unsigned int heatlth = addr->mem->ReadMemory<unsigned int>(cInfos_P2->Health);

            ig::Text("Health ");
            ig::SameLine();
            ig::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.988f, 0.207f, 0.125f, 1.0f));
            ig::ProgressBar((float)heatlth / 120);
            ig::PopStyleColor();
        }

        if (cP2->Stamina) {
            float stamina = addr->mem->ReadMemory<float>(cP2->Stamina);

            ig::Text("Stamina");
            ig::SameLine();
            ig::PushStyleColor(ImGuiCol_PlotHistogram, ImVec4(0.0, 1.0f, 0.141f, 0.447f));
            ig::ProgressBar(stamina/3000.0f);
            ig::PopStyleColor();
        }

        ig::End();
#endif
    }
} // namespace Menu_P2