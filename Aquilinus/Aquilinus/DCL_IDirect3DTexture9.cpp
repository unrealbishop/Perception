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
#ifdef _DEBUG
#include <windows.h>
#include <tchar.h>
#include <sstream>
typedef std::basic_stringstream<TCHAR> tstringstream;
template<typename T> tstringstream& operator,(tstringstream& tss, T t) { tss << _T(" ") << t; return tss; }
#define OUTPUT_DEBUG_STRING_IDirect3DTexture9(...) ::OutputDebugString((tstringstream(), _T("***"), __VA_ARGS__, _T("\n")).str().c_str());
#else
#define OUTPUT_DEBUG_STRING_IDirect3DTexture9(...)
#endif
#define AQU_IDIRECT3DTEXTURE9_HEADER________(a) if ((!m_pcTransferSite->m_bForceD3D) && (m_pcTransferSite->m_ppNOD_IDirect3DTexture9[a]) && (m_pcTransferSite->m_ppNOD_IDirect3DTexture9[a]->m_cProvoker.m_paInvokers.size() > 0)) {
#define AQU_IDIRECT3DTEXTURE9_SET_DATA______(a,b,c) m_pcTransferSite->m_ppNOD_IDirect3DTexture9[a]->m_paCommandersTemporary[b]->m_pOutput = (void*)&c;
#define AQU_IDIRECT3DTEXTURE9_PROVOKE_______(a) m_pcTransferSite->m_bForceD3D = true; void* pvRet = m_pcTransferSite->m_ppNOD_IDirect3DTexture9[a]->Provoke((void*)pcThis, m_pcTransferSite->m_ppaNodes); m_pcTransferSite->m_bForceD3D = false;
#define AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(a,b) if ((*m_pcTransferSite->m_ppaNodes)[m_pcTransferSite->m_ppNOD_IDirect3DTexture9[a]->m_cProvoker.m_paInvokers[0]->m_lNodeIndex]->m_bReturn){ static b hr = (b)*(b*)pvRet; return hr; } }
#define AQU_IDIRECT3DTEXTURE9_REPLACE_VOID__(a) if ((*m_pcTransferSite->m_ppaNodes)[m_pcTransferSite->m_ppNOD_IDirect3DTexture9[a]->m_cProvoker.m_paInvokers[0]->m_lNodeIndex]->m_bReturn){ return; } }

#include"DCL_IDirect3DTexture9.h"
#include"DCL_IDirect3DTexture9_Super.h"

#pragma region DCL_IDirect3DTexture9 constructor/destructor

/**
*
***/
DCL_IDirect3DTexture9::DCL_IDirect3DTexture9(AQU_TransferSite* pcTransferSite) : 
	m_pcTransferSite(pcTransferSite)
{}

/**
*
***/
DCL_IDirect3DTexture9::~DCL_IDirect3DTexture9(){}

#pragma endregion

#pragma region IUnknown methods

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::QueryInterface(IDirect3DTexture9* pcThis, REFIID riid, void** ppvObj)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::QueryInterface");
	return D3D9_IDirect3DTexture9_QueryInterface_Super(pcThis, riid, ppvObj);
}

/**
*
***/
ULONG WINAPI DCL_IDirect3DTexture9::AddRef(IDirect3DTexture9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::AddRef");
	
	// set reference counter in the transfer site class
	int iCount = D3D9_IDirect3DTexture9_AddRef_Super(pcThis);
	m_pcTransferSite->m_anInterfaceRefCount[AQU_SUPPORTEDINTERFACES::AQU_SupportedInterfaces::IDirect3DTexture9] = iCount;
	return iCount;
}

/**
*
***/
ULONG WINAPI DCL_IDirect3DTexture9::Release(IDirect3DTexture9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::Release");
		
	// set reference counter in the transfer site class
	int iCount = D3D9_IDirect3DTexture9_Release_Super(pcThis);
	m_pcTransferSite->m_anInterfaceRefCount[AQU_SUPPORTEDINTERFACES::AQU_SupportedInterfaces::IDirect3DTexture9] = iCount;
	return iCount;
}

#pragma endregion

