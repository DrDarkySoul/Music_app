package com.rda.music.music1.Registration;

import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.Nullable;
import android.support.design.widget.TextInputLayout;
import android.support.v4.app.Fragment;
import android.support.v7.widget.AppCompatButton;
import android.support.v7.widget.AppCompatEditText;
import android.text.Editable;
import android.text.TextWatcher;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.EditText;

import com.rda.music.music1.GlobalFunctions.CheckEmptyFieldsTextInputLayout;
import com.rda.music.music1.MainActivity.MainActivity;
import com.rda.music.music1.R;

/**
 * Created by DENIS on 04.12.2016.
 */

public class FragmentLogin extends Fragment implements View.OnClickListener {
    View contentView;

    AppCompatEditText etLogin, etPassword;
    TextInputLayout tilLogin, tilPassword;
    AppCompatButton btnLogin, btnRegistrate;

    @Nullable
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle saveInstanceState) {
        contentView = inflater.inflate(R.layout.fragment_login, null);
        return contentView;
    }

    @Override
    public void onViewCreated(View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);

        init(view);
    }

    private void init(View view) {
        etLogin = (AppCompatEditText) view.findViewById(R.id.etLogin);
        etPassword = (AppCompatEditText) view.findViewById(R.id.etPassword);
        tilLogin = (TextInputLayout) view.findViewById(R.id.tilLogin);
        tilPassword = (TextInputLayout) view.findViewById(R.id.tilPassword);
        btnLogin = (AppCompatButton) view.findViewById(R.id.btnLogin);
        btnLogin.setOnClickListener(this);
        btnRegistrate = (AppCompatButton) view.findViewById(R.id.btnRegistrate);
        btnRegistrate.setOnClickListener(this);

        etLogin.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                tilLogin.setError(null);
                tilLogin.setErrorEnabled(false);
            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });
        etPassword.addTextChangedListener(new TextWatcher() {
            @Override
            public void beforeTextChanged(CharSequence s, int start, int count, int after) {

            }

            @Override
            public void onTextChanged(CharSequence s, int start, int before, int count) {
                tilPassword.setError(null);
                tilPassword.setErrorEnabled(false);
            }

            @Override
            public void afterTextChanged(Editable s) {

            }
        });
    }

    @Override
    public void onClick(View v) {
        switch (v.getId()) {
            case R.id.btnLogin: {
                if (checkEmpty()) {
                    SignIn();
                }
                break;
            }
            case R.id.btnRegistrate: {
                startRegistrationPage();
                break;
            }
        }
    }

    private void SignIn(){
        Intent intent = new Intent(getActivity(), MainActivity.class);
        intent.setFlags(Intent.FLAG_ACTIVITY_NEW_TASK | Intent.FLAG_ACTIVITY_CLEAR_TASK);
        startActivity(intent);
    }

    private boolean checkEmpty() {
        EditText[] editTexts = {etLogin, etPassword};
        TextInputLayout[] textInputLayouts = {tilLogin, tilPassword};
        String fill = "Fill";
        String[] errors = {fill, fill};
        return CheckEmptyFieldsTextInputLayout.getInstance().check(textInputLayouts, editTexts, errors);
    }

    private void startRegistrationPage() {
        EnterActivity registrationActivity = (EnterActivity) getActivity();
        registrationActivity.viewPager.setCurrentItem(1, true);
    }
}
