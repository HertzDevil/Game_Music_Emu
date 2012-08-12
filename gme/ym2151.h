/*
** File: ym2151.h - header file for software implementation of YM2151
**                                            FM Operator Type-M(OPM)
**
** (c) 1997-2002 Jarek Burczynski (s0246@poczta.onet.pl, bujar@mame.net)
** Some of the optimizing ideas by Tatsuyuki Satoh
**
** Version 2.150 final beta May, 11th 2002
**
**
** I would like to thank following people for making this project possible:
**
** Beauty Planets - for making a lot of real YM2151 samples and providing
** additional informations about the chip. Also for the time spent making
** the samples and the speed of replying to my endless requests.
**
** Shigeharu Isoda - for general help, for taking time to scan his YM2151
** Japanese Manual first of all, and answering MANY of my questions.
**
** Nao - for giving me some info about YM2151 and pointing me to Shigeharu.
** Also for creating fmemu (which I still use to test the emulator).
**
** Aaron Giles and Chris Hardy - they made some samples of one of my favourite
** arcade games so I could compare it to my emulator.
**
** Bryan McPhail and Tim (powerjaw) - for making some samples.
**
** Ishmair - for the datasheet and motivation.
*/

#pragma once

#ifndef __YM2151_H__
#define __YM2151_H__


/* 16- and 8-bit samples (signed) are supported*/
#define SAMPLE_BITS 16

/* compiler dependence */
#ifndef __OSDCOMM_H__
#define __OSDCOMM_H__
typedef unsigned char	UINT8;   /* unsigned  8bit */
typedef unsigned short	UINT16;  /* unsigned 16bit */
typedef unsigned int	UINT32;  /* unsigned 32bit */
typedef signed char		INT8;    /* signed  8bit   */
typedef signed short	INT16;   /* signed 16bit   */
typedef signed int		INT32;   /* signed 32bit   */

typedef INT32           stream_sample_t;
#endif

typedef stream_sample_t SAMP;
/*
#if (SAMPLE_BITS==16)
    typedef INT16 SAMP;
#endif
#if (SAMPLE_BITS==8)
    typedef signed char SAMP;
#endif
*/

#ifdef __cplusplus
extern "C" {
#endif

/*
** Initialize YM2151 emulator(s).
**
** 'num' is the number of virtual YM2151's to allocate
** 'clock' is the chip clock in Hz
** 'rate' is sampling rate
*/
void *ym2151_init(int clock, int rate);

/* shutdown the YM2151 emulators*/
void ym2151_shutdown(void *chip);

/* reset all chip registers for YM2151 number 'num'*/
void ym2151_reset_chip(void *chip);

/*
** Generate samples for one of the YM2151's
**
** 'num' is the number of virtual YM2151
** '**buffers' is table of pointers to the buffers: left and right
** 'length' is the number of samples that should be generated
*/
void ym2151_update_one(void *chip, SAMP **buffers, int length);

/* write 'v' to register 'r' on YM2151 chip number 'n'*/
void ym2151_write_reg(void *chip, int r, int v);

void ym2151_set_mask(void *chip, UINT32 mask);

#ifdef __cplusplus
}
#endif

#endif /*__YM2151_H__*/