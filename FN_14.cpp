#include <windows.h>
#include "CFN_14.h"

// Realization of FN_14 class methods

CFN_14::CFN_14()
{
	m_lRef = 0;
	InterlockedIncrement(&g_lObjs);
}

CFN_14::~CFN_14()
{
	InterlockedDecrement(&g_lObjs);
}

STDMETHODIMP CFN_14::QueryInterface(REFIID riid, void** ppv)
{
	*ppv = 0;
	if (riid == IID_IUnknown || riid == IID_FN_14)
		*ppv = this;
	if (*ppv)
	{
		AddRef();
		return(S_OK);
	}
	return (E_NOINTERFACE);
};

STDMETHODIMP_(ULONG) CFN_14::AddRef()
{
	return InterlockedIncrement(&m_lRef);
}

STDMETHODIMP_(ULONG) CFN_14::Release()
{
	if (InterlockedDecrement(&m_lRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_lRef;
}

STDMETHODIMP CFN_14::Fun141(int op1, int op2, int* pResult)
{
	*pResult = op1 + op2;
	return S_OK;
}

STDMETHODIMP CFN_14::Fun142(int op1, int op2, int op3, int* pResult)
{
	*pResult = op1 + op2 + op3;
	return S_OK;
}

STDMETHODIMP CFN_14::Fun143(double in, double* out)
{
	*out = in * in;
	return S_OK;
}

// Realization of CFN_14 class FN_14ClassFactory

FN_14ClassFactory::FN_14ClassFactory()
{
	m_lRef = 0;
}

FN_14ClassFactory::~FN_14ClassFactory()
{
}

STDMETHODIMP_(ULONG) FN_14ClassFactory::AddRef()
{
	return InterlockedIncrement(&m_lRef);
}

STDMETHODIMP_(ULONG) FN_14ClassFactory::Release()
{
	if (InterlockedDecrement(&m_lRef) == 0)
	{
		delete this;
		return 0;
	}
	return m_lRef;
}

STDMETHODIMP FN_14ClassFactory::QueryInterface(REFIID riid,
	void** ppv)
{
	*ppv = 0;
	if (riid == IID_IUnknown || riid == IID_IClassFactory)
		*ppv = this;
	if (*ppv)
	{
		AddRef();
		return S_OK;
	}
	return(E_NOINTERFACE);
}

STDMETHODIMP FN_14ClassFactory::CreateInstance(LPUNKNOWN pUnkOuter, REFIID riid, void** ppvObj)
{
	CFN_14* pFN_14;
	HRESULT hr;
	*ppvObj = 0;
	pFN_14 = new CFN_14;
	if (pFN_14 == 0)
	{
		return(E_OUTOFMEMORY);
	}
	hr = pFN_14->QueryInterface(riid, ppvObj);
	if (FAILED(hr))
		delete pFN_14;
	return hr;
}

STDMETHODIMP FN_14ClassFactory::LockServer(BOOL fLock)
{
	if (fLock)
		InterlockedIncrement(&g_lLocks);
	else
		InterlockedDecrement(&g_lLocks);
	return S_OK;
}