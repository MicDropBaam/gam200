#include <emptyStage.hpp>

BE::Stage::emptyStage::emptyStage()
    : BaseStage("emptyStage.stg")
{
    // Setting up the core config, by default everything is set to false
    {
        _stageLoadCoreConf.drawCore = true; // We want the draw core to keep drawing whatever was present while we display the confirm action pop up
    }
}

void
BE::Stage::emptyStage::start(std::string fileName_)
{
}

void
BE::Stage::emptyStage::resume()
{
}

void
BE::Stage::emptyStage::pause()
{
}

void
BE::Stage::emptyStage::update(float /*dt_*/)
{
}
