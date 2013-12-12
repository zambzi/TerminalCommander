/*
 * ShipInterface.cpp
 *
 *  Created on: Nov 25, 2013
 *      Author: zambzi
 */

#include "ShipInterface.h"

using namespace CEGUI;

bool ShipInterface::instanceExist = false;
ShipInterface* ShipInterface::interface = NULL;

ShipInterface::ShipInterface(const Ship* playerShip) : playerShip(playerShip){
	rootWindow = WindowManager::getSingleton().createWindow("DefaultWindow", "root");
	System::getSingleton().setGUISheet(rootWindow);

	setResourceProvider();

	setResourceGroups();

	SchemeManager::getSingleton().create("TaharezLook.scheme");
	System::getSingleton().setDefaultMouseCursor("TaharezLook", "MouseArrow");
	console = WindowManager::getSingleton().loadWindowLayout("ship-gui.xml");

	outputConsole = new OutputConsole();
	bindings = new Bindings();
	inputField = new InputField(outputConsole, bindings);
	infoPanel = new InfoPanel();

	rootWindow->addChildWindow(console);
}

ShipInterface::~ShipInterface() {
	delete outputConsole;
	delete inputField;
	delete bindings;
	delete infoPanel;
	WindowManager::getSingleton().destroyAllWindows();
	instanceExist = false;
}

ShipInterface* ShipInterface::getInstance(){
	if(instanceExist){
		return interface;
	}
	else
		return NULL;
}

ShipInterface* ShipInterface::instantiate(const Ship* playerShip){
	if(!instanceExist){
		interface = new ShipInterface(playerShip);
		instanceExist = true;
		return interface;
	}
	else
		return interface;
}

void ShipInterface::setResourceProvider(){
	DefaultResourceProvider* provider = static_cast<DefaultResourceProvider*>(System::getSingleton().getResourceProvider());
	provider->setResourceGroupDirectory("schemes", "./assets/gui/schemes");
	provider->setResourceGroupDirectory("imagesets", "./assets/gui/imagesets");
	provider->setResourceGroupDirectory("fonts", "./assets/gui/fonts");
	provider->setResourceGroupDirectory("layouts", "./assets/gui-xml");
	provider->setResourceGroupDirectory("looknfeels", "./assets/gui/looknfeel");
	provider->setResourceGroupDirectory("xml_schemas", "./assets/gui/xml_schemas");
}

void ShipInterface::setResourceGroups(){
	Imageset::setDefaultResourceGroup("imagesets");
	Font::setDefaultResourceGroup("fonts");
	Scheme::setDefaultResourceGroup("schemes");
	WidgetLookManager::setDefaultResourceGroup("looknfeels");
	WindowManager::setDefaultResourceGroup("layouts");
	ScriptModule::setDefaultResourceGroup("lua_scripts");

	XMLParser* parser = System::getSingleton().getXMLParser();
	if(parser->isPropertyPresent("SchemaDefaultResourceGroup"))
		parser->setProperty("SchemaDefaultResourceGroup", "xml_schemas");
}

void ShipInterface::update(const Ship& playerShip){
	infoPanel->update(playerShip);
}

void ShipInterface::event(SDL_Event* evt){
}
