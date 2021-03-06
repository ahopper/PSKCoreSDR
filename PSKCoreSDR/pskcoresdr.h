/* Copyright (C)
* 2000 - Moe Wheatley, AE4JY
* 2016 - Alan Hopper, 2E0NNB
* 2016 - John Melton, G0ORX/N6LYT
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 2
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program; if not, write to the Free Software
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*
*/


// The following ifdef block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the PSKCORE_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// PSKCORE_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
//#define PSKCORE_EXPORTS
#ifdef PSKCORE_EXPORTS
#ifdef linux
#define PSKCORE_API extern
#else
#define PSKCORE_API __declspec(dllexport)
#endif
#else
#define PSKCORE_API 
#endif

#ifdef __cplusplus
extern "C" {
#endif

	typedef int(* getNextCharCallback)(void* context);

	PSKCORE_API void* createPSKDet();
	PSKCORE_API void* initPSKDet(int fs);
	PSKCORE_API void setupPSKDet(void* det, int fs);

	PSKCORE_API int runPSKDet(void* det, double * inp, int len, int stride, char* result, int resultLen);
	PSKCORE_API void freePSKDet(void* det);
	PSKCORE_API void SetSquelchThresh(void* det, int limit);
	PSKCORE_API void SetRXFrequency(void* det, int frequency);
	PSKCORE_API int GetRXFrequency(void* det);
	PSKCORE_API int GetSignalLevel(void* det);
	PSKCORE_API void SetAFCLimit(void* det, int limit);
	PSKCORE_API void ResetDetector(void* det);
	PSKCORE_API void SetRXPSKMode(void* det,int mode);

	PSKCORE_API void* createPSKMod(int fs, double maxAmplitude);
	PSKCORE_API void freePSKMod(void* mod);
	PSKCORE_API void SetTXFrequency(void* mod, int frequency);
	PSKCORE_API void CalcPSK(void* mod, double* pData, int n, int stride);
	PSKCORE_API void PutTxQue(void* mod, int ch);
	PSKCORE_API void SetCallback(void* mod, void* context, getNextCharCallback callback);
	PSKCORE_API void SetMode(void* mod, int mode);


#ifdef __cplusplus
}
#endif
