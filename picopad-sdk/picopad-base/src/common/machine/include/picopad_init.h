// ****************************************************************************
//
//                              PicoPad Init
//
// ****************************************************************************
// Interface and part of the code taken from Picopad SDK
// https://github.com/pajenicko/picopad

#ifndef _PICOPAD_INIT_H
#define _PICOPAD_INIT_H

#ifdef __cplusplus
extern "C" {
#endif

#include "picopad.h"

// Device init
void DeviceInit(bool load_config_from_sd = False);

// Device terminate
void DeviceTerm();

#ifdef __cplusplus
}
#endif

#endif // _PICOPAD_INIT_H
