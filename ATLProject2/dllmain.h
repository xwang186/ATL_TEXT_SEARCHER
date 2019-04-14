// dllmain.h : Declaration of module class.

class CATLProject2Module : public ATL::CAtlDllModuleT< CATLProject2Module >
{
public :
	DECLARE_LIBID(LIBID_ATLProject2Lib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_ATLPROJECT2, "{0FB599C4-1455-438A-95B9-A490B5569DF3}")
};

extern class CATLProject2Module _AtlModule;
