<?php
//!!!!!!!!!!!!!!!!!ВСЕ ЧТО В СКОБОЧКАХ {} НАДО ВСТАВЛЯТЬ В ЗАПРОС!!!!
#Music
/*для Admin*/ $addMusic = "INSERT music (title, artist, album, duration, photo, link) VALUE ({title}, {artist}, {album}, {duration}, {photo}, {link})";
$getMusicAction = "SELECT * FROM music WHERE id={id}";
$getMusicsAction = "SELECT * FROM music WHERE id BETWEEN {start} AND {end}";

#Location
$addLocationAction = "INSERT location (latitude, longitude, title, photo) VALUE ({latitude}, {longitude}, {title}, {photo})";
$getLocationAction = "SELECT * FROM location WHERE id={id}";

#LocationNotes
$addLocationNoteAction = "SELECT * FROM location_notes WHERE (user_id, location_id, music_id)=({user_id}, {location_id}, {music_id})";
    "INSERT location_notes (user_id, location_id, music_id) VALUE({user_id}, {location_id}, {music_id})";
$deleteLocationNoteAction="DELETE FROM location_notes WHERE (user_id, location_id, music_id)=({user_id}, {location_id}, {music_id})";
$getSmbLocationNotesAction = "SELECT * FROM location_notes WHERE user_id={user_id}";
$getSmbLocationNotesFullAction = "SELECT * FROM  location_notes INNER JOIN music ON location_notes.music_id = music.id INNER JOIN location ON location_notes.location_id=location.id WHERE user_id={user_id}";
$getLocationNotesAction="SELECT * FROM location_notes WHERE id BETWEEN {start} AND {end}";
$getLocationNotesFullAction ="SELECT * FROM  location_notes INNER JOIN music ON location_notes.music_id = music.id INNER JOIN location ON location_notes.location_id=location.id WHERE location.id BETWEEN {start} AND {end}";


#User
$registrateAction = "INSERT user (login, password, email, nickname, photo) VALUE ({login}, {password}, {email}, {nickname}, {photo})";
$loginAction = "SELECT * FROM user WHERE (login, password)=({login}, {password})";
$getUserAction = "SELECT * FROM user WHERE id={id}";

#Friends
$addFriendAction = "SELECT * FROM friends WHERE (user_id_1, user_id_2)=({user_id_1}, {user_id_2})";
    "INSERT friends (user_id_1, user_id_2) VALUE ({user_id_1}, {user_id_2})";
$deleteFriendAction = "DELETE FROM friends WHERE (user_id_1, user_id_2)=({user_id_1}, {user_id_2})";
$getSmbFriendsAction = "SELECT * FROM friends WHERE user_id_1 = {user_id_1} AND id BETWEEN {start} AND {end}";
$getSmbFriendsFullAction = "SELECT * FROM friends INNER JOIN user ON friends.user_id_2 = user.id WHERE user_id_1 = {user_id_1} AND friends.id BETWEEN {start} AND {end}";
$getUsersAction = "SELECT * FROM user WHERE id BETWEEN {start} AND {end}";

#PlayList
$addMusicToPlayListAction="SELECT * FROM playlist WHERE (user_id, music_id)=({user_id}, {music_id})";
    "INSERT playlist (user_id, music_id) VALUE ({user_id}, {music_id})";
$deleteMusicFromPlayListAction="DELETE FROM playlist WHERE (user_id, music_id)=({user_id}, {music_id})";
$getSmbPlayListAction="SELECT * FROM playlist WHERE user_id={user_id} AND id BETWEEN {start} AND {end}";
$getSmbPlayListFullAction="SELECT * FROM playlist INNER JOIN music ON playlist.music_id=music.id WHERE playlist.user_id={user_id} AND playlist.id BETWEEN {start} AND {end}";
