/*
 * Copyright (C) 2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#pragma once

#include <sys/ioctl.h>

#define OPLUS_PANEL_IOCTL_BASE 'o'

#define PANEL_IOCTL_SET_SEED _IOW(OPLUS_PANEL_IOCTL_BASE, 0x03, unsigned int)
#define PANEL_IOCTL_GET_SEED _IOWR(OPLUS_PANEL_IOCTL_BASE, 0x04, unsigned int)
#define PANEL_IOCTL_SET_HBM _IOW(OPLUS_PANEL_IOCTL_BASE, 0x0F, unsigned int)
#define PANEL_IOCTL_GET_HBM _IOWR(OPLUS_PANEL_IOCTL_BASE, 0x10, unsigned int)
#define PANEL_IOCTL_SET_DIMLAYER_HBM _IOW(OPLUS_PANEL_IOCTL_BASE, 0x1F, unsigned int)
#define PANEL_IOCTL_SET_DIMLAYER_BL_EN _IOW(OPLUS_PANEL_IOCTL_BASE, 0x21, unsigned int)
#define PANEL_IOCTL_GET_DIMLAYER_BL_EN _IOWR(OPLUS_PANEL_IOCTL_BASE, 0x22, unsigned int)
#define PANEL_IOCTL_SET_FP_PRESS _IOW(OPLUS_PANEL_IOCTL_BASE, 0x29, unsigned int)
