#include "yaFadeScript.h"
#include "yaTransform.h"
#include "yaGameObject.h"
#include "yaApplication.h"
#include "yaConstantBuffer.h"
#include "yaRenderer.h"

extern ya::Application application;

namespace ya
{
	FadeScript::FadeScript()
		: Script()
	{

	}

	FadeScript::~FadeScript()
	{

	}

	void FadeScript::Initalize()
	{

	}

	void FadeScript::Update()
	{ 
		fadein = true; //fade in을 할지 out을 할지 결정할 수 있다. 
		float time = Time::DeltaTime();
		float FadeTime = 2.0f; //Fadeinout의 시간
		if (CumulTime <= 1)
		{
			CumulTime += (float)time / FadeTime;
		}


		// Constant buffer
		ConstantBuffer* cb = renderer::constantBuffers[(UINT)eCBType::Fade];
		renderer::FadeCB data;
		if (fadein) { data.Cumultime = CumulTime; }
		else { data.Cumultime = 1.0f - CumulTime; }

		cb->Bind(&data);
		cb->SetPipline(eShaderStage::VS);
		cb->SetPipline(eShaderStage::PS);
	}

	void FadeScript::FixedUpdate()
	{
	}

	void FadeScript::Render()
	{
	}
}
