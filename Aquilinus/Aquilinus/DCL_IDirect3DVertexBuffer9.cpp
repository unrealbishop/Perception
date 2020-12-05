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
#define OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(...) ::OutputDebugString((tstringstream(), _T("***"), __VA_ARGS__, _T("\n")).str().c_str());
#else
#define OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(...)
#endif
#define AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(a) if ((!m_pcTransferSite->m_bForceD3D) && (m_pcTransferSite->m_ppNOD_IDirect3DVertexBuffer9[a]) && (m_pcTransferSite->m_ppNOD_IDirect3DVertexBuffer9[a]->m_cProvoker.m_paInvokers.size() > 0)) {
#define AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(a,b,c) m_pcTransferSite->m_ppNOD_IDirect3DVertexBuffer9[a]->m_paCommandersTemporary[b]->m_pOutput = (void*)&c;
#define AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(a) m_pcTransferSite->m_bForceD3D = true; void* pvRet = m_pcTransferSite->m_ppNOD_IDirect3DVertexBuffer9[a]->Provoke((void*)pcThis, m_pcTransferSite->m_ppaNodes); m_pcTransferSite->m_bForceD3D = false;
#define AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(a,b) if ((*m_pcTransferSite->m_ppaNodes)[m_pcTransferSite->m_ppNOD_IDirect3DVertexBuffer9[a]->m_cProvoker.m_paInvokers[0]->m_lNodeIndex]->m_bReturn){ static b hr = (b)*(b*)pvRet; return hr; } }
#define AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_VOID__(a) if ((*m_pcTransferSite->m_ppaNodes)[m_pcTransferSite->m_ppNOD_IDirect3DVertexBuffer9[a]->m_cProvoker.m_paInvokers[0]->m_lNodeIndex]->m_bReturn){ return; } }

#include"DCL_IDirect3DVertexBuffer9.h"
#include"DCL_IDirect3DVertexBuffer9_Super.h"

#pragma region DCL_IDirect3DVertexBuffer9 constructor/destructor

/**
*
***/
DCL_IDirect3DVertexBuffer9::DCL_IDirect3DVertexBuffer9(AQU_TransferSite* pcTransferSite) : 
	m_pcTransferSite(pcTransferSite)
{}

/**
*
***/
DCL_IDirect3DVertexBuffer9::~DCL_IDirect3DVertexBuffer9(){}

#pragma endregion

#pragma region IUnknown methods

/**
*
***/
HRESULT WINAPI DCL_IDirect3DVertexBuffer9::QueryInterface(IDirect3DVertexBuffer9* pcThis, REFIID riid, void** ppvObj)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::QueryInterface");
	return D3D9_IDirect3DVertexBuffer9_QueryInterface_Super(pcThis, riid, ppvObj);
}

/**
*
***/
ULONG WINAPI DCL_IDirect3DVertexBuffer9::AddRef(IDirect3DVertexBuffer9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::AddRef");
	
	// set reference counter in the transfer site class
	int iCount = D3D9_IDirect3DVertexBuffer9_AddRef_Super(pcThis);
	m_pcTransferSite->m_anInterfaceRefCount[AQU_SUPPORTEDINTERFACES::AQU_SupportedInterfaces::IDirect3DVertexBuffer9] = iCount;
	return iCount;
}

/**
*
***/
ULONG WINAPI DCL_IDirect3DVertexBuffer9::Release(IDirect3DVertexBuffer9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::Release");
	
	// set reference counter in the transfer site class
	int iCount = D3D9_IDirect3DVertexBuffer9_Release_Super(pcThis);
	m_pcTransferSite->m_anInterfaceRefCount[AQU_SUPPORTEDINTERFACES::AQU_SupportedInterfaces::IDirect3DVertexBuffer9] = iCount;
	return iCount;
}

#pragma endregion

#pragma region IDirect3DResource9 methods

/**
*
***/
HRESULT WINAPI DCL_IDirect3DVertexBuffer9::GetDevice(IDirect3DVertexBuffer9* pcThis, IDirect3DDevice9** ppDevice)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::GetDevice");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DRESOURCE9::GetDevice);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::GetDevice,0,ppDevice);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::GetDevice);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::GetDevice,HRESULT);

	return D3D9_IDirect3DVertexBuffer9_GetDevice_Super(pcThis, ppDevice);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DVertexBuffer9::SetPrivateData(IDirect3DVertexBuffer9* pcThis, REFGUID refguid,CONST void* pData,DWORD SizeOfData,DWORD Flags)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::SetPrivateData");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DRESOURCE9::SetPrivateData);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPrivateData,0,refguid);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPrivateData,1,pData);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPrivateData,2,SizeOfData);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPrivateData,3,Flags);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::SetPrivateData);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::SetPrivateData,HRESULT);

	return D3D9_IDirect3DVertexBuffer9_SetPrivateData_Super(pcThis, refguid, pData, SizeOfData, Flags);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DVertexBuffer9::GetPrivateData(IDirect3DVertexBuffer9* pcThis, REFGUID refguid,void* pData,DWORD* pSizeOfData)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::GetPrivateData");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DRESOURCE9::GetPrivateData);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::GetPrivateData,0,refguid);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::GetPrivateData,1,pData);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::GetPrivateData,2,pSizeOfData);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::GetPrivateData);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::GetPrivateData,HRESULT);

	return D3D9_IDirect3DVertexBuffer9_GetPrivateData_Super(pcThis, refguid, pData, pSizeOfData);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DVertexBuffer9::FreePrivateData(IDirect3DVertexBuffer9* pcThis, REFGUID refguid)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::FreePrivateData");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DRESOURCE9::FreePrivateData);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::FreePrivateData,0,refguid);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::FreePrivateData);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::FreePrivateData,HRESULT);

	return D3D9_IDirect3DVertexBuffer9_FreePrivateData_Super(pcThis, refguid);
}

