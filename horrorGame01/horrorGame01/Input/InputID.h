#pragma once
enum class InputID
{
	Up,					// �ړ��n
	Down,
	Left,
	Right,
	Action,				// �A�C�e���������h�A�A���J������
	Menu,				// ���j���[�{�^��
	Button_3,
	Button_4,
	Max,
};

InputID begin(InputID);
InputID end(InputID);
InputID operator++(InputID& key);
InputID operator* (InputID key);
