/***************************************************************************//**
*   @file   iio_ad713x.h
*   @brief  Header file of iio_axi_adc
*   @author Cristian Pop (cristian.pop@analog.com)
********************************************************************************
* Copyright 2019(c) Analog Devices, Inc.
*
* All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*  - Redistributions of source code must retain the above copyright
*    notice, this list of conditions and the following disclaimer.
*  - Redistributions in binary form must reproduce the above copyright
*    notice, this list of conditions and the following disclaimer in
*    the documentation and/or other materials provided with the
*    distribution.
*  - Neither the name of Analog Devices, Inc. nor the names of its
*    contributors may be used to endorse or promote products derived
*    from this software without specific prior written permission.
*  - The use of this software may or may not infringe the patent rights
*    of one or more patent holders.  This license does not release you
*    from the requirement that you obtain separate licenses from these
*    patent holders to use this software.
*  - Use of the software either in source or binary form, must be run
*    on or directly connected to an Analog Devices Inc. component.
*
* THIS SOFTWARE IS PROVIDED BY ANALOG DEVICES "AS IS" AND ANY EXPRESS OR
* IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, NON-INFRINGEMENT,
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
* IN NO EVENT SHALL ANALOG DEVICES BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
* LIMITED TO, INTELLECTUAL PROPERTY RIGHTS, PROCUREMENT OF SUBSTITUTE GOODS OR
* SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
* CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
* OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
* OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*******************************************************************************/
#ifndef IIO_AXI_ADC_H_
#define IIO_AXI_ADC_H_

/******************************************************************************/
/***************************** Include Files **********************************/
/******************************************************************************/

#include <stdio.h>
#include "iio_types.h"
#include "spi.h"

/******************************************************************************/
/*************************** Types Declarations *******************************/
/******************************************************************************/

/**
 * @struct iio_ad713x_init_par
 * @brief iio_ad713x configuration.
 */
struct iio_ad713x_init_par {
	/** Device name */
	char *name;
	/** Number of channels */
	uint8_t	num_channels;
	/** Spi engine message descriptor */
	struct spi_eng_msg *msg;
	/** Spi engine descriptor */
	struct spi_desc *spi_eng_desc;
	/** Invalidate the Data cache for the given address range */
	void (*dcache_invalidate_range)(uint32_t address, uint32_t bytes_count);
};

struct iio_ad713x {
	/** Number of channels */
	uint8_t	num_channels;
	/** Spi engine message descriptor */
	struct spi_eng_msg *msg;
	/** Spi engine descriptor */
	struct spi_desc *spi_eng_desc;
	/** Invalidate the Data cache for the given address range */
	void (*dcache_invalidate_range)(uint32_t address, uint32_t bytes_count);
	/** iio interface */
	struct iio_interface *iio_interface;
};

/******************************************************************************/
/************************ Functions Declarations ******************************/
/******************************************************************************/

/* Init function. */
int32_t iio_ad713x_init(struct iio_ad713x **desc,
			struct iio_ad713x_init_par *param);

/* Free the resources allocated by iio_demo_init(). */
int32_t iio_ad713x_remove(struct iio_ad713x *desc);

#endif /* IIO_AXI_ADC_H_ */