/**
*
***/
DWORD WINAPI DCL_IDirect3DVertexBuffer9::SetPriority(IDirect3DVertexBuffer9* pcThis, DWORD PriorityNew)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::SetPriority");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DRESOURCE9::SetPriority);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DRESOURCE9::SetPriority,0,PriorityNew);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::SetPriority);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::SetPriority,DWORD);

	return D3D9_IDirect3DVertexBuffer9_SetPriority_Super(pcThis, PriorityNew);
}

/**
*
***/
DWORD WINAPI DCL_IDirect3DVertexBuffer9::GetPriority(IDirect3DVertexBuffer9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::GetPriority");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DRESOURCE9::GetPriority);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::GetPriority);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::GetPriority,DWORD);

	return D3D9_IDirect3DVertexBuffer9_GetPriority_Super(pcThis);
}

/**
*
***/
void WINAPI DCL_IDirect3DVertexBuffer9::PreLoad(IDirect3DVertexBuffer9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::PreLoad");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DRESOURCE9::PreLoad);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::PreLoad);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_VOID__(VMT_IDIRECT3DRESOURCE9::PreLoad);

	return D3D9_IDirect3DVertexBuffer9_PreLoad_Super(pcThis);
}

/**
*
***/
D3DRESOURCETYPE WINAPI DCL_IDirect3DVertexBuffer9::GetType(IDirect3DVertexBuffer9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::GetType");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DRESOURCE9::GetType);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DRESOURCE9::GetType);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DRESOURCE9::GetType,D3DRESOURCETYPE);

	return D3D9_IDirect3DVertexBuffer9_GetType_Super(pcThis);
}


#pragma endregion

#pragma region IDirect3DVertexBuffer9 methods

/**
*
***/
HRESULT WINAPI DCL_IDirect3DVertexBuffer9::Lock(IDirect3DVertexBuffer9* pcThis, UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::Lock");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DVERTEXBUFFER9::Lock);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DVERTEXBUFFER9::Lock,0,OffsetToLock);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DVERTEXBUFFER9::Lock,1,SizeToLock);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DVERTEXBUFFER9::Lock,2,ppbData);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DVERTEXBUFFER9::Lock,3,Flags);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DVERTEXBUFFER9::Lock);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DVERTEXBUFFER9::Lock,DWORD);

	return D3D9_IDirect3DVertexBuffer9_Lock_Super(pcThis, OffsetToLock, SizeToLock, ppbData, Flags);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DVertexBuffer9::Unlock(IDirect3DVertexBuffer9* pcThis)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::Unlock");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DVERTEXBUFFER9::Unlock);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DVERTEXBUFFER9::Unlock);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DVERTEXBUFFER9::Unlock,DWORD);

	return D3D9_IDirect3DVertexBuffer9_Unlock_Super(pcThis);
}

/**
*
***/
HRESULT WINAPI DCL_IDirect3DVertexBuffer9::GetDesc(IDirect3DVertexBuffer9* pcThis, D3DVERTEXBUFFER_DESC *pDesc)
{ 
	OUTPUT_DEBUG_STRING_IDirect3DVertexBuffer9(L"IDirect3DVertexBuffer9::GetDesc");

	// watch DCL_IDirect3DDevice9.cpp for detailed code (without macros)
	AQU_IDIRECT3DVERTEXBUFFER9_HEADER________(VMT_IDIRECT3DVERTEXBUFFER9::GetDesc);
	AQU_IDIRECT3DVERTEXBUFFER9_SET_DATA______(VMT_IDIRECT3DVERTEXBUFFER9::GetDesc,0,pDesc);
	AQU_IDIRECT3DVERTEXBUFFER9_PROVOKE_______(VMT_IDIRECT3DVERTEXBUFFER9::GetDesc);
	AQU_IDIRECT3DVERTEXBUFFER9_REPLACE_METHOD(VMT_IDIRECT3DVERTEXBUFFER9::GetDesc,DWORD);

	return D3D9_IDirect3DVertexBuffer9_GetDesc_Super(pcThis, pDesc);
}

