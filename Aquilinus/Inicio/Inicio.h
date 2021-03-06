/********************************************************************
Vireio Perception : Open-Source Stereoscopic 3D Driver
Copyright (C) 2012 Andres Hernandez

Aquilinus : Vireio Perception 3D Modification Studio 
Copyright � 2014 Denis Reischl

Vireio Perception Version History:
v1.0.0 2012 by Andres Hernandez
v1.0.X 2013 by John Hicks, Neil Schneider
v1.1.x 2013 by Primary Coding Author: Chris Drain
Team Support: John Hicks, Phil Larkson, Neil Schneider
v2.0.x 2013 by Denis Reischl, Neil Schneider, Joshua Brown
v2.0.4 to v3.0.x 2014-2015 by Grant Bagwell, Simon Brown and Neil Schneider
v4.0.x 2015 by Denis Reischl, Grant Bagwell, Simon Brown and Neil Schneider

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU Lesser General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU Lesser General Public License for more details.

You should have received a copy of the GNU Lesser General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
********************************************************************/
#ifndef INICIO_MAIN_APP
#define INICIO_MAIN_APP

#define AQUILINUS_VERSION_PRIMA 1
#define AQUILINUS_VERSION_SECONDO 0
#define AQUILINUS_VERSION_TERZO 0

#define MAIN_WINDOW_WIDTH 680
#define MAIN_WINDOW_HEIGHT 200
#define MAIN_WINDOW_HEIGHT_NEW 800
#define MAIN_WINDOW_HEIGHT_OPTIONS 800
#define MAIN_WINDOW_HEIGHT_INFO 800

#define GLFW_INCLUDE_NONE

#pragma warning( disable : 26812 )

#include <windows.h>
#include <windowsx.h>
#include <tlhelp32.h>
#include <stdio.h>
#include <fstream>
#include <string>
#include <algorithm>
#include "Resources.h"
#include "..//Aquilinus/AquilinusCfg.h"
#include "..//Aquilinus/AQU_FileManager.h"
#include "..\\Aquilinus\AQU_2DData.h"
#include "..\dependecies\imgui\imgui.h"
#include "..\dependecies\imgui\imgui_impl_glfw.h"
#include "..\dependecies\imgui\imgui_impl_opengl3.h"
#include "..\dependecies\imgui\imgui_internal.h"
#include "..\dependecies\imgui\imgui_helpers.h"
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#pragma comment(lib, "advapi32.lib")

/*** Inicio Types ***/

/**
* Inicio menu control status.
***/
enum class InicioStatus
{
	Idle,
	Injecting,
	ToInject
//	Injected
};

/**
* Injection profiles supported.
***/
enum InjectionProfile
{
	IP_D3D9    = 0,
	IP_D3D10   = 1,
	IP_D3D11   = 2,
	IP_Count   = 3
};

/**
* The Aquilinus versioning structure.
***/
struct AQU_Version 
{ 
	DWORD dwPrima;
	DWORD dwSecondo; 
	DWORD dwTerzo; 
};

/**
* Inicio sub window types.
***/
enum class InicioWindows
{
	Main = 0,
	SelectProcess,
	SelectProfile,
	NewProject,
	Options,
	Info,
};

/*** Inicio Globals  ***/
AQU_FileManager*          g_pFileManager;                                            /**< Inicio File Manager class. ***/
InicioStatus              g_eInicioStatus;                                           /**< The control status for Inicio or the Aquilinus RTE. **/
int                       g_nScreenWidth  = GetSystemMetrics(SM_CXFULLSCREEN);
int                       g_nScreenHeight = GetSystemMetrics(SM_CYFULLSCREEN);
int                       g_nMainWindowWidth  = MAIN_WINDOW_WIDTH;                   /**< Current window width. **/
int                       g_nMainWindowHeight = MAIN_WINDOW_HEIGHT;                  /**< Current window height. **/
DWORD                     g_dwColorSchemeIndex = 0;                                  /**< Global color scheme index. Only needed to load/save options. Actual color scheme index stored in config. **/
bool                      g_bKeepProcessName = false;                                /**< True if the game process should be kept for next workspace load **/
DWORD                     g_nLetterStartIndex[27];                                   /**< The start index for that Letter (0, A, B,....., X, Y, Z) in the game list. **/
DWORD                     g_nLetterEntriesNumber[27];                                /**< The number of entries for that Letter (0, A, B,....., X, Y, Z) in the game list. **/
WNDCLASSEX                g_wc;                                                      /**< The window class. **/
BYTE*                     g_pPictureData;                                            /**< The global picture data. **/
DWORD                     g_dwPictureSize;                                           /**< The size of the raw (PNG) data. **/
HANDLE                    g_hInjectionThread;
HANDLE                    g_hInjectionAbortEvent;                                    /**< Abort injection event. ***/
std::vector<std::wstring> g_aszGameNames;                                            /**< The sorted game list to be used in the game selection window. **/
std::vector<std::wstring> g_aszGameNamesUnsorted;                                    /**< The unsorted game list to be used to get the process index for the game **/
int                       g_nGameSelected = 0;                                       /**< Index of the selected game. Matches the index in g_aszGameNames. **/
InjectionProfile          g_eGameProfile;                                            /**< Game graphics profile selected. **/
int                       g_nRepeat = 0;                                             /**< The number of process IDs to be skipped in injection process. (0..15) **/

#ifndef AQUILINUS_RUNTIME_ENVIRONMENT
AQU_Version               g_eVersion;                                                /**< The current version of Aquilinus. Maybe we put that in the configuration... **/
InicioWindows             g_eCurrentWindow;                                          /**< The current active window. ***/
bool                      g_bWindowResize;                                           /**< True if main window ought to be resized. **/
int	                      g_nCpX, g_nCpY;
int                       g_nOffsetCpX, g_nOffsetCpY;
int                       g_nWPosX, g_nWPosY;
int                       g_nButtonEvent, g_nControlEvent;
#endif

/*** Inicio controls methods ***/
void             ImGui_Main();
void             ImGui_New();
void             ImGui_StyleColorsByScheme();
void             SaveConfig();

/*** Inicio methods ***/
HRESULT          InicioInit();
void             InicioClose();
void             ForceIdle();
HRESULT          EnumerateGameNames();
HRESULT          EnumerateSupportedInterfaces(LPWSTR *&pszEntries, DWORD &dwEntries);
BOOL             SetPrivilege(HANDLE hToken, LPCTSTR lpszPrivilege, BOOL bEnablePrivilege); 
DWORD            GetTargetThreadID(wchar_t * szProcName);
HRESULT          Inject(DWORD dwID, const wchar_t * szDllName);
DWORD   WINAPI   InjectionThread(LPVOID Param);

#ifndef AQUILINUS_RUNTIME_ENVIRONMENT

/*** GL callbacks ***/
void             Viewport_callback(GLFWwindow* window, int width, int height);
void             CursorPosition_callback(GLFWwindow* window, double x, double y);
void             MouseButton_callback(GLFWwindow* window, int button, int action, int mods);

#endif

#endif