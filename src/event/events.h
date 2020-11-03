#ifndef EVENTS_H
#define EVENTS_H

typedef enum
{
	evButtonIrqId = 1,
	evButtonPressedId,
	evButtonReleasedId,
	tmButtonLongPressId,
	tmDebounceId
} EventIds;

#endif // EVENTS_H
