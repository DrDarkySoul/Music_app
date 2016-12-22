<?php
#Music
$addMusic = "INSERT music (title, artist, album, duration, photo, link) VALUE (title, artist, album, duration, photo, link)";
$getMusic = "SELECT * FROM music WHERE id=id";

#Location
$addLocation = "INSERT location (latitude, longitude, title, photo) VALUE (latitude, longitude, title, photo)";
$getLocation = "SELECT * FROM location WHERE id=id";

#LocationNotes
$addLocationNote = "SELECT * FROM location_notes WHERE (user_id, location_id, music_id)=(2,2,1)";
    "INSERT location_notes (user_id, location_id, music_id) VALUE(user_id, location_id, music_id)";
$deleteLocationNote="DELETE FROM location_notes WHERE (user_id, location_id, music_id)=(user_id, location_id, music_id)";
$getSmbLocationNotes = "SELECT * FROM location_notes WHERE user_id=user_id";
$getSmbLocationNotesFull = "SELECT * FROM  location_notes INNER JOIN music ON location_notes.music_id = music.id INNER JOIN location ON location_notes.location_id=location.id WHERE user_id=3";
$getLocations="SELECT * FROM location_notes WHERE id BETWEEN start AND end";
$getLocationsFull ="SELECT * FROM  location_notes INNER JOIN music ON location_notes.music_id = music.id INNER JOIN location ON location_notes.location_id=location.id WHERE location.id BETWEEN start AND end";


#User
$registrate = "INSERT user (login, password, email, nickname, photo) VALUE (login, password, email, nickname, photo)";
$login = "SELECT * FROM user WHERE (login, password)=(login, password)";
$getUser = "SELECT * FROM user WHERE id=id";

#Friends
$addFriend = "SELECT * FROM friends WHERE (user_id_1, user_id_2)=(user_id_1, user_id_2)";
    "INSERT friends (user_id_1, user_id_2) VALUE (user_id_1, user_id_2)";
$deleteFriend = "DELETE FROM friends WHERE (user_id_1, user_id_2)=(user_id_1, user_id_2)";
$getSmbFriends = "SELECT * FROM friends WHERE user_id_1 = user_id AND id BETWEEN start AND end";
$getUsers = "SELECT * FROM user WHERE id BETWEEN start AND end";

#PlayList
$addMusicToPlayList="SELECT * FROM playlist WHERE (user_id, music_id)=(user_id, music_id)";
    "INSERT playlist (user_id, music_id) VALUE (user_id, music_id)";
$deleteMusicFromPlayList="DELETE FROM playlist WHERE music_id=music_id";
$getMusicFromPlayList="SELECT * FROM playlist WHERE music_id=music_id";
$getSmbPlayList="SELECT * FROM playlist WHERE user_id=1 AND id BETWEEN start AND end";
$getSmbPlayListFull="SELECT * FROM playlist INNER JOIN music ON playlist.music_id=music.id WHERE playlist.id BETWEEN start AND end";
