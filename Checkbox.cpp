#include "Checkbox.h"

Checkbox::Checkbox(string text, int x, int y) {
	this->position.X = x;
	this->position.Y = y;
	this->value = text;
	this->Lengh = text.length() + 1;
	this->Checked = false;
}

void Checkbox::Draw() {
	SetConsoleCursorPosition(stdoutHandle, position);
	CONSOLE_SCREEN_BUFFER_INFO consoleScreenBufferInfo;
	GetConsoleScreenBufferInfo(stdoutHandle, &consoleScreenBufferInfo);

	CONSOLE_CURSOR_INFO consoleCursorInfo = { 100, FALSE };
	SetConsoleCursorInfo(stdoutHandle, &consoleCursorInfo);

	if (this->Checked == true) {
		cout << "[X]" << this->value;
	}
	else {
		cout << "[ ]" << this->value;
	}
	
}

void Checkbox::Choose() {
	if (this->Checked == true) {
		this->Checked = false;
		this->Draw();
	}
	else {
		this->Checked = true;
		this->Draw();
	}
}

void Checkbox::SetX(int x) {
	this->position.X = x;
}

void Checkbox::SetY(int y) {
	this->position.Y = y;
}

void Checkbox::SetText(string text) {
	this->value = text;
}

bool Checkbox::IsTarget(COORD mCords) {
	if (mCords.Y == this->position.Y && mCords.X > this->position.X && mCords.X < this->position.X + this->Lengh) {
		return true;
	}
	return false;
}

COORD Checkbox::getCoords() {
	return this->position;
}

bool Checkbox::GetStatus() {
	return this->Checked;
}

void Checkbox::SetKeyboardFocus(bool f) {
	this->KeyBoardFocus = f;
}

bool Checkbox::GetKeyboardFocus() {
	return this->KeyBoardFocus;
}

Checkbox::Checkbox() {}