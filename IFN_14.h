#pragma once
#include "objbase.h"

// {5D22066B-45D2-4AFF-8FB6-377A1AAF33A8}
DEFINE_GUID(CLSID_FN_14,
	0x5d22066b, 0x45d2, 0x4aff, 0x8f, 0xb6, 0x37, 0x7a, 0x1a, 0xaf, 0x33, 0xa8);

// {85E2851B-84C4-4DCC-84D6-1C05429A157D}
DEFINE_GUID(IID_FN_14,
	0x85e2851b, 0x84c4, 0x4dcc, 0x84, 0xd6, 0x1c, 0x5, 0x42, 0x9a, 0x15, 0x7d);

// {41C9B100-6D5E-4E87-A371-8B3959E9683B}
DEFINE_GUID(IID_IVer,
	0x41c9b100, 0x6d5e, 0x4e87, 0xa3, 0x71, 0x8b, 0x39, 0x59, 0xe9, 0x68, 0x3b);


/// <summary>
///  CFN_14 component interface
/// </summary>
class IFN_14 : public IUnknown
{
public:
	STDMETHOD(Fun141(int, int, int*)) PURE;
	STDMETHOD(Fun142(int, int, int, int*)) PURE;
	STDMETHOD(Fun143(double, double*)) PURE;
};

class IVer : public IUnknown
{
public:
	STDMETHOD(GetAuthor(WCHAR* name, WCHAR** message)) PURE;
};