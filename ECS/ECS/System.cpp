#include "System.h"

/// <summary>
/// 
/// </summary>
System::System()
{

}

/// <summary>
/// 
/// </summary>
/// <param name="e"></param>
void System::addEntity(Entity * e)
{
	m_entities.push_back(e);
}

/// <summary>
/// 
/// </summary>
void System::update()
{
}
