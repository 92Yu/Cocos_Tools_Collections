
#define __SHAKE_H__

#include "cocos2d.h"
USING_NS_CC;
class Shake : public cocos2d::CCActionInterval
{
public:
	Shake();

public:
	static Shake* create(float d, float strength);
	static Shake* createWithStrength(float d, float strength_x, float strength_y);
	bool initWithDuration(float d, float strength_x, float strength_y);

protected:
	void startWithTarget(cocos2d::CCNode* pTarget);
	void update(float time);
	void stop(void);

	CCPoint m_StartPosition;

	float m_strength_x, m_strength_y;

};
