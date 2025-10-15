/*
 * rng.c
 *
 *  Created on: Oct 13, 2025
 *      Author: 39171
 */

#include "main.h"
#include "rng.h"

// Create 32 bit pointer
uint32_t *trng_cr = (uint32_t *)TRNG_CR_ADDR;
uint32_t *trng_sr = (uint32_t *)TRNG_SR_ADDR;
uint32_t *trng_dr = (uint32_t *)TRNG_DR_ADDR;

uint32_t last_rng = 0;

uint32_t rng_run(void) {
	RNG_DBG("RNG get\n\r");
	RNG_DBG("CR = 0x%08lx\n\r", *trng_cr);
	RNG_DBG("SR = 0x%08lx\n\r", *trng_sr);
	RNG_DBG("DR = 0x%08lx\n\r", *trng_dr);

	while (*trng_dr == 0);

	RNG_DBG("Hello after while loop\n\r");

	last_rng = *trng_dr;

	return last_rng;
}

void rng_init(void) {
	RNG_DBG("\rHello from RNG init function\n\r");

	__HAL_RCC_PLL_ENABLE();
	__HAL_RCC_RNG_CLK_ENABLE();

	// Print out each register address to make sure we have the right ones
	RNG_DBG("CR = 0x%08lx SR = 0x%08lx DR = 0x%08lx\n\r", (uint32_t)trng_cr, (uint32_t)trng_sr, (uint32_t)trng_dr);

	// Print out the initial data in the registers
	RNG_DBG("RNG registers initial values\n\r");
	RNG_DBG("CR = 0x%08lx\n\r", *trng_cr);
	RNG_DBG("SR = 0x%08lx\n\r", *trng_sr);

	// Start RNG
	*trng_cr |= TRNG_CR_RNGEN | TRNG_CR_CED;

	// Print out the initial data in the registers
	RNG_DBG("RNG registers values after enabling\n\r");
	RNG_DBG("CR = 0x%08lx\n\r", *trng_cr);
	RNG_DBG("SR = 0x%08lx\n\r", *trng_sr);

	rng_run();
}

void rng_task(void) {

}
