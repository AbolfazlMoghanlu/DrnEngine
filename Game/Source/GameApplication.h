#pragma once

#include "Core/Application.h"

class GameApplication : public Drn::Application
{
protected:
	virtual void Startup() override;
	virtual void Shutdown() override;

	virtual void Tick(float DeltaTime) override;

};

