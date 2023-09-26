/*
 * Copyright (C) 2022 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "android.hardware.biometrics.fingerprint@2.3-service.porsche"

#include <android-base/logging.h>
#include <hidl/HidlTransportSupport.h>

#include "BiometricsFingerprint.h"

using android::sp;
using android::hardware::configureRpcThreadpool;
using android::hardware::joinRpcThreadpool;
using android::hardware::biometrics::fingerprint::V2_3::IBiometricsFingerprint;
using android::hardware::biometrics::fingerprint::V2_3::implementation::BiometricsFingerprint;

int main() {
    sp<IBiometricsFingerprint> bio = new BiometricsFingerprint();

    configureRpcThreadpool(1, true /*callerWillJoin*/);

    if (bio->registerAsService() != android::OK) {
        LOG(ERROR) << "Can't register BiometricsFingerprint HAL service";
        return 1;
    }

    joinRpcThreadpool();

    return 0;  // should never get here
}
