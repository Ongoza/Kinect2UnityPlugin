#ifdef NTKINECTDLL_EXPORTS
#define NTKINECTDLL_API __declspec(dllexport)
#else
#define NTKINECTDLL_API __declspec(dllimport)
#endif
namespace NtKinectDLL {
	extern "C" {
		NTKINECTDLL_API void* getKinect(void);
		NTKINECTDLL_API void stopKinect(void* ptr);
		NTKINECTDLL_API int setSkeleton(void* ptr, float* skeleton, int* state, int* id, bool isShow);
	//	NTKINECTDLL_API int faceDirection(void* ptr, float* dir);
	}
}