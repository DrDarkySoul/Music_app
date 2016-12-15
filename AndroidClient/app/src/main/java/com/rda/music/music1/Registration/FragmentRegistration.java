package com.rda.music.music1.Registration;

import android.app.Activity;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.design.widget.TextInputLayout;
import android.support.v4.app.Fragment;
import android.support.v4.view.ViewPager;
import android.support.v7.widget.AppCompatButton;
import android.support.v7.widget.AppCompatEditText;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;

import com.rda.music.music1.GlobalFunctions.CheckEmptyFieldsTextInputLayout;
import com.rda.music.music1.R;

/**
 * Created by DENIS on 04.12.2016.
 */

public class FragmentRegistration  extends Fragment implements View.OnClickListener, TextWatcher, View.OnFocusChangeListener {
    View contentView;

    TextInputLayout tilLoginUser, tilPasswordUser, tilPasswordRepeatUser, tilNicknameUser, tilEmailUser;
    AppCompatEditText etLoginUser, etPasswordUser, etPasswordRepeatUser, etNicknameUser, etEmailUser;
    AppCompatButton btnFinish;

    View viewInFocus;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle saveInstanceState) {
        contentView = inflater.inflate(R.layout.fragment_registration, null);
        return contentView;
    }

    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        init(view);
    }

    private void init(View view) {
        tilLoginUser = (TextInputLayout) view.findViewById(R.id.tilLoginUser);
        tilPasswordUser = (TextInputLayout) view.findViewById(R.id.tilPasswordUser);
        tilPasswordRepeatUser = (TextInputLayout) view.findViewById(R.id.tilPasswordRepeatUser);
        tilNicknameUser = (TextInputLayout) view.findViewById(R.id.tilNicknameUser);
        tilEmailUser = (TextInputLayout) view.findViewById(R.id.tilEmailUser);

        etLoginUser = (AppCompatEditText) view.findViewById(R.id.etLoginUser);
        etPasswordUser = (AppCompatEditText) view.findViewById(R.id.etPasswordUser);
        etPasswordRepeatUser = (AppCompatEditText) view.findViewById(R.id.etPasswordRepeatUser);
        etNicknameUser = (AppCompatEditText) view.findViewById(R.id.etNicknameUser);
        etEmailUser = (AppCompatEditText) view.findViewById(R.id.etEmailUser);
        btnFinish = (AppCompatButton) view.findViewById(R.id.btnFinish);
        btnFinish.setOnClickListener(this);

        etLoginUser.setOnFocusChangeListener(this);
        etPasswordUser.setOnFocusChangeListener(this);
        etPasswordRepeatUser.setOnFocusChangeListener(this);
        etNicknameUser.setOnFocusChangeListener(this);
        etEmailUser.setOnFocusChangeListener(this);

        etLoginUser.addTextChangedListener(this);
        etPasswordUser.addTextChangedListener(this);
        etPasswordRepeatUser.addTextChangedListener(this);
        etNicknameUser.addTextChangedListener(this);
        etEmailUser.addTextChangedListener(this);
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btnFinish: {
                if (checkEmpty()) {
                    if(checkPasswordsLength()) {
                        SignUp();
                    }
                }
                break;
            }
        }
    }

    private void SignUp() {

    }

    private void startLoginPage() {
        ViewPager viewPager = (ViewPager) ((Activity) getContext()).findViewById(R.id.viewpager);
        viewPager.setCurrentItem(0, true);
        clearEditTexts();
    }

    private void clearEditTexts() {
        etLoginUser.setText("");
        etPasswordUser.setText("");
        etPasswordRepeatUser.setText("");
        etNicknameUser.setText("");
        etEmailUser.setText("");
    }

    private boolean checkEmpty() {
        EditText[] editTexts = {etLoginUser, etPasswordUser, etPasswordRepeatUser, etNicknameUser, etEmailUser};
        TextInputLayout[] textInputLayouts = {tilLoginUser, tilPasswordUser, tilPasswordRepeatUser, tilNicknameUser, tilEmailUser};
        String fill = "Fill";
        String[] errors = {fill, fill, fill, fill, fill};
        return CheckEmptyFieldsTextInputLayout.getInstance().check(textInputLayouts, editTexts, errors);
    }

    private boolean checkPasswordsLength(){
        boolean result = true;
        if(String.valueOf(etPasswordUser.getText()).length() < 8){
            tilPasswordUser.setError("Short password - 8 is min");
            result = false;
        }
        if(String.valueOf(etPasswordRepeatUser.getText()).length() < 8){
            tilPasswordRepeatUser.setError("Short password - 8 is min");
            result = false;
        }
        return result;
    }

    @Override
    public void beforeTextChanged(CharSequence s, int start, int count, int after) {

    }

    @Override
    public void onTextChanged(CharSequence s, int start, int before, int count) {
        if (viewInFocus != null) {
            switch (viewInFocus.getId()) {
                case R.id.etLoginUser: {
                    tilLoginUser.setError(null);
                    tilLoginUser.setErrorEnabled(false);
                    break;
                }
                case R.id.etPasswordUser: {
                    tilPasswordUser.setError(null);
                    tilPasswordUser.setErrorEnabled(false);
                    break;
                }
                case R.id.etPasswordRepeatUser: {
                    tilPasswordRepeatUser.setError(null);
                    tilPasswordRepeatUser.setErrorEnabled(false);
                    break;
                }
                case R.id.etNicknameUser: {
                    tilNicknameUser.setError(null);
                    tilNicknameUser.setErrorEnabled(false);
                    break;
                }
                case R.id.etEmailUser: {
                    tilEmailUser.setError(null);
                    tilEmailUser.setErrorEnabled(false);
                    break;
                }
            }
        }
    }

    @Override
    public void afterTextChanged(Editable s) {

    }

    @Override
    public void onFocusChange(View v, boolean hasFocus) {
        viewInFocus = v;
    }
}