#pragma endregion

#pragma region DCL_IDirect3DVertexBuffer9 public methods
/**
* Sets old function pointer by provided index.
* @param eFunc The function as listed in VMT_IUnknown.
* @param dwFunc The address of the super function as retourned by the detour method.
***/
HRESULT DCL_IDirect3DVertexBuffer9::SetSuperFunctionPointer(VMT_IUNKNOWN::VMT_IUnknown eFunc, UINT_PTR dwFunc)
{
	switch(eFunc)
	{
		/*** IUnknown super methods ***/
	case VMT_IUNKNOWN::QueryInterface:              *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_QueryInterface_Super              = (UINT_PTR)dwFunc; break;
	case VMT_IUNKNOWN::AddRef:                      *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_AddRef_Super                      = (UINT_PTR)dwFunc; break;
	case VMT_IUNKNOWN::Release:                     *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_Release_Super                     = (UINT_PTR)dwFunc; break;
	}

	return S_OK;
};

/**
* Sets old function pointer by provided index.
* @param eFunc The function as listed in VMT_IDirect3DResource9.
* @param dwFunc The address of the super function as retourned by the detour method.
***/
HRESULT DCL_IDirect3DVertexBuffer9::SetSuperFunctionPointer(VMT_IDIRECT3DRESOURCE9::VMT_IDirect3DResource9 eFunc, UINT_PTR dwFunc)
{
	switch(eFunc)
	{
		/*** IDirect3DResource9 super methods ***/
	case VMT_IDIRECT3DRESOURCE9::GetDevice:       *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetDevice_Super       = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::SetPrivateData:  *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_SetPrivateData_Super  = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::GetPrivateData:  *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetPrivateData_Super  = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::FreePrivateData: *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_FreePrivateData_Super = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::SetPriority:     *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_SetPriority_Super     = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::GetPriority:     *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetPriority_Super     = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::PreLoad:         *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_PreLoad_Super         = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DRESOURCE9::GetType:         *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetType_Super         = (UINT_PTR)dwFunc; break;
	}
	return S_OK;
}

/**
* Sets old function pointer by provided index.
* @param eFunc The function as listed in VMT_IDirect3DVertexBuffer9.
* @param dwFunc The address of the super function as retourned by the detour method.
***/
HRESULT DCL_IDirect3DVertexBuffer9::SetSuperFunctionPointer(VMT_IDIRECT3DVERTEXBUFFER9::VMT_IDirect3DVertexBuffer9 eFunc, UINT_PTR dwFunc)
{
	switch(eFunc)
	{
		/*** IDirect3DVertexBuffer9 super methods ***/
	case VMT_IDIRECT3DVERTEXBUFFER9::Lock:    *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_Lock_Super    = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DVERTEXBUFFER9::Unlock:  *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_Unlock_Super  = (UINT_PTR)dwFunc; break;
	case VMT_IDIRECT3DVERTEXBUFFER9::GetDesc: *(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetDesc_Super = (UINT_PTR)dwFunc; break;
	}
	return S_OK;
}

/**
* Sets old function pointers by provided virtual methods table.
* @param pVMTable Pointer to the Virtual Methods Table.
***/
HRESULT DCL_IDirect3DVertexBuffer9::SetSuperFunctionPointers(PUINT_PTR pVMTable)
{
	if (!pVMTable) return E_FAIL;

	/*** IUnknown super methods ***/
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_QueryInterface_Super  = (UINT_PTR)pVMTable[VMT_IUNKNOWN::QueryInterface];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_AddRef_Super          = (UINT_PTR)pVMTable[VMT_IUNKNOWN::AddRef];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_Release_Super         = (UINT_PTR)pVMTable[VMT_IUNKNOWN::Release];

	/*** IDirect3DResource9 super methods ***/
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetDevice_Super       = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::GetDevice];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_SetPrivateData_Super  = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::SetPrivateData];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetPrivateData_Super  = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::GetPrivateData];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_FreePrivateData_Super = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::FreePrivateData];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_SetPriority_Super     = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::SetPriority];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetPriority_Super     = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::GetPriority];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_PreLoad_Super         = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::PreLoad];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetType_Super         = (UINT_PTR)pVMTable[VMT_IDIRECT3DRESOURCE9::GetType];

	/*** IDirect3DVertexBuffer9 super methods ***/
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_Lock_Super            = (UINT_PTR)pVMTable[VMT_IDIRECT3DVERTEXBUFFER9::Lock];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_Unlock_Super          = (UINT_PTR)pVMTable[VMT_IDIRECT3DVERTEXBUFFER9::Unlock];
	*(PUINT_PTR)&D3D9_IDirect3DVertexBuffer9_GetDesc_Super         = (UINT_PTR)pVMTable[VMT_IDIRECT3DVERTEXBUFFER9::GetDesc];

	return S_OK;
}
#pragma endregion