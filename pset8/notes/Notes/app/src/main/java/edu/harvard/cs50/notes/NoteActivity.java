package edu.harvard.cs50.notes;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;

import com.google.android.material.floatingactionbutton.FloatingActionButton;

import static edu.harvard.cs50.notes.MainActivity.database;

public class NoteActivity extends AppCompatActivity {
    private EditText editText;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_note);

        Intent intent = getIntent();
        editText = findViewById(R.id.note_edit_text);
        editText.setText(intent.getStringExtra("content"));

        //added button to delete note on note
        FloatingActionButton fab2 = findViewById(R.id.delete_note_button);
        fab2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Intent intent = getIntent();
                int id = intent.getIntExtra("id", 0);
                database.noteDao().delete(id);
                finish();
            }
        });
    }

    @Override
    protected void onPause() {
        super.onPause();

        Intent intent = getIntent();
        int id = intent.getIntExtra("id", 0);
        database.noteDao().save(editText.getText().toString(), id);
    }
}
