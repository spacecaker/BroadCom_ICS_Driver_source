/* ============================================================================
Copyright (c) 2006-2014, Broadcom Corporation
All rights reserved.
Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
1. Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
2. Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
3. Neither the name of the copyright holder nor the names of its contributors may be used to endorse or promote products derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
============================================================================ */

#ifndef _METADATA_FOURCC_H
#define _METADATA_FOURCC_H

/******************************************************************************
Definition of 4CCs assigned to metadata items. This list acts more as a 
central repository of 4CCs for different metadata items so as to avoid clashes. 
They are not otherwise necessary for library to function correctly.
******************************************************************************/

/*
   Note: Multi-character constants are not valid C and although supported by 
   some compilers such as Metaware, they are ambiguous in how they should be 
   packed into a long due to endian-ness (and also due to size for 2 and 3 
   character constants).
*/

typedef enum {

   METADATA_CDI                  = ('C'<<24)+('D'<<16)+('M'<<8)+('D'),   // 'CDMD'    struct CDI_METADATA_T in /middleware/camplus/cdi/cdi.h 
   METADATA_TIMING               = ('T'<<24)+('I'<<16)+('M'<<8)+('E'),   // 'TIME'    struct TIMING_METADATA_T in /middleware/camplus/cdi/cdi.h
   METADATA_CDI_FILE             = ( 0 <<24)+('C'<<16)+('D'<<8)+('F'),   // '\x00CDF' struct CDI_FILE_METADATA_T in /middleware/camplus/cdi/cdi_file.h
   METADATA_CDI_RAW              = ('C'<<24)+('D'<<16)+('R'<<8)+('W'),   // 'CDRW'    struct CDI_FILE_RAW_METADATA_T in /middleware/camplus/cdi/cdi_file_raw.h
   METADATA_STABILISE            = ('S'<<24)+('T'<<16)+('A'<<8)+('B'),   // 'STAB'    struct GLOBAL_MOTION_VECTOR_T in /middleware/camplus/sw/stabilise/stabilise.h
   METADATA_LOCAL_MV1            = ('L'<<24)+('M'<<16)+('V'<<8)+('1'),   // 'LMV1'    struct ALL_LOCAL_MOTION_VECTORS_T in /middleware/camplus/sw/stabilise/stabilise.h
   METADATA_LOCAL_MV2            = ('L'<<24)+('M'<<16)+('V'<<8)+('2'),   // 'LMV2'    struct ALL_LOCAL_MOTION_VECTORS_T in /middleware/camplus/sw/stabilise/stabilise.h
   METADATA_TUNER_AGC            = ( 0 <<24)+('A'<<16)+('G'<<8)+('C'),   // '\x00AGC' struct ISP_AGC_METADATA_T in /middleware/ISP/tuner/isp_tuner_ctrl.h
   METADATA_AGC_DEBUG            = ('A'<<24)+('G'<<16)+('C'<<8)+('D'),   // 'AGCD'    struct ISP_TUNER_BRCM_AGC_DEBUG_T in /middleware/ISP/tuner/isp_tuner_agc.h
   METADATA_FOCUS_REGION         = ('F'<<24)+('R'<<16)+('G'<<8)+('N'),   // 'FRGN'    struct ISP_TUNER_BRCM_AF_STATISTICS_PARAMS_T in /middleware/ISP/tuner/isp_tuner_brcm_common.h
   METADATA_FOCUS_WOI            = ('F'<<24)+('W'<<16)+('O'<<8)+('I'),   // 'FWOI'    struct ISP_WOI_METADATA_T in /middleware/ISP/tuner/isp_tuner_ctrl.h
   METADATA_AUTOFOCUS            = ( 0 <<24)+( 0 <<16)+('A'<<8)+('F'),   // '\x00\x00AF'  struct ISP_AF_METADATA_T in /middleware/ISP/tuner/isp_tuner_ctrl.h
   METADATA_EV                   = ('E'<<24)+('V'<<16)+('M'<<8)+('D'),   // 'EVMD'    struct ISP_TUNER_BRCM_EV_METADATA_T in /middleware/ISP/tuner/isp_tuner_brcm_common.h
   METADATA_ISP                  = ('I'<<24)+('S'<<16)+('P'<<8)+('M'),   // 'ISPM'    struct ISP_ISP_METADATA_T in /middleware/ISP/tuner/isp_tuner_ctrl.h
   METADATA_FACETRACKING         = ('F'<<24)+('A'<<16)+('C'<<8)+('E'),   // 'FACE'    struct FACE_METADATA_T defined in /middleware/camplus/sw/face_metadata.h
   METADATA_ANTISHAKE            = ('S'<<24)+('H'<<16)+('A'<<8)+('K'),   // 'SHAK'    struct SHAKE_METADATA_T defined in /middleware/camplus/sw/shake_metadata.h
   METADATA_RER                  = ( 0 <<24)+('R'<<16)+('E'<<8)+('R'),   // '\x00RER'    struct RER_METADATA_T defined in /middleware/camplus/sw/rer_metadata.h
   METADATA_SCENEDETECTION       = ( 0 <<24)+('A'<<16)+('S'<<8)+('D'),   // '\x00ASD'    struct ASD_METADATA_T defined in /middleware/camplus/sw/asd_metadata.h
   METADATA_TUNER_SYNC           = ('S'<<24)+('Y'<<16)+('N'<<8)+('C'),   // 'SYNC'    NULL data, just adds the item header.   
   METADATA_DARK_FRAME_CORRECT   = ('D'<<24)+('F'<<16)+('R'<<8)+('C'),   // 'DFRC'    5 byte literal string "dfrc"
   METADATA_DARK_FRAME_SUB       = ('D'<<24)+('F'<<16)+('S'<<8)+('B'),   // 'DFSB'    3 byte literal string "on"   
   METADATA_ABL                  = ( 0 <<24)+('A'<<16)+('B'<<8)+('L'),   // '\x00ABL'    struct ISP_TUNER_BRCM_BLACK_LEVEL_ABL_T defined in /middleware/ISP/tuner/isp_tuner_brcm_black_level.h

   // structure definitions for IL metadata are
   // in middleware/openmaxil/headers/ilmetadata.h
   METADATA_IL_CAMERA_NAME         = ('I'<<24)+('L'<<16)+('C'<<8)+('A'), // 'ILCA'
   METADATA_IL_CROP_RECTANGLE      = ('I'<<24)+('L'<<16)+('C'<<8)+('R'), // 'ILCR'
   METADATA_IL_PIXEL_ASPECT_RATIO  = ('I'<<24)+('L'<<16)+('P'<<8)+('A'), // 'ILPA'
   
   METADATA_TUNER_FLASH_MONITOR    = ('F'<<24)+('L'<<16)+('M'<<8)+('N'), // 'FLMN'  Flash monitor - type ISP_TUNER_BRCM_FLASH_MONITOR_T from isp_tuner_brcm.h

   METADATA_UNKNOWN        = ('U'<<24)+('N'<<16)+('K'<<8)+('N') // 'UNKN'

} METADATA_CODE_T;

#endif
