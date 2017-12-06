#include "pfactory.h"

pfactory::PFactory::PFactory(): PFactorySinglenton<PFactory> ()
{

}

pfactory::PFactory::~PFactory()
{

}
