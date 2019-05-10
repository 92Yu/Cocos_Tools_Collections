Head_ParticalEffect

void addParticalToHead(Node* node)
{
	Vec2 pos[4];
	pos[0] = Vec2(5, 75);
	pos[1] = Vec2(75, 75);
	pos[2] = Vec2(75, 5);
	pos[3] = Vec2(5, 5);

	for (int i = 0; i < 2; i++)
	{
		auto   partNode = ParticleSystemQuad::createWithTotalParticles(60);
		partNode->setTexture(TextureCache::getInstance()->addImage("GameUI/CommonUI/fire.png"));//设置粒子图
		partNode->setDuration(-1);//发射时长

		// life of particles
		partNode->setLife(0.5f);//粒子生命
		partNode->setLifeVar(0.1f);

		partNode->setEmissionRate(partNode->getTotalParticles() / partNode->getLife());//发射器发射频率
		partNode->setPositionType(ParticleSystem::PositionType::FREE);//设置发射器的跟随模式

		// color of particles
		partNode->setStartColor(ccc4f(0.76f, 0.25f, 0.12f, 1.0f));//起始颜色
		partNode->setStartColorVar(ccc4f(0.1f, 0.1f, 0.1f, 0.0f));

		partNode->setEndColor(ccc4f(1.0f, 1.0f, 1.0f, 1.0f));//结束颜色
		partNode->setEndColorVar(ccc4f(0.1f, 0.1f, 0.1f, 0.1f));

		// size, in pixels
		partNode->setStartSize(15);//粒子大小
		partNode->setStartSizeVar(3);
		partNode->setEndSize(0);
		partNode->setEndSizeVar(3);

		// angle
		partNode->setAngle(0);//发射器角度
		partNode->setAngleVar(0);

		// speed of particles
		partNode->setSpeed(0);//粒子速度
		partNode->setSpeedVar(0);

		// emitter position
		partNode->setPosVar(ccp(0, 0));//发射器位置变化

		partNode->setBlendAdditive(true);

		node->addChild(partNode);
		partNode->setTag(PARTICALTAG);
		auto move0 = MoveTo::create(1.f, pos[0]);
		auto move1 = MoveTo::create(1.f, pos[1]);
		auto move2 = MoveTo::create(1.f, pos[2]);
		auto move3 = MoveTo::create(1.f, pos[3]);

		if (i == 0)
		{
			partNode->setPosition(pos[0]);
			partNode->runAction(RepeatForever::create(Sequence::create(move1, move2, move3, move0, nullptr)));
		}
		else
		{
			partNode->setPosition(pos[2]);
			partNode->runAction(RepeatForever::create(Sequence::create(move3, move0, move1, move2, nullptr)));
		}

	}
}

void removeParticalFromHead(Node* node)
{
	node->removeChildByTag(PARTICALTAG);
	node->removeChildByTag(PARTICALTAG);
}
