#include "Subject.h"
#include"Observer.h"
#include"Playlist.h"
#include"Friends.h"
#include"Location_note.h"
Subject::Subject()
{
}

void Subject::notify() {
	// 5. ��������� ������������
	for (int i = 0; i < views.size(); i++) {
		views[i]->update(value);
	}
}

Subject::~Subject()
{
}