#pragma region IDirect3DResource9 methods

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::GetDevice(IDirect3DTexture9* pcThis, IDirect3DDevice9** ppDevice)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GetDevice");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DRESOURCE9::GetDevice);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::GetDevice,0,ppDevice);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::GetDevice);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::GetDevice,HRESULT);
		
	return D3D9_IDirect3DTexture9_GetDevice_Super(pcThis, ppDevice);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::SetPrivateData(IDirect3DTexture9* pcThis, REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::SetPrivateData");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DRESOURCE9::SetPrivateData);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPrivateData,0,refguid);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPrivateData,1,pData);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPrivateData,2,SizeOfData);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPrivateData,3,Flags);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::SetPrivateData);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::SetPrivateData,HRESULT);
		
	return D3D9_IDirect3DTexture9_SetPrivateData_Super(pcThis, refguid, pData, SizeOfData, Flags);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::GetPrivateData(IDirect3DTexture9* pcThis, REFGUID refguid,void* pData,DWORD* pSizeOfData)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GetPrivateData");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DRESOURCE9::GetPrivateData);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::GetPrivateData,0,refguid);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::GetPrivateData,1,pData);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::GetPrivateData,2,pSizeOfData);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::GetPrivateData);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::GetPrivateData,HRESULT);
		
	return D3D9_IDirect3DTexture9_GetPrivateData_Super(pcThis, refguid, pData, pSizeOfData);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::FreePrivateData(IDirect3DTexture9* pcThis, REFGUID refguid)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::FreePrivateData");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DRESOURCE9::FreePrivateData);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::FreePrivateData,0,refguid);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::FreePrivateData);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::FreePrivateData,HRESULT);

	return D3D9_IDirect3DTexture9_FreePrivateData_Super(pcThis, refguid);
}

/**
*
***/
DWORD WINAPI DCL_IDirect3DTexture9::SetPriority(IDirect3DTexture9* pcThis, DWORD PriorityNew)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::SetPriority");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DRESOURCE9::SetPriority);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPriority,0,PriorityNew);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::SetPriority);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::SetPriority,DWORD);

	return D3D9_IDirect3DTexture9_SetPriority_Super(pcThis, PriorityNew);
}

/**
*
***/
DWORD WINAPI DCL_IDirect3DTexture9::GetPriority(IDirect3DTexture9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GetPriority");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DRESOURCE9::GetPriority);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::GetPriority);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::GetPriority,DWORD);

	return D3D9_IDirect3DTexture9_GetPriority_Super(pcThis);
}

/**
*
***/
void WINAPI DCL_IDirect3DTexture9::PreLoad(IDirect3DTexture9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::PreLoad");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DRESOURCE9::PreLoad);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::PreLoad);
	AQU_IDIRECT3DTEXTURE9_REPLACE_VOID__(VMT_IDIRECT3DRESOURCE9::PreLoad);

	return D3D9_IDirect3DTexture9_PreLoad_Super(pcThis);
}

/**
*
***/
D3DRESOURCETYPE WINAPI DCL_IDirect3DTexture9::GetType(IDirect3DTexture9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GetType");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DRESOURCE9::GetType);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::GetType);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::GetType,D3DRESOURCETYPE);

	return D3D9_IDirect3DTexture9_GetType_Super(pcThis);
}


#pragma endregion

#pragma region IDirect3DBaseTexture9 methods

/**
*
***/
DWORD WINAPI DCL_IDirect3DTexture9::SetLOD(IDirect3DTexture9* pcThis, DWORD LODNew)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::SetLOD");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DBASETEXTURE9::SetLOD);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DBASETEXTURE9::SetLOD,0,LODNew);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DBASETEXTURE9::SetLOD);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DBASETEXTURE9::SetLOD,DWORD);

	return D3D9_IDirect3DTexture9_SetLOD_Super(pcThis, LODNew);
}

/**
*
***/
DWORD WINAPI DCL_IDirect3DTexture9::GetLOD(IDirect3DTexture9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GetLOD");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DBASETEXTURE9::GetLOD);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DBASETEXTURE9::GetLOD);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DBASETEXTURE9::GetLOD,DWORD);

	return D3D9_IDirect3DTexture9_GetLOD_Super(pcThis);
}

/**
*
***/
DWORD WINAPI DCL_IDirect3DTexture9::GetLevelCount(IDirect3DTexture9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GetLevelCount");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DBASETEXTURE9::GetLevelCount);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DBASETEXTURE9::GetLevelCount);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DBASETEXTURE9::GetLevelCount,DWORD);

	return D3D9_IDirect3DTexture9_GetLevelCount_Super(pcThis);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::SetAutoGenFilterType(IDirect3DTexture9* pcThis, D3DTEXTUREFILTERTYPE FilterType)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::SetAutoGenFilterType");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DBASETEXTURE9::SetAutoGenFilterType);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DBASETEXTURE9::SetAutoGenFilterType,0,FilterType);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DBASETEXTURE9::SetAutoGenFilterType);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DBASETEXTURE9::SetAutoGenFilterType,HRESULT);

	return D3D9_IDirect3DTexture9_SetAutoGenFilterType_Super(pcThis, FilterType);
}

