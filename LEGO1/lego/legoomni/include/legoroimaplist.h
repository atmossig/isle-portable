#ifndef LEGOROIMAPLIST_H
#define LEGOROIMAPLIST_H

#include "mxlist.h"
#include "mxtypes.h"

class LegoROI;

// VTABLE: LEGO1 0x100d9218
// class MxCollection<LegoROI **>

// VTABLE: LEGO1 0x100d9230
// class MxList<LegoROI **>

// VTABLE: LEGO1 0x100d9248
// class MxPtrList<LegoROI *>

// Specialize MxPtrList for LegoROI* in order to fix Destroy.
// TODO: Change to using constexpr in MxPtrList<T>::Destroy once C++17 standard works.
template <>
class MxPtrList<LegoROI*> : public MxList<LegoROI**> {
public:
	MxPtrList(MxBool p_ownership) { SetOwnership(p_ownership); }

	static void Destroy(LegoROI** p_obj) { delete[] p_obj; }

	void SetOwnership(MxBool p_ownership)
	{
		MxCollection<LegoROI**>::SetDestroy(
			p_ownership ? MxPtrList<LegoROI*>::Destroy : MxCollection<LegoROI**>::Destroy
		);
	}
};

// VTABLE: LEGO1 0x100d9260
// SIZE 0x18
class LegoROIMapList : public MxPtrList<LegoROI*> {
public:
	LegoROIMapList() : MxPtrList<LegoROI*>(TRUE) {}

	// SYNTHETIC: LEGO1 0x1006d360
	// LegoROIMapList::`scalar deleting destructor'
};

// TEMPLATE: LEGO1 0x1006d250
// MxCollection<LegoROI * *>::Compare

// TEMPLATE: LEGO1 0x1006d260
// MxCollection<LegoROI * *>::~MxCollection<LegoROI * *>

// TEMPLATE: LEGO1 0x1006d2b0
// MxCollection<LegoROI * *>::Destroy

// TEMPLATE: LEGO1 0x1006d2c0
// MxList<LegoROI * *>::~MxList<LegoROI * *>

// TEMPLATE: LEGO1 0x1006d3d0
// MxPtrList<LegoROI *>::~MxPtrList<LegoROI *>

// TEMPLATE: LEGO1 0x1006d350
// MxPtrList<LegoROI *>::Destroy

// SYNTHETIC: LEGO1 0x1006d420
// MxCollection<LegoROI * *>::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x1006d490
// MxList<LegoROI * *>::`scalar deleting destructor'

// SYNTHETIC: LEGO1 0x1006d540
// MxPtrList<LegoROI *>::`scalar deleting destructor'

#endif // LEGOROIMAPLIST_H
