#pragma once
#include "IFN_14.h"

extern long g_lObjs;
extern long g_lLocks;

class CFN_14 :public IFN_14
{
protected:
	// Reference count
	long m_lRef;

public:
	CFN_14();
	~CFN_14();

	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());

	// IFN_14
	STDMETHOD(Fun141(int, int, int*));
	STDMETHOD(Fun142(int, int, int, int*));
	STDMETHOD(Fun143(double, double*));
};

/// <summary>
/// Class factory class
/// </summary>
class FN_14ClassFactory : public IClassFactory
{
protected:
	long m_lRef;

public:

	FN_14ClassFactory();
	~FN_14ClassFactory();

	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());


	// IClassFactory
	STDMETHOD(CreateInstance(LPUNKNOWN, REFIID, void**));
	STDMETHOD(LockServer(BOOL));
};