/**
*
***/
D3DTEXTUREFILTERTYPE WINAPI DCL_IDirect3DTexture9::GetAutoGenFilterType(IDirect3DTexture9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GetAutoGenFilterType");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DBASETEXTURE9::GetAutoGenFilterType);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DBASETEXTURE9::GetAutoGenFilterType);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DBASETEXTURE9::GetAutoGenFilterType,D3DTEXTUREFILTERTYPE);

	return D3D9_IDirect3DTexture9_GetAutoGenFilterType_Super(pcThis);
}

/**
*
***/
void WINAPI DCL_IDirect3DTexture9::GenerateMipSubLevels(IDirect3DTexture9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GenerateMipSubLevels");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DBASETEXTURE9::GenerateMipSubLevels);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DBASETEXTURE9::GenerateMipSubLevels);
	AQU_IDIRECT3DTEXTURE9_REPLACE_VOID__(VMT_IDIRECT3DBASETEXTURE9::GenerateMipSubLevels);

	return D3D9_IDirect3DTexture9_GenerateMipSubLevels_Super(pcThis);
}

#pragma endregion

#pragma region IDirect3DTexture9 methods

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::GetLevelDesc(IDirect3DTexture9* pcThis, UINT Level, D3DSURFACE_DESC *pDesc)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GetLevelDesc");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DTEXTURE9::GetLevelDesc);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::GetLevelDesc,0,Level);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::GetLevelDesc,1,pDesc);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DTEXTURE9::GetLevelDesc);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DTEXTURE9::GetLevelDesc,HRESULT);
	
	return D3D9_IDirect3DTexture9_GetLevelDesc_Super(pcThis, Level, pDesc);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::GetSurfaceLevel(IDirect3DTexture9* pcThis, UINT Level,IDirect3DSurface9** ppSurfaceLevel)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::GetSurfaceLevel");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DTEXTURE9::GetSurfaceLevel);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::GetSurfaceLevel,0,Level);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::GetSurfaceLevel,1,ppSurfaceLevel);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DTEXTURE9::GetSurfaceLevel);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DTEXTURE9::GetSurfaceLevel,HRESULT);
	
	return D3D9_IDirect3DTexture9_GetSurfaceLevel_Super(pcThis, Level, ppSurfaceLevel);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::LockRect(IDirect3DTexture9* pcThis, UINT Level,D3DLOCKED_RECT* pLockedRect,CONST RECT* pRect,DWORD Flags)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::LockRect");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DTEXTURE9::LockRect);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::LockRect,0,Level);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::LockRect,1,pLockedRect);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::LockRect,2,pRect);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::LockRect,3,Flags);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DTEXTURE9::LockRect);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DTEXTURE9::LockRect,HRESULT);
	
	return D3D9_IDirect3DTexture9_LockRect_Super(pcThis, Level, pLockedRect, pRect, Flags);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::UnlockRect(IDirect3DTexture9* pcThis, UINT Level)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::UnlockRect");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DTEXTURE9::UnlockRect);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::UnlockRect,0,Level);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DTEXTURE9::UnlockRect);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DTEXTURE9::UnlockRect,HRESULT);
	
	return D3D9_IDirect3DTexture9_UnlockRect_Super(pcThis, Level);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DTexture9::AddDirtyRect(IDirect3DTexture9* pcThis, CONST RECT* pDirtyRect)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DTexture9(L"IDirect3DTexture9::AddDirtyRect");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DTEXTURE9_HEADER________(VMT_IDIRECT3DTEXTURE9::AddDirtyRect);
	AQU_IDIRECT3DTEXTURE9_SET_DATA______(VMT_IDIRECT3DTEXTURE9::AddDirtyRect,0,pDirtyRect);
	AQU_IDIRECT3DTEXTURE9_PROVOKE_______(VMT_IDIRECT3DTEXTURE9::AddDirtyRect);
	AQU_IDIRECT3DTEXTURE9_REPLACE_METHOD(VMT_IDIRECT3DTEXTURE9::AddDirtyRect,HRESULT);
	
	return D3D9_IDirect3DTexture9_AddDirtyRect_Super(pcThis, pDirtyRect);
}

