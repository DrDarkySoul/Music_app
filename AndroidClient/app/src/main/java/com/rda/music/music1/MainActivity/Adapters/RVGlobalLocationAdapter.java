package com.rda.music.music1.MainActivity.Adapters;

import android.content.Context;
import android.support.v7.widget.AppCompatTextView;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

import com.rda.music.music1.MainActivity.MainActivity;
import com.rda.music.music1.R;

public class RVGlobalLocationAdapter extends RecyclerView.Adapter<RVGlobalLocationAdapter.ViewHolderClass> {
    Context context;

    public RVGlobalLocationAdapter(Context context) {
        this.context = context;
    }

    public class ViewHolderClass extends RecyclerView.ViewHolder {

        AppCompatTextView itemTitle;
        ImageView itemPhoto;

        public ViewHolderClass(final View itemView) {
            super(itemView);
            itemTitle = (AppCompatTextView) itemView.findViewById(R.id.itemTitle);
            itemPhoto = (ImageView) itemView.findViewById(R.id.itemPhoto);
        }
    }

    @Override
    public ViewHolderClass onCreateViewHolder(ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_location, null);
        return new ViewHolderClass(itemView);
    }

    @Override
    public void onBindViewHolder(final ViewHolderClass holder, final int position) {
        holder.itemTitle.setText(MainActivity.locations.get(position).getTitle());
    }

    @Override
    public int getItemCount() {
        if (MainActivity.locations == null) {
            return 0;
        } else {
            return MainActivity.locations.size();
        }
    }
}
