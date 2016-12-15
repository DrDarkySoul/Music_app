package com.rda.music.music1.Registration;

import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.app.FragmentPagerAdapter;

/**
 * Created by DENIS on 04.12.2016.
 */

public class EnterViewPagerAdapter extends FragmentPagerAdapter {

    private String[] tabTitleArray = {"LOGIN", "REGISTRATION"};

    public EnterViewPagerAdapter(FragmentManager fm) {
        super(fm);
    }

    @Override
    public Fragment getItem(int position) {
        switch (position) {
            case 0:
                return new FragmentLogin();
            case 1:
                return new FragmentRegistration();
        }
        return null;
    }

    @Override
    public int getCount() {
        return 2;
    }

    @Override
    public CharSequence getPageTitle(int position) {
        return tabTitleArray[position];
    }

}
