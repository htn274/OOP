#include "TRUCK.h"

TRUCK::TRUCK()
{
	m_type = 2;
	m_width = 3;
	m_height = 3;
	m_trafficLight.TRAFFIC_LIGHT::TRAFFIC_LIGHT(YTRUCK - 4);
}

TRUCK::TRUCK(int y)
{
	this->CObstacle::init(y);
	this->TRUCK::TRUCK();
}

void TRUCK::draw(char ch)
{
	if (isOutBoard() || IsHitBoard()) return;
	for (int i = 1; i < m_width; i++)
		for (int j = 0; j < m_height; j++) {
			GotoXy(m_x + i, m_y - j);
			printf("%c", ch);
		}
	GotoXy(m_x, m_y); printf("%c", ch);
	//GotoXy(m_x, m_y - 1); printf("%c", 254);
}

void TRUCK::updatePos(char direct)
{
	m_trafficLight.incTime();
	if (isStop()) return;
	if (isOutBoard()) {
		CObject::updatePos(direct);
	}
	switch (direct) {
	case LEFT: {
		for (int j = 0; j < m_height; j++) {
			GotoXy(m_x + 2, m_y - j);
			printf(" ");
		}
		Left();
		if (IsHitBoard()) {
			for (int j = 0; j < m_height; j++) {
				GotoXy(m_x + 2, m_y - j);
				printf(" ");
			}
			GotoXy(m_x + 1, m_y); printf(" ");
			m_x = BOARD_ENDX - m_width - 1;
		}
		this->draw(219);
		break;
	}
	}
}
