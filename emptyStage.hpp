#pragma once

#include <BaseStage.hpp>

namespace BE
{
namespace Stage
{
    //!  The emptyStage class. 
    /*!
    The emptyStage class is a Stage.
    This only exists as a hacky fix for pausing the game audio
    */
    class emptyStage : public BE::Stage::BaseStage
    {
    public:
        emptyStage();
        ~emptyStage() = default;

        BaseStage*  cpy() final
        {
            return (new emptyStage());
        }

        void    start(std::string fileName_ = "") final;

        void    resume() final;
        void    pause() final;

        void    update(float dt_) final;
    protected:
        //
    private:
        //

    public:
        //
    protected:
        //
    private:
        //
    };
}
}
