/*
 * rng.h
 *
 *  Created on: Oct 13, 2025
 *      Author: 39171
 */

#ifndef RNG_H_
#define RNG_H_

#ifdef DEBUG

#include <stdio.h>
#define RNG_DBG(...) printf(__VA_ARGS__);

#endif

#define TRNG_ADDR 0x50060800
#define TRNG_CR_ADDR TRNG_ADDR
#define TRNG_SR_ADDR TRNG_ADDR + 1 // In this case adding 1 is the same as off setting by 0x04 because we are dealing with a pointer
#define TRNG_DR_ADDR TRNG_ADDR + 2 // Same as offsetting by 0x08

#define TRNG_CR_RNGEN (1 << 2)
#define TRNG_CR_IE    (1 << 3)
#define TRNG_CR_CED   (1 << 5)

#define TRNG_SR_DRDY  (1 << 0)
#define TRNG_SR_CECS  (1 << 1)
#define TRNG_SR_SECS  (1 << 2)
#define TRNG_SR_CEIS  (1 << 5)
#define TRNG_SR_SEIS  (1 << 6)

void rng_init(void);
void rng_task(void);

#endif /* RNG_H_ */
