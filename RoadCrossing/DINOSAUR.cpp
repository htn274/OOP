#include "DINOSAUR.h"

DINOSAUR::DINOSAUR()
{
	m_type = 3;
	m_width = 3;
	m_height = 3;
}

DINOSAUR::DINOSAUR(int y)
{
	this->DINOSAUR::DINOSAUR();
	this->init(y);
	m_type = 3;
}

void DINOSAUR::draw(char ch)
{
	if (IsHitBoard() || isOutBoard()) return;
	GotoXy(m_x, m_y - 2); printf("%c", ch);
	for (int i = 0; i < m_height - 1; i++) {
		GotoXy(m_x + 1, m_y - i);
		printf("%c", ch);
	}
	GotoXy(m_x + 2, m_y); printf("%c", ch);
}

void DINOSAUR::updatePos(char direct)
{
	if (isOutBoard()) {
		this->CObject::updatePos(direct);
		return;
	}
	switch (direct) {
	case LEFT: {
		GotoXy(m_x + 2, m_y); printf(" ");
		for (int i = 1; i < m_height; i++) {
			GotoXy(m_x + 1, m_y - i);
			printf(" ");
		}
		Left();
		if (IsHitBoard()) {
			draw(' ');
			GotoXy(m_x + 1, m_y - 2); printf(" ");
			GotoXy(m_x + 2, m_y); printf(" ");
			m_x = BOARD_ENDX - m_width - 1;
		}
		draw(219);
		break;
	}
	}
}
