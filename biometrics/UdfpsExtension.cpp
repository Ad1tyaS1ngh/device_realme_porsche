/*
 * Copyright (C) 2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#include <compositionengine/UdfpsExtension.h>
#include <display/drm/sde_drm.h>

uint32_t getUdfpsZOrder(uint32_t z, bool touched) {
#ifdef FOD_PRESSED_LAYER_ZORDER
    return touched ? z | FOD_PRESSED_LAYER_ZORDER : z;
#else
    return touched ? 0x41000033 : z;
#endif
}

uint64_t getUdfpsUsageBits(uint64_t usageBits, bool /*touched*/) {
    return usageBits;
}
