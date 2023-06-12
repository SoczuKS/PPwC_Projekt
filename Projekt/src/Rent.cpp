#include "Rent.hpp"

Rent::Rent(const uint64_t rd, const uint64_t uid, const uint64_t vId, const uint64_t sd, const uint16_t th, const uint16_t td) :
	id{ rd },
	userId{ uid },
	vehicleId{ vId },
	startDate{ sd },
	timeHours{ th },
	timeDays{ td }
{
}