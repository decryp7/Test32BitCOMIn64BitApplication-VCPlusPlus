// dllmain.h : Declaration of module class.

class CMy32BitComLibraryModule : public ATL::CAtlDllModuleT< CMy32BitComLibraryModule >
{
public :
	DECLARE_LIBID(LIBID_My32BitComLibraryLib)
	DECLARE_REGISTRY_APPID_RESOURCEID(IDR_MY32BITCOMLIBRARY, "{6e93d5da-e8fb-4a06-92aa-191bf716e618}")
};

extern class CMy32BitComLibraryModule _AtlModule;
