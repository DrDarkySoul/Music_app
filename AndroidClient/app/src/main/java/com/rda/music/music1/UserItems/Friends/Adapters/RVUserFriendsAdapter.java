package com.rda.music.music1.UserItems.Friends.Adapters;

import android.content.Context;
import android.support.v7.widget.AppCompatTextView;
import android.support.v7.widget.RecyclerView;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;

import com.rda.music.music1.R;
import com.rda.music.music1.UserItems.Friends.FriendsActivity;

public class RVUserFriendsAdapter extends RecyclerView.Adapter<RVUserFriendsAdapter.ViewHolderClass> {
    Context context;

    public RVUserFriendsAdapter(Context context) {
        this.context = context;
    }

    public class ViewHolderClass extends RecyclerView.ViewHolder {

        AppCompatTextView itemNickname;
        ImageView itemPhoto;

        public ViewHolderClass(final View itemView) {
            super(itemView);
            itemNickname = (AppCompatTextView) itemView.findViewById(R.id.itemNickname);
            itemPhoto = (ImageView) itemView.findViewById(R.id.itemPhoto);
        }
    }

    @Override
    public ViewHolderClass onCreateViewHolder(ViewGroup parent, int viewType) {
        View itemView = LayoutInflater.from(parent.getContext()).inflate(R.layout.item_user, null);
        return new ViewHolderClass(itemView);
    }

    @Override
    public void onBindViewHolder(final ViewHolderClass holder, final int position) {
        holder.itemNickname.setText(FriendsActivity.friends.get(position).getNickname());
    }

    @Override
    public int getItemCount() {
        if (FriendsActivity.friends == null) {
            return 0;
        } else {
            return FriendsActivity.friends.size();
        }
    }
}