#pragma endregion

#pragma region DCL_IDirect3DTexture9 public methods
/**
* Sets old function pointer by provided index.
* @param eFunc The function as listed in VMT_IUnknown.
* @param dwFunc The address of the super function as retourned by the detour method.
***/
HRESULT DCL_IDirect3DTexture9::SetSuperFunctionPointer(VMT_IUNKNOWN::VMT_IUnknown eFunc, UINT_PTR dwFunc)
{
	switch(eFunc)
	{
		/*** IUnknown super methods ***/
	case VMT_IUNKNOWN::QueryInterface:              *(PUINT_PTR)&D3D9_IDirect3DTexture9_QueryInterface_Super              = (UINT_PTR)dwFunc; break;
	case VMT_IUNKNOWN::AddRef:                      *(PUINT_PTR)&D3D9_IDirect3DTexture9_AddRef_Super                      = (UINT_PTR)dwFunc; break;
	case VMT_IUNKNOWN::Release:                     *(PUINT_PTR)&D3D9_IDirect3DTexture9_Release_Super                     = (UINT_PTR)dwFunc; break;
	}

	return S_OK;
};

/**
* Sets old function pointer by provided index.
* @param eFunc The function as listed in VMT_IDirect3DResource9.
* @param dwFunc The address of the super function as retourned by the detour method.
***/
HRESULT DCL_IDirect3DTexture9::SetSuperFunctionPointer(VMT_IDIRECT3DRESOURCE9::VMT_IDirect3DResource9 eFunc, UINT_PTR dwFunc)
{
	switch(eFunc)
	{
		/*** IDirect3DResource9 super methods ***/
	case VMT_IDIRECT3DRESOURCE9::GetDevice:       *(PUINT_PTR)&D3D9_IDirect3DTexture9_GetDevice_Super       = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::SetPrivateData:  *(PUINT_PTR)&D3D9_IDirect3DTexture9_SetPrivateData_Super  = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::GetPrivateData:  *(PUINT_PTR)&D3D9_IDirect3DTexture9_GetPrivateData_Super  = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::FreePrivateData: *(PUINT_PTR)&D3D9_IDirect3DTexture9_FreePrivateData_Super = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::SetPriority:     *(PUINT_PTR)&D3D9_IDirect3DTexture9_SetPriority_Super     = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::GetPriority:     *(PUINT_PTR)&D3D9_IDirect3DTexture9_GetPriority_Super     = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::PreLoad:         *(PUINT_PTR)&D3D9_IDirect3DTexture9_PreLoad_Super         = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::GetType:         *(PUINT_PTR)&D3D9_IDirect3DTexture9_GetType_Super         = (UINT_PTR)dwFunc; break;
	}
	return S_OK;
}

/**
* Sets old function pointer by provided index.
* @param eFunc The function as listed in VMT_IDirect3DBaseTexture9.
* @param dwFunc The address of the super function as retourned by the detour method.
***/
HRESULT DCL_IDirect3DTexture9::SetSuperFunctionPointer(VMT_IDIRECT3DBASETEXTURE9::VMT_IDirect3DBaseTexture9 eFunc, UINT_PTR dwFunc)
{
	switch(eFunc)
	{
		/*** IDirect3DBaseTexture9 super methods ***/
	case VMT_IDIRECT3DBASETEXTURE9::SetLOD:               *(PUINT_PTR)&D3D9_IDirect3DTexture9_SetLOD_Super               = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DBASETEXTURE9::GetLOD:               *(PUINT_PTR)&D3D9_IDirect3DTexture9_GetLOD_Super               = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DBASETEXTURE9::GetLevelCount:        *(PUINT_PTR)&D3D9_IDirect3DTexture9_GetLevelCount_Super        = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DBASETEXTURE9::SetAutoGenFilterType: *(PUINT_PTR)&D3D9_IDirect3DTexture9_SetAutoGenFilterType_Super = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DBASETEXTURE9::GetAutoGenFilterType: *(PUINT_PTR)&D3D9_IDirect3DTexture9_GetAutoGenFilterType_Super = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DBASETEXTURE9::GenerateMipSubLevels: *(PUINT_PTR)&D3D9_IDirect3DTexture9_GenerateMipSubLevels_Super = (UINT_PTR)dwFunc; break;
	}
	return S_OK;
}

