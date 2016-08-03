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

// PSKCoreSDR.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "PSKCoreSDR.h"
#include "PskDet.h"
#include "PSKMod.h"


PSKCORE_API void* createPSKDet(int fs)
{
	CPSKDet* d = new CPSKDet();
	d->Init(fs);

	return d;
}
PSKCORE_API int runPSKDet(void* det, double * inp, int len, int stride, char* result, int resultLen)
{
	return ((CPSKDet*)det)->ProcPSKDet(inp, len, stride, result, resultLen);
}
PSKCORE_API void freePSKDet(void* det)
{
	delete ((CPSKDet*)det);
}
PSKCORE_API void SetSquelchThresh(void* det, int limit)
{
	((CPSKDet*)det)->SetSquelchThresh(limit, 75);
}
PSKCORE_API void SetRXFrequency(void* det, int frequency)
{
	((CPSKDet*)det)->SetRXFrequency(frequency);
}
PSKCORE_API int GetRXFrequency(void* det)
{
	return ((CPSKDet*)det)->GetRXFrequency();
}
PSKCORE_API int GetSignalLevel(void* det)
{
	return ((CPSKDet*)det)->GetSignalLevel();
}
PSKCORE_API void SetAFCLimit(void* det, int limit)
{
	((CPSKDet*)det)->SetAFCLimit(limit);
}
PSKCORE_API void ResetDetector(void* det)
{
	((CPSKDet*)det)->ResetDetector();
}


PSKCORE_API void* createPSKMod(int fs, double maxAmplitude)
{
	CPSKMod* m = new CPSKMod();
	m->InitPSKMod(fs,maxAmplitude);
	return m;
}
PSKCORE_API void freePSKMod(void* mod)
{
	delete ((CPSKMod*)mod);
}
PSKCORE_API void SetTXFrequency(void* mod, int frequency)
{
	((CPSKMod*)mod)->SetTXFreq(frequency);
}
PSKCORE_API void CalcPSK(void* mod, double* pData, int n, int stride)
{
	((CPSKMod*)mod)->CalcPSK(pData, n, stride);
}
PSKCORE_API void PutTxQue(void* mod, int ch)
{
	((CPSKMod*)mod)->PutTxQue(ch, false);
}



