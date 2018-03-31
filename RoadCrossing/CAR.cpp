#include "CAR.h"

CAR::CAR()
{
	m_type = 1;
	m_width = 3;
	m_height = 2;
	m_trafficLight.TRAFFIC_LIGHT::TRAFFIC_LIGHT(YCAR - 4);
}

CAR::CAR(int y)
{
	this->init(y);
	this->CAR::CAR();
}

void CAR::draw(char ch)
{
	if (IsHitBoard() || isOutBoard()) return;

	for (int i = 0; i < m_width; i++) {
		GotoXy(m_x + i, m_y);
		printf("%c", ch);
	}

	GotoXy(m_x + 1, m_y - 1);
	printf("%c", ch);
}

void CAR::updatePos(char direct)
{
	m_trafficLight.incTime();
	if (isStop()) return;
	if (isOutBoard()) {
		CObject::updatePos(direct);
	}
	switch (direct){
	case LEFT: {
		GotoXy(m_x + 1, m_y - 1); printf(" ");
		GotoXy(m_x + 2, m_y); printf(" ");
		Left();
		if (IsHitBoard()) {
			GotoXy(m_x + 1, m_y); printf(" ");
			GotoXy(m_x + 2, m_y); printf(" ");
			m_x = BOARD_ENDX - m_width - 1;
		}
		draw(219);
		break;
	}
	case RIGHT: {
		GotoXy(m_x, m_y); printf(" ");
		GotoXy(m_x + 1, m_y - 1); printf(" ");
		Right();
		if (IsHitBoard()) {
			GotoXy(m_x, m_y); printf(" ");
			GotoXy(m_x + 1, m_y);  printf(" ");
			m_x = BOARD_STARTX + 1;
		}
		//GotoXy(m_x + 1, m_y - 1); printf("%c", 219);
		//GotoXy(m_x + 2, m_y); printf("%c", 219);
		draw(219);
	}
	}
}
