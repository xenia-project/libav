/*
 * Copyright (c) 2009 Mans Rullgard <mans@mansr.com>
 *
 * This file is part of Libav.
 *
 * Libav is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * Libav is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with Libav; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA
 */

#include "libavutil/arm/cpu.h"
#include "libavcodec/fft.h"
#include "libavcodec/rdft.h"
#include "libavcodec/synth_filter.h"

void ff_fft_calc_vfp(FFTContext *s, FFTComplex *z);

void ff_fft_permute_neon(FFTContext *s, FFTComplex *z);
void ff_fft_calc_neon(FFTContext *s, FFTComplex *z);

void ff_imdct_half_vfp(FFTContext *s, FFTSample *output, const FFTSample *input);

void ff_imdct_calc_neon(FFTContext *s, FFTSample *output, const FFTSample *input);
void ff_imdct_half_neon(FFTContext *s, FFTSample *output, const FFTSample *input);
void ff_mdct_calc_neon(FFTContext *s, FFTSample *output, const FFTSample *input);

void ff_rdft_calc_neon(struct RDFTContext *s, FFTSample *z);

av_cold void ff_fft_init_arm(FFTContext *s)
{
    int cpu_flags = av_get_cpu_flags();

#if ARCH_ARM
    if (have_vfp(cpu_flags) && !have_vfpv3(cpu_flags)) {
        s->fft_calc     = ff_fft_calc_vfp;
#if CONFIG_MDCT
        s->imdct_half   = ff_imdct_half_vfp;
#endif
    }

    if (have_neon(cpu_flags)) {
        s->fft_permute  = ff_fft_permute_neon;
        s->fft_calc     = ff_fft_calc_neon;
#if CONFIG_MDCT
        s->imdct_calc   = ff_imdct_calc_neon;
        s->imdct_half   = ff_imdct_half_neon;
        s->mdct_calc    = ff_mdct_calc_neon;
        s->mdct_permutation = FF_MDCT_PERM_INTERLEAVE;
#endif
    }
#endif
}

#if CONFIG_RDFT
av_cold void ff_rdft_init_arm(RDFTContext *s)
{
    int cpu_flags = av_get_cpu_flags();

    if (have_neon(cpu_flags))
        s->rdft_calc    = ff_rdft_calc_neon;
}
#endif
