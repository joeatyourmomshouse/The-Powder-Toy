#include "OptionsController.h"

#include "OptionsView.h"
#include "OptionsModel.h"

#include "Controller.h"

OptionsController::OptionsController(GameModel * gModel_, std::function<void ()> onDone_):
	gModel(gModel_),
	onDone(onDone_),
	HasExited(false)
{
	view = new OptionsView();
	model = new OptionsModel(gModel);
	model->AddObserver(view);

	view->AttachController(this);
}

void OptionsController::SetHeatSimulation(bool state)
{
	model->SetHeatSimulation(state);
}

void OptionsController::SetAmbientHeatSimulation(bool state)
{
	model->SetAmbientHeatSimulation(state);
}

void OptionsController::SetNewtonianGravity(bool state)
{
	model->SetNewtonianGravity(state);
}

void OptionsController::SetWaterEqualisation(bool state)
{
	model->SetWaterEqualisation(state);
}

void OptionsController::SetGravityMode(int gravityMode)
{
	model->SetGravityMode(gravityMode);
}

void OptionsController::SetCustomGravityX(float x)
{
	model->SetCustomGravityX(x);
}

void OptionsController::SetCustomGravityY(float y)
{
	model->SetCustomGravityY(y);
}

void OptionsController::SetAirMode(int airMode)
{
	model->SetAirMode(airMode);
}

void OptionsController::SetAmbientAirTemperature(float ambientAirTemp)
{
	model->SetAmbientAirTemperature(ambientAirTemp);
}

void OptionsController::SetVorticityCoeff(float vorticityCoeff)
{
	model->SetVorticityCoeff(vorticityCoeff);
}

void OptionsController::SetEdgeMode(int edgeMode)
{
	model->SetEdgeMode(edgeMode);
}

void OptionsController::SetTemperatureScale(TempScale temperatureScale)
{
	model->SetTemperatureScale(temperatureScale);
}

void OptionsController::SetThreadedRendering(bool newThreadedRendering)
{
	model->SetThreadedRendering(newThreadedRendering);
}

void OptionsController::SetFullscreen(bool fullscreen)
{
	model->SetFullscreen(fullscreen);
}

void OptionsController::SetChangeResolution(bool newChangeResolution)
{
	model->SetChangeResolution(newChangeResolution);
}

void OptionsController::SetForceIntegerScaling(bool forceIntegerScaling)
{
	model->SetForceIntegerScaling(forceIntegerScaling);
}

void OptionsController::SetBlurryScaling(bool newBlurryScaling)
{
	model->SetBlurryScaling(newBlurryScaling);
}

void OptionsController::SetShowAvatars(bool showAvatars)
{
	model->SetShowAvatars(showAvatars);
}

void OptionsController::SetScale(int scale)
{
	model->SetScale(scale);
}

void OptionsController::SetGraveExitsConsole(bool graveExitsConsole)
{
	model->SetGraveExitsConsole(graveExitsConsole);
}

void OptionsController::SetNativeClipoard(bool nativeClipoard)
{
	model->SetNativeClipoard(nativeClipoard);
}

void OptionsController::SetResizable(bool resizable)
{
	model->SetResizable(resizable);
}

void OptionsController::SetFastQuit(bool fastquit)
{
	model->SetFastQuit(fastquit);
}

void OptionsController::SetGlobalQuit(bool newGlobalQuit)
{
	model->SetGlobalQuit(newGlobalQuit);
}

void OptionsController::SetDecoSpace(int decoSpace)
{
	model->SetDecoSpace(decoSpace);
}

OptionsView * OptionsController::GetView()
{
	return view;
}

void OptionsController::SetMouseClickrequired(bool mouseClickRequired)
{
	model->SetMouseClickRequired(mouseClickRequired);
}

void OptionsController::SetIncludePressure(bool includePressure)
{
	model->SetIncludePressure(includePressure);
}

void OptionsController::SetPerfectCircle(bool perfectCircle)
{
	model->SetPerfectCircle(perfectCircle);
}

void OptionsController::SetMomentumScroll(bool momentumScroll)
{
	model->SetMomentumScroll(momentumScroll);
}

void OptionsController::SetRedirectStd(bool newRedirectStd)
{
	model->SetRedirectStd(newRedirectStd);
}

void OptionsController::SetAutoStartupRequest(bool newAutoStartupRequest)
{
	model->SetAutoStartupRequest(newAutoStartupRequest);
}

void OptionsController::Exit()
{
	view->CloseActiveWindow();

	if (onDone)
		onDone();
	HasExited = true;
}


OptionsController::~OptionsController()
{
	delete model;
	view->CloseActiveWindow();
	delete view;
}

