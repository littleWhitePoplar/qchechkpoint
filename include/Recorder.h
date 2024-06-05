#pragma once
#include"Common.h"
namespace qcheckpoint {
    class Recorder {
        public:
        virtual void record()=0;
    };
}