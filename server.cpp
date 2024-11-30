#include <windows.h>
#include <initguid.h>
#include "CFN_14.h"
#include "REGISTRY.H"

long g_lObjs = 0;
long g_lLocks = 0;

static HMODULE g_hModule = NULL;   // DLL module handle
// Friendly name of component
const char g_szFriendlyName[] = "TCP_Lab1 FN_14 Component";
// Version-independent ProgID
const char g_szVerIndProgID[] = "Server30331.FN_14Com";
// ProgID
const char g_szProgID[] = "Server30331.FN_14Com.1";



STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, void**
	ppv)
{
	HRESULT hr;
	FN_14ClassFactory* pCF;
	pCF = 0;

	// Make sure the CLSID is for our Expression component
	if (rclsid != CLSID_FN_14)
		return(E_FAIL);
	pCF = new FN_14ClassFactory;
	if (pCF == 0)
	{
		return(E_OUTOFMEMORY);
	}


	hr = pCF->QueryInterface(riid, ppv);
	// Check for failure of QueryInterface
	if (FAILED(hr))
	{
		delete pCF;
		pCF = 0;
	}
	return hr;
}

STDAPI DllCanUnloadNow(void)
{
	if (g_lObjs || g_lLocks)
		return(S_FALSE);
	else
		return(S_OK);
}

//
// Server registration
//
STDAPI DllRegisterServer()
{
	return RegisterServer(g_hModule,
		CLSID_FN_14,
		g_szFriendlyName,
		g_szVerIndProgID,
		g_szProgID);
}

//
// Server underregistration
//
STDAPI DllUnregisterServer()
{
	return UnregisterServer(CLSID_FN_14,
		g_szVerIndProgID,
		g_szProgID);
}

/// <summary>
/// DLL module information
/// </summary>
BOOL APIENTRY DllMain(HANDLE hModule,
	DWORD dwReason,
	void* lpReserved)
{
	if (dwReason == DLL_PROCESS_ATTACH)
	{
		g_hModule = (HMODULE)hModule;
	}
	return TRUE;
}