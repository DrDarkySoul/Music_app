package com.rda.music.music1.GlobalFunctions;

import android.support.design.widget.TextInputLayout;
import android.widget.EditText;

/**
 * Created by DENIS on 02.09.2016.
 */
public class CheckEmptyFieldsTextInputLayout {
    private static CheckEmptyFieldsTextInputLayout instance;

    public boolean check(TextInputLayout[] textInputLayout, EditText[] editTexts, String[] errors) {
        boolean result = true;
        for (int count = 0; count < textInputLayout.length; count++) {
            if (editTexts[count].getText().toString().trim().equals("")) {
                textInputLayout[count].setError(errors[count]);
                result = false;
            }
        }
        return result;
    }

    public static synchronized CheckEmptyFieldsTextInputLayout getInstance() {
        if (instance == null) {
            instance = new CheckEmptyFieldsTextInputLayout();
        }
        return instance;
    }
}