/**
* Sets old function pointer by provided index.
* @param eFunc The function as listed in VMT_IDirect3DTexture9.
* @param dwFunc The address of the super function as retourned by the detour method.
***/
HRESULT DCL_IDirect3DTexture9::SetSuperFunctionPointer(VMT_IDIRECT3DTEXTURE9::VMT_IDirect3DTexture9 eFunc, UINT_PTR dwFunc)
{
	switch(eFunc)
	{
		/*** IDirect3DBaseTexture9 super methods ***/
	case VMT_IDIRECT3DTEXTURE9::GetLevelDesc:    *(PUINT_PTR)&D3D9_IDirect3DTexture9_GetLevelDesc_Super    = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DTEXTURE9::GetSurfaceLevel: *(PUINT_PTR)&D3D9_IDirect3DTexture9_GetSurfaceLevel_Super = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DTEXTURE9::LockRect:        *(PUINT_PTR)&D3D9_IDirect3DTexture9_LockRect_Super        = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DTEXTURE9::UnlockRect:      *(PUINT_PTR)&D3D9_IDirect3DTexture9_UnlockRect_Super      = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DTEXTURE9::AddDirtyRect:    *(PUINT_PTR)&D3D9_IDirect3DTexture9_AddDirtyRect_Super    = (UINT_PTR)dwFunc; break;
	}
	return S_OK;
}

/**
* Sets old function pointers by provided virtual methods table.
* @param pVMTable Pointer to the Virtual Methods Table.
***/
HRESULT DCL_IDirect3DTexture9::SetSuperFunctionPointers(PUINT_PTR pVMTable)
{
	if (!pVMTable) return E_FAIL;

	/*** IUnknown super methods ***/
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_QueryInterface_Super       = (UINT_PTR)pVMTable[VMT_IUNKNOWN::QueryInterface];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_AddRef_Super               = (UINT_PTR)pVMTable[VMT_IUNKNOWN::AddRef];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_Release_Super              = (UINT_PTR)pVMTable[VMT_IUNKNOWN::Release];

	/*** IDirect3DResource9 super methods ***/
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GetDevice_Super            = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::GetDevice];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_SetPrivateData_Super       = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::SetPrivateData];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GetPrivateData_Super       = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::GetPrivateData];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_FreePrivateData_Super      = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::FreePrivateData];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_SetPriority_Super          = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::SetPriority];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GetPriority_Super          = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::GetPriority];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_PreLoad_Super              = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::PreLoad];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GetType_Super              = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::GetType];

	/*** IDirect3DBaseTexture9 super methods ***/
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_SetLOD_Super               = (UINT_PTR)pVMTable[VMT_IDIRECT3DBASETEXTURE9::SetLOD];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GetLOD_Super               = (UINT_PTR)pVMTable[VMT_IDIRECT3DBASETEXTURE9::GetLOD];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GetLevelCount_Super        = (UINT_PTR)pVMTable[VMT_IDIRECT3DBASETEXTURE9::GetLevelCount];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_SetAutoGenFilterType_Super = (UINT_PTR)pVMTable[VMT_IDIRECT3DBASETEXTURE9::SetAutoGenFilterType];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GetAutoGenFilterType_Super = (UINT_PTR)pVMTable[VMT_IDIRECT3DBASETEXTURE9::GetAutoGenFilterType];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GenerateMipSubLevels_Super = (UINT_PTR)pVMTable[VMT_IDIRECT3DBASETEXTURE9::GenerateMipSubLevels];

	/*** IDirect3DTexture9 super methods ***/
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GetLevelDesc_Super         = (UINT_PTR)pVMTable[VMT_IDIRECT3DTEXTURE9::GetLevelDesc];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_GetSurfaceLevel_Super      = (UINT_PTR)pVMTable[VMT_IDIRECT3DTEXTURE9::GetSurfaceLevel];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_LockRect_Super             = (UINT_PTR)pVMTable[VMT_IDIRECT3DTEXTURE9::LockRect];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_UnlockRect_Super           = (UINT_PTR)pVMTable[VMT_IDIRECT3DTEXTURE9::UnlockRect];
	*(PUINT_PTR)&D3D9_IDirect3DTexture9_AddDirtyRect_Super         = (UINT_PTR)pVMTable[VMT_IDIRECT3DTEXTURE9::AddDirtyRect];

	return S_OK;
}
#pragma endregion