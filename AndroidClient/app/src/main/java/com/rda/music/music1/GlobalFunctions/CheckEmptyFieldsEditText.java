package com.rda.music.music1.GlobalFunctions;

import android.widget.EditText;

/**
 * Created by DENIS on 08.07.2016.
 */
public class CheckEmptyFieldsEditText {
    private static CheckEmptyFieldsEditText instance;

    public boolean check(EditText[] editTexts, String[] errors) {
        boolean result = true;
        for (int count = 0; count < editTexts.length; count++) {
            if (editTexts[count].getText().toString().trim().equals("")) {
                editTexts[count].setError(errors[count]);
                result = false;
            }
        }
        return result;
    }

    public static synchronized CheckEmptyFieldsEditText getInstance() {
        if (instance == null) {
            instance = new CheckEmptyFieldsEditText();
        }
        return instance;
    }
}
