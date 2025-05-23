#ifndef MXOBJECTFACTORY_H
#define MXOBJECTFACTORY_H

#include "mxatom.h"
#include "mxcore.h"

#define FOR_MXOBJECTFACTORY_OBJECTS(X)                                                                                 \
	X(MxPresenter)                                                                                                     \
	X(MxCompositePresenter)                                                                                            \
	X(MxVideoPresenter)                                                                                                \
	X(MxFlcPresenter)                                                                                                  \
	X(MxSmkPresenter)                                                                                                  \
	X(MxStillPresenter)                                                                                                \
	X(MxWavePresenter)                                                                                                 \
	X(MxEventPresenter)                                                                                                \
	X(MxLoopingFlcPresenter)                                                                                           \
	X(MxLoopingSmkPresenter)

// VTABLE: LEGO1 0x100dc220
// VTABLE: BETA10 0x101c2280
class MxObjectFactory : public MxCore {
public:
	MxObjectFactory();

	// FUNCTION: LEGO1 0x10008f70
	// FUNCTION: BETA10 0x100a5d20
	const char* ClassName() const override // vtable+0x0c
	{
		// STRING: LEGO1 0x100f0730
		return "MxObjectFactory";
	}

	// FUNCTION: LEGO1 0x10008f80
	MxBool IsA(const char* p_name) const override // vtable+0x10
	{
		return !strcmp(p_name, MxObjectFactory::ClassName()) || MxCore::IsA(p_name);
	}

	virtual MxCore* Create(const char* p_name); // vtable+0x14
	virtual void Destroy(MxCore* p_object);     // vtable+0x18

	// SYNTHETIC: LEGO1 0x100b1160
	// MxObjectFactory::`scalar deleting destructor'

	// SYNTHETIC: LEGO1 0x10009020
	// MxObjectFactory::~MxObjectFactory

private:
#define X(V) MxAtomId m_id##V;
	FOR_MXOBJECTFACTORY_OBJECTS(X)
#undef X
};

#endif // MXOBJECTFACTORY_H
