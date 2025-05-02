#include <Actor.hpp>
#include <Utilities/JsonWriter.hh>
#include <Components/Transform.hpp>

#include <imgui\imgui.h>

BE::Actor::Actor()
    : _isActive(true), _isSelected(false), _name("newActor"), _saveActor(false)
{
}

void
BE::Actor::loadComponents(Json::Value & data_)
{
    for (auto& component : _componentVec)
    {
        if (component->hashId != Component::Transform::identifier)
        {
            component->getData(data_);
        }
    }
}

void
BE::Actor::saveComponents(Json::Value& data_)
{
    BE::JsonWriter::appendValue(data_["ActorList"], _name);
    BE::JsonWriter::addValue(data_["Actors"][_name]["isActive"], _isActive);
    std::vector<std::string> componentStringArray;
    for (auto & component : _componentVec)
    {
        componentStringArray.push_back(Component::TypeStr[component->type]);
        component->writeData(data_);
    }
    JsonWriter::addStringArray(data_["Actors"][_name]["Components"], componentStringArray);
}

void
BE::Actor::drawComponentData()
{
    for (auto & component : _componentVec)
    {
        component->drawData();
    }
}
