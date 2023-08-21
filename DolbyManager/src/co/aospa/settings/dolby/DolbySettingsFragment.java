/*
 * Copyright (C) 2018,2020 The LineageOS Project
 *
 * SPDX-License-Identifier: Apache-2.0
 */

package co.aospa.settings.dolby;

import android.app.Activity;
import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.widget.Switch;

import androidx.preference.Preference;
import androidx.preference.ListPreference;
import androidx.preference.Preference.OnPreferenceChangeListener;
import androidx.preference.PreferenceCategory;
import androidx.preference.PreferenceFragment;
import androidx.preference.SwitchPreference;

import com.android.settingslib.widget.MainSwitchPreference;
import com.android.settingslib.widget.OnMainSwitchChangeListener;

public class DolbySettingsFragment extends PreferenceFragment implements
        OnPreferenceChangeListener, OnMainSwitchChangeListener {

    public static final String PREF_ENABLE = "dolby_enable";
    public static final String PREF_PRESET = "dolby_preset";
    public static final String PREF_PROFILE = "dolby_profile";

    private MainSwitchPreference mSwitchBar;
    private ListPreference mPresetPref;
    private ListPreference mProfilePref;

    private DolbyUtils mDolbyUtils;

    @Override
    public void onCreatePreferences(Bundle savedInstanceState, String rootKey) {
        addPreferencesFromResource(R.xml.dolby_settings);

        mDolbyUtils = DolbyUtils.getInstance(getActivity());
        final boolean dsOn = mDolbyUtils.getDsOn();

        mSwitchBar = (MainSwitchPreference) findPreference(PREF_ENABLE);
        mSwitchBar.addOnSwitchChangeListener(this);
        mSwitchBar.setChecked(dsOn);

        mPresetPref = (ListPreference) findPreference(PREF_PRESET);
        mPresetPref.setOnPreferenceChangeListener(this);
        mPresetPref.setEnabled(dsOn);

        mProfilePref = (ListPreference) findPreference(PREF_PROFILE);
        mProfilePref.setOnPreferenceChangeListener(this);
        mProfilePref.setEnabled(dsOn);
        mProfilePref.setValue(Integer.toString(mDolbyUtils.getProfile()));
    }

    @Override
    public boolean onPreferenceChange(Preference preference, Object newValue) {
        switch (preference.getKey()) {
            case PREF_PRESET:
                mDolbyUtils.setPreset(newValue.toString());
                return true;
            case PREF_PROFILE:
                mDolbyUtils.setProfile(Integer.parseInt((newValue.toString())));
                return true;
            default:
                return false;
        }
    }

    @Override
    public void onSwitchChanged(Switch switchView, boolean isChecked) {
        mSwitchBar.setChecked(isChecked);

        mDolbyUtils.setDsOn(isChecked);
        mPresetPref.setEnabled(isChecked);
        mProfilePref.setEnabled(isChecked);
    }
}
