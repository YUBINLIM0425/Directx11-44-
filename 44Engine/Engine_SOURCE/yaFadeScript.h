#pragma once
#include "yaScript.h"
#include "yaCamera.h"
#include "yaTime.h"

namespace ya
{
	class FadeScript : public Script
	{
	public:
		FadeScript();
		virtual ~FadeScript();

		virtual void Initalize();
		virtual void Update();
		virtual void FixedUpdate();
		virtual void Render();


	private:
		float CumulTime = 0.f;
		bool fadein;
	};
}
