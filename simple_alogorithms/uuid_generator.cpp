#include "uuid_generator.hpp"




QUuid generate_uuid()
{
    return QUuid::createUuid();
}
