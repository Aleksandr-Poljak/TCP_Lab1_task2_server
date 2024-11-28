#pragma once
#include "objbase.h"

// {5D22066B-45D2-4AFF-8FB6-377A1AAF33A8}
DEFINE_GUID(CLSID_FN_14,
	0x5d22066b, 0x45d2, 0x4aff, 0x8f, 0xb6, 0x37, 0x7a, 0x1a, 0xaf, 0x33, 0xa8);

// {85E2851B-84C4-4DCC-84D6-1C05429A157D}
DEFINE_GUID(IID_FN_14,
	0x85e2851b, 0x84c4, 0x4dcc, 0x84, 0xd6, 0x1c, 0x5, 0x42, 0x9a, 0x15, 0x7d);

/// <summary>
///  CFN_14 component interface
/// </summary>
class IFN_14 : public IUnknown
{
public:
	STDMETHOD(Fun141(int, int, int*)) PURE;
	STDMETHOD(Fun142(int, int , int, int*)) PURE;
	STDMETHOD(Fun143(double, double*)) PURE;
